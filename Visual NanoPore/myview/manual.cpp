#include<fstream>
#include "vnpmainwindow.h"
#include "manual.h" 
#include "vnptreewidget.h"
#include "qtdataview.h"
#include "Iir.h"

ManualPeakFind::ManualPeakFind(QWidget* p):QMdiSubWindow(p) {
	widget = new QWidget();
	ui.setupUi(widget);
	this->setWidget(widget);
	this->setAttribute(Qt::WA_DeleteOnClose);

	FirstDataView* firstview = this->findChild<FirstDataView*>("graphicsView");
	connect(this, SIGNAL(sendxscale1(double, double)), firstview, SLOT(setxscale(double, double)));
	connect(this, SIGNAL(sendyscale(double, double)), firstview, SLOT(setyscale(double, double)));
	connect(this, SIGNAL(senddata1(QVector<QPointF>)), firstview, SLOT(update_data(QVector<QPointF>)));
	connect(this, SIGNAL(senddatadone(QVector<QPointF>)), firstview, SLOT(update_mask(QVector<QPointF>)));
	connect(firstview, SIGNAL(request_data(double, double, bool)), this, SLOT(getdata(double, double, bool)));

	SecondDataView* secondview = this->findChild<SecondDataView*>("graphicsView_2");
	connect(this, SIGNAL(sendxscale2(double, double)), secondview, SLOT(setxscale(double, double)));
	connect(this, SIGNAL(senddata2(QVector<QPointF>)), secondview, SLOT(update_data(QVector<QPointF>)));
	connect(this, SIGNAL(sendeventlist(QVector<QPointF>)), secondview, SLOT(update_event(QVector<QPointF>)));
	connect(firstview->axisy, SIGNAL(minChanged(qreal)), secondview, SLOT(setMin(qreal)));
	connect(firstview->axisy, SIGNAL(maxChanged(qreal)), secondview, SLOT(setMax(qreal)));
	connect(secondview->axisx, SIGNAL(rangeChanged(qreal, qreal)), firstview, SLOT(setselectarea(qreal, qreal)));

	QPushButton* button_8 = this->findChild<QPushButton*>("pushButton_8");
	connect(button_8, SIGNAL(clicked()), this, SLOT(insertevent()));

	QPushButton* button_19 = this->findChild<QPushButton*>("pushButton_19");
	connect(button_19, SIGNAL(clicked()), this, SLOT(removeevent()));

	QPushButton* button_17 = this->findChild<QPushButton*>("pushButton_17");
	connect(button_17, SIGNAL(clicked()), this, SLOT(saveeventlist()));

	QPushButton* button_22 = this->findChild<QPushButton*>("pushButton_22");
	connect(button_22, SIGNAL(clicked()), this, SLOT(insertregion()));

	QPushButton* button_23 = this->findChild<QPushButton*>("pushButton_23");
	connect(button_23, SIGNAL(clicked()), this, SLOT(removeregion()));

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

	QPushButton* button_16 = this->findChild<QPushButton*>("pushButton_16");
	connect(button_16, SIGNAL(toggled(bool)), this, SLOT(filter(bool)));
}

ManualPeakFind::~ManualPeakFind() {
	dat.close();
}

void ManualPeakFind::opendat(QString fn, double fs) {
	filename = fn.toStdString();
	dat.open(filename);
	interval = fs;
	n = dat.size();
	home();
	return;
}

void ManualPeakFind::filter(bool check) {
	if (!check) {
		dat.open(filename);
		home();
	}
	else {
		VNPMainWindow* mainwindow = qobject_cast<VNPMainWindow*>(this->parent()->parent()->parent()->parent());
		std::unordered_map<std::string, double> mymap = mainwindow->mymap;
		if (mymap.empty()) {
			QMessageBox msgBox;
			msgBox.setText("Please set config file");
			msgBox.exec();
			return;
		}
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

void ManualPeakFind::getdata(double xmin, double xmax, bool mainview) {
	if (mainview) 
		history.push_back(std::pair<double, double>(xmin, xmax));
	
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
	if (mainview) {
		emit sendxscale1(xmin, xmax);
		emit senddata1(point);
	}
		
	else {
		emit sendxscale2(xmin, xmax);
		emit senddata2(point);
		geteventlist();
	}
	return;
}

void ManualPeakFind::getdatadone() {
	std::list<std::pair<double, double>>::iterator it;
	QVector<QPointF> point;
	for (it = datadone.begin(); it != datadone.end(); ++it) {
		point.push_back(QPointF(it->first, it->second));
	}
	emit senddatadone(point);
}

void ManualPeakFind::meansd(double xmin, double xmax) {
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	std::pair<float, float> y = dat.meansd();
	emit sendmean(y.first);
	emit sendsd(y.second);
	return;
}

void ManualPeakFind::backward() {
	if (std::next(pos, 1) != history.end()) {
		pos = std::next(pos, 1);
		double xmin = pos->first;
		double xmax = pos->second;
		emit sendxscale1(xmin, xmax);

		unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
		unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
		unsigned int skip = (e - s) / 1500;
		unsigned int j;
		QVector<QPointF> point;
		if (skip <= 1) {
			for (unsigned int i = s; i < e; i += 1) {
				point.append(QPointF((double)i * interval / 1000, dat.at(i)));
			}
		}
		else {
			for (unsigned int i = s; i < e; i += skip) {
				j = (i + skip <= e) ? i + skip : e;
				std::pair<float, float> x = dat.valminmax(i, j);
				point.append(QPointF(i * interval / 1000, x.first));
				point.append(QPointF(i * interval / 1000, x.second));
			}
		}
		emit senddata1(point);
	}
}

void ManualPeakFind::forward() {
	if (pos != history.begin()) {
		pos = std::prev(pos, 1);
		double xmin = pos->first;
		double xmax = pos->second;
		emit sendxscale1(xmin, xmax);

		unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
		unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
		unsigned int skip = (e - s) / 1500;
		unsigned int j;
		QVector<QPointF> point;
		if (skip <= 1) {
			for (unsigned int i = s; i < e; i += 1) {
				point.append(QPointF((double)i * interval / 1000, dat.at(i)));
			}
		}
		else {
			for (unsigned int i = s; i < e; i += skip) {
				j = (i + skip <= e) ? i + skip : e;
				std::pair<float, float> x = dat.valminmax(i, j);
				point.append(QPointF(i * interval / 1000, x.first));
				point.append(QPointF(i * interval / 1000, x.second));
			}
		}
		emit senddata1(point);
	}
}

void ManualPeakFind::home() {
	double xmin = 0;
	double xmax = dat.size() * interval / 1000;
	std::pair<double, double> y = dat.valminmax();
	double ymax = std::max(y.first, y.second);
	double ymin = std::min(y.first, y.second);
	emit sendxscale1(xmin, xmax);
	emit sendyscale(ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin));
	history.clear();
	getdata(xmin, xmax, true);
	pos = history.begin();
	return;
}

void ManualPeakFind::insertregion() {
	double s = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->min();
	double e = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->max();
	std::list<std::pair<double, double>>::iterator it;
	std::list<std::pair<double, double>>::iterator poss;
	std::list<std::pair<double, double>>::iterator pose;
	it = datadone.begin();
	poss = datadone.end();
	pose = datadone.end();
	while (it != datadone.end()) {
		if (s <= it->second && s >= it->first) {
			s = it->first;
			poss = it;
			break;
		}
		else if (s > it->second)
			++it;
		else {
			poss = it;
			break;
		}	
	}
	while (it != datadone.end()) {
		if (e <= it->second && e >= it->first) {
			e = it->second;
			pose = std::next(it, 1);
			break;
		}
		else if (e > it->second)
			++it;
		else {
			pose = it;
			break;
		}
	}

	if (poss != datadone.end()) {
		datadone.erase(poss, pose);
	}
	datadone.insert(pose, std::pair<double, double>(s, e));
	getdatadone();
}

void ManualPeakFind::removeregion() {
	double s = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->min();
	double e = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->max();
	int s0, e0 = -1;
	std::list<std::pair<double, double>>::iterator it;
	std::list<std::pair<double, double>>::iterator poss;
	std::list<std::pair<double, double>>::iterator pose;
	it = datadone.begin();
	poss = datadone.end();
	pose = datadone.end();
	while (it != datadone.end()) {
		if (s <= it->second && s >= it->first) {
			poss = it;
			s0 = it->first;
			break;
		}
		else if (s > it->second)
			++it;
		else {
			poss = it;
			break;
		}
	}
	while (it != datadone.end()) {
		if (e <= it->second && e >= it->first) {
			e0 = it->second;
			pose = std::next(it, 1);
			break;
		}
		else if (e > it->second)
			++it;
		else {
			pose = it;
			break;
		}
	}

	if (poss != datadone.end()) {
		datadone.erase(poss, pose);
	}
	if (e0 >= 0) 
		datadone.insert(pose, std::pair<double, double>(e, e0));
	if (s0 >= 0) 
		datadone.insert(pose, std::pair<double, double>(s0, s));
	getdatadone();
	return;
}

void ManualPeakFind::insertevent() {
	std::list<Peak>::iterator poss;
	std::list<Peak>::iterator pose;
	double xmin = parent()->findChild<SecondDataView*>("graphicsView_2")->series_left->at(0).x();
	double xmax = parent()->findChild<SecondDataView*>("graphicsView_2")->series_right->at(0).x();
	double eventcurrent = parent()->findChild<SecondDataView*>("graphicsView_2")->series_down->at(0).y();
	double baseline = parent()->findChild<SecondDataView*>("graphicsView_2")->series_upper->at(0).y();
	Peak point = { xmin, xmax, eventcurrent, baseline };
	poss = findposs(point.start);
	pose = findpose(point.end);
	eventlist.erase(poss, pose);
	eventlist.insert(pose, point);
	geteventlist();
	return;
}

void ManualPeakFind::removeevent() {
	std::list<Peak>::iterator poss;
	std::list<Peak>::iterator pose;
	double xmin = parent()->findChild<SecondDataView*>("graphicsView_2")->series_left->at(0).x(); 
	double xmax = parent()->findChild<SecondDataView*>("graphicsView_2")->series_right->at(0).x();
	poss = findposs(xmin);
	pose = findpose(xmax);
	eventlist.erase(poss, pose);
	geteventlist();
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

void ManualPeakFind::geteventlist() {
	double xmin = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->min();
	double xmax = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->max();
	std::list<Peak>::iterator poss = findposs(xmin);
	std::list<Peak>::iterator pose = findpose(xmax);
	std::list<Peak>::iterator it;
	QVector<QPointF> point;
	for (it = poss; it != pose; ++it) {
		point.append(QPointF(it->start, it->baseline));
		point.append(QPointF(it->start, it->currentpeak));
		point.append(QPointF(it->end, it->currentpeak));
		point.append(QPointF(it->end, it->baseline));
	}
	emit sendeventlist(point);
}

void ManualPeakFind::forwardwindow() {
	double skip = parent()->findChild<QLineEdit*>("lineEdit_2")->text().toDouble() ;
	double xmax = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->max();
	getdata(xmax, xmax + skip, false);
}

void ManualPeakFind::backwardwindow() {
	double skip = parent()->findChild<QLineEdit*>("lineEdit_2")->text().toDouble();
	double xmin = parent()->findChild<SecondDataView*>("graphicsView_2")->axisx->min();
	getdata(xmin-skip, xmin, false);
}

void ManualPeakFind::saveeventlist() {
	QVector<QPointF> point;
	for (auto i : eventlist ) {
		point.append(QPointF(i.start, i.end));
		point.append(QPointF(i.currentpeak, i.baseline));
	}
	emit sendsaveeventlist(point);
}

void ManualPeakFind::seteventlist(std::list<Peak> data) {
	eventlist = data;
}

void ManualPeakFind::setdatadone(std::list<std::pair<double, double>> data) {
	datadone = data;
	getdatadone();
}