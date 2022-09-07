#include<fstream>
#include <QtWidgets/QFileDialog>

#include "vnpmainwindow.h"
#include "vnptreewidget.h"
#include "qtdataview.h"
#include "Iir.h"
#include "manual.h" 

ManualPeakFind::ManualPeakFind(QWidget* p):QMdiSubWindow(p) {
	widget = new QWidget();
	ui.setupUi(widget);
	this->setWidget(widget);
	this->setAttribute(Qt::WA_DeleteOnClose);

	DataView* firstview = this->findChild<DataView*>("graphicsView");
	connect(this, SIGNAL(sendxscale(double, double)), firstview, SLOT(setxscale(double, double)));
	connect(this, SIGNAL(sendyscale(double, double)), firstview, SLOT(setyscale(double, double)));
	connect(this, SIGNAL(senddata(QVector<QPointF>)), firstview, SLOT(update_data(QVector<QPointF>)));
	connect(this, SIGNAL(senddatadone(QVector<double>)), firstview, SLOT(update_done(QVector<double>)));
	connect(firstview, SIGNAL(request_data(double, double, double, double)), this, SLOT(senddata(double, double, double, double)));
	connect(this, SIGNAL(sendeventlist(QVector<QPointF>)), firstview, SLOT(update_event(QVector<QPointF>)));
	connect(this, SIGNAL(sendeventlist_temp(QVector<QPointF>)), firstview, SLOT(update_event_temp(QVector<QPointF>)));

	QPushButton* button_8 = this->findChild<QPushButton*>("pushButton_8");
	connect(button_8, SIGNAL(clicked()), this, SLOT(insertevent()));

	QPushButton* button_19 = this->findChild<QPushButton*>("pushButton_19");
	connect(button_19, SIGNAL(clicked()), this, SLOT(removeevent()));

	QPushButton* button_17 = this->findChild<QPushButton*>("pushButton_17");
	connect(button_17, SIGNAL(clicked()), this, SLOT(saveeventlist()));

	QPushButton* button_23 = this->findChild<QPushButton*>("pushButton_23");
	connect(button_23, SIGNAL(clicked(bool)), this, SLOT(addeventlist_temp(bool)));

	QPushButton* button_12 = this->findChild<QPushButton*>("pushButton_12");
	connect(button_12, SIGNAL(clicked()), this, SLOT(backward()));

	QPushButton* button = this->findChild<QPushButton*>("pushButton");
	connect(button, SIGNAL(clicked()), this, SLOT(forward()));

	QPushButton* button_11 = this->findChild<QPushButton*>("pushButton_11");
	connect(button_11, SIGNAL(clicked()), this, SLOT(home()));

	QPushButton* button_13 = this->findChild<QPushButton*>("pushButton_13");
	connect(button_13, SIGNAL(clicked()), this, SLOT(backwardwindow()));

	QPushButton* button_10 = this->findChild<QPushButton*>("pushButton_10");
	connect(button_10, SIGNAL(clicked()), this, SLOT(forwardwindow()));
}

ManualPeakFind::~ManualPeakFind() {
	dat.close();
	emit offline(QString::fromStdString(currentgroup));
}

void ManualPeakFind::opendat(QString fn, VNPIO& vf) {
	vnpfile = &vf;
	currentgroup = fn.toStdString();
	filename = vnpfile->getdatapath(fn.toStdString());
	datadone = vnpfile->getdatadone(fn.toStdString());
	eventlist = vnpfile->geteventlist(fn.toStdString());
	dat.open(filename);
	n = dat.size();
	home();
	return;
}

void ManualPeakFind::filter(std::unordered_map<std::string, double>& mymap, bool check) {
	if (!check) {
		dat.open(filename);
		home();
	}
	else {
		float samplingrate = mymap["fs"];
		float cutoff = mymap["cutoff"];
		Iir::Butterworth::LowPass<5> f;
		f.setup(samplingrate, cutoff);
		float* data = new float[n];
		for (int i = 0; i < n; i++) {
			data[i] = f.filter(dat.at(i));
		}
		f.setup(samplingrate, cutoff);
		std::ofstream wf;
		wf.open("temporary.dat", std::ios::out | std::ios::binary);
		wf.write(reinterpret_cast<const char*>(data), n * sizeof(float));
		wf.close();
		delete[] data;
		dat.open("temporary.dat");
		home();
	}
}

void ManualPeakFind::findpeak(std::unordered_map<std::string, double>& mymap) {
	std::vector<double> timex;
	for (auto it : datadone) {
		timex.push_back(it.first * 1000 / mymap["interval"]);
		timex.push_back(it.second * 1000 / mymap["interval"]);
	}
	std::vector<float> dats = dat.data(0, n, 1);
	//if(datadone.empty())
		eventlist = findPeak(dats, mymap, 0, n);
	//else {
		//eventlist.clear();
		//DataView* firstview = this->findChild<DataView*>("graphicsView");
		//std::list<std::pair<double, double>>::iterator it=datadone.begin();
		//int i = 0;
		//while (it != datadone.end()) {
		//	eventlist.splice(eventlist.end(), findPeak_manual(dats, mymap, it->first, it->second, firstview->linestack[i]->at(0).y()));
		//	++it;
		//}
	//}
	sendeventlist();
}

void ManualPeakFind::senddata(double xmin, double xmax, double ymin, double ymax) {	
	int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	int skip = (e - s) / 1500;
	int j;
	QVector<QPointF> point;
	clock_t t1 = clock();
	if (skip <= 1) {
		for (int i = s; i < e; i += 1) {
			point.append(QPointF((double)i * interval / 1000, dat.at(i)));
		}
	}
	else {
		for (int i = s; i < e; i += skip) {
			j = (i + skip <= e) ? i + skip : e;
			std::pair<float, float> x = dat.valminmax(i, j);
			point.append(QPointF(i * interval / 1000, x.first));
			point.append(QPointF(i * interval / 1000, x.second));
		}
	}
	clock_t t2 = clock();
	emit senddata(point);
	emit sendxscale(xmin, xmax);
	emit sendyscale(ymin, ymax);
	history.push_back({ xmin, xmax, ymin, ymax });
	pos = std::next(history.end(), -1);
	return;
}


void ManualPeakFind::home() {
	double xmin = 0;
	double xmax = dat.size() * interval / 1000;
	std::pair<double, double> y = dat.valminmax();
	double ymax = std::max(y.first, y.second);
	double ymin = std::min(y.first, y.second);
	emit sendxscale(xmin, xmax);
	emit sendyscale(ymin - 0.1 * (ymax - ymin), ymax + 0.1 * (ymax - ymin));
	history.clear();
	senddata(xmin, xmax, ymin, ymax);
	sendeventlist();
	return;
}


void ManualPeakFind::insertevent() {
	for (auto i : eventlist_temp) {
		std::list<Peak>::iterator poss;
		std::list<Peak>::iterator pose;
		double xmin = i.start;
		double xmax = i.end;
		double eventcurrent = i.currentpeak;
		double baseline = i.baseline;
		Peak point = { xmin, xmax, eventcurrent, baseline };
		poss = findposs(point.start);
		pose = findpose(point.end);
		eventlist.erase(poss, pose);
		eventlist.insert(pose, point);
	}
	sendeventlist();
	return;
}

void ManualPeakFind::removeevent() {
	std::list<Peak>::iterator poss;
	std::list<Peak>::iterator pose;
	double xmin = parent()->findChild<QLabel*>("label_18")->text().toDouble();
	double xmax = parent()->findChild<QLabel*>("label_19")->text().toDouble();
	poss = findposs(xmin);
	pose = findpose(xmax);
	eventlist.erase(poss, pose);
	sendeventlist();
	return;
}

std::list<Peak>::iterator ManualPeakFind::findposs(double start) {
	std::list<Peak>::iterator it;
	it = eventlist.begin();
	while (it != eventlist.end()) {
		if (start <= it->end && start >= it->start) {
			return it;
		}
		else if (start > it->end) {
			++it;
		}
		else {
			return it;
		}
	}
	return it;
}

std::list<Peak>::iterator ManualPeakFind::findpose(double end) {
	std::list<Peak>::iterator it;
	it = eventlist.begin();
	while (it != eventlist.end()) {
		if (end <= it->end && end >= it->start) {
			return std::next(it, 1);
		}
		else if (end > it->end) {
			++it;
		}
		else {
			return it;
		}
	}
	return it;
}

void ManualPeakFind::sendeventlist() {
	QVector<QPointF> point;
	for (auto it:eventlist) {
		point.append(QPointF(it.start, it.baseline));
		point.append(QPointF(it.start, it.currentpeak));
		point.append(QPointF(it.end, it.currentpeak));
		point.append(QPointF(it.end, it.baseline));
	}
	emit sendeventlist(point);
}

void ManualPeakFind::forwardwindow() {
	double skip = parent()->findChild<QLineEdit*>("lineEdit_2")->text().toDouble() ;
	double xmax = parent()->findChild<DataView*>("graphicsView")->axisx->max();
	double ymin = parent()->findChild<DataView*>("graphicsView")->axisy->min();
	double ymax = parent()->findChild<DataView*>("graphicsView")->axisy->max();
	senddata(xmax, xmax + skip, ymin, ymax);
}

void ManualPeakFind::backwardwindow() {
	double skip = parent()->findChild<QLineEdit*>("lineEdit_2")->text().toDouble();
	double xmin = parent()->findChild<DataView*>("graphicsView")->axisx->min();
	double ymin = parent()->findChild<DataView*>("graphicsView")->axisy->min();
	double ymax = parent()->findChild<DataView*>("graphicsView")->axisy->max();
	senddata(xmin-skip, xmin, ymin, ymax);
}

void ManualPeakFind::saveeventlist() {
	vnpfile->seteventlist(currentgroup.c_str(), eventlist);
}

void ManualPeakFind::savedatadone() {
	vnpfile->setdatadone(currentgroup.c_str(), datadone);
}

void ManualPeakFind::backward() {
	if (pos != history.begin()) {
		pos = std::next(pos, -1);
		double xmin = pos->start;
		double xmax = pos->end;
		double ymin = pos->currentpeak;
		double ymax = pos->baseline;
		int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
		int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
		int skip = (e - s) / 1500;
		int j;
		QVector<QPointF> point;
		if (skip <= 1) {
			for (int i = s; i < e; i += 1) {
				point.append(QPointF((double)i * interval / 1000, dat.at(i)));
			}
		}
		else {
			for (int i = s; i < e; i += skip) {
				j = (i + skip <= e) ? i + skip : e;
				std::pair<float, float> x = dat.valminmax(i, j);
				point.append(QPointF(i * interval / 1000, x.first));
				point.append(QPointF(i * interval / 1000, x.second));
			}
		}
		emit senddata(point);
		emit sendxscale(xmin, xmax);
		emit sendyscale(ymin, ymax);
	}
}

void ManualPeakFind::forward() {
	if (std::next(pos, 1) != history.end()) {
		pos = std::next(pos, 1);
		double xmin = pos->start;
		double xmax = pos->end;
		double ymin = pos->currentpeak;
		double ymax = pos->baseline;
		int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
		int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
		int skip = (e - s) / 1500;
		int j;
		QVector<QPointF> point;
		if (skip <= 1) {
			for (int i = s; i < e; i += 1) {
				point.append(QPointF((double)i * interval / 1000, dat.at(i)));
			}
		}
		else {
			for (int i = s; i < e; i += skip) {
				j = (i + skip <= e) ? i + skip : e;
				std::pair<float, float> x = dat.valminmax(i, j);
				point.append(QPointF(i * interval / 1000, x.first));
				point.append(QPointF(i * interval / 1000, x.second));
			}
		}
		emit senddata(point);
		emit sendxscale(xmin, xmax);
		emit sendyscale(ymin, ymax);
	}
}

void ManualPeakFind::addeventlist_temp(bool draw) {
	if (draw) {
		QPushButton* stats = this->findChild<QPushButton*>("pushButton_22");
		if (stats->isChecked()) {
			double xmin = parent()->findChild<QLabel*>("label_18")->text().toDouble();
			double xmax = parent()->findChild<QLabel*>("label_19")->text().toDouble();
			double eventcurrent = parent()->findChild<QLabel*>("label_15")->text().toDouble();
			double baseline = parent()->findChild<QLabel*>("label_16")->text().toDouble();
			Peak point = { xmin, xmax, eventcurrent, baseline };
			eventlist_temp.clear();
			eventlist_temp.push_back(point);

		}
		else {
			VNPMainWindow* mainwindow = NULL;
			QObject* wid = NULL;
			wid = this->parent();
			while (qobject_cast<VNPMainWindow*>(wid) == NULL)
				wid = wid->parent();
			mainwindow = qobject_cast<VNPMainWindow*>(wid);
			std::unordered_map<std::string, double> mymap = mainwindow->mymap;
			double interval = mymap["interval"];
			double s = parent()->findChild<DataView*>("graphicsView")->axisx->min();
			double e = parent()->findChild<DataView*>("graphicsView")->axisx->max();
			std::vector<float> dats = dat.data(0, n, 1);
			//if(datadone.empty())
			double eventcurrent = parent()->findChild<QLabel*>("label_15")->text().toDouble();
			double baseline = parent()->findChild<QLabel*>("label_16")->text().toDouble();
			eventlist_temp = findPeak_manual(dats, mymap, s, e, baseline, abs(eventcurrent - baseline));
		}
	}
	else {
		eventlist_temp.clear();
	}
	QVector<QPointF> p;
	for (auto it : eventlist_temp) {
		p.append(QPointF(it.start, it.baseline));
		p.append(QPointF(it.start, it.currentpeak));
		p.append(QPointF(it.end, it.currentpeak));
		p.append(QPointF(it.end, it.baseline));
	}
	emit sendeventlist_temp(p);
}