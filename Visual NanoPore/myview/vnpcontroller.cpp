#include<fstream>
#include "Iir.h"
#include "vnpcontroller.h"


VNPController::VNPController(QObject* p, ManualPeakFind* p1,
	VNPTreeWidget* p2): QObject(p) {
	filewidget = p2;
	connect(filewidget, SIGNAL(showdat(QString&)), this, SLOT(opendat(QString&)));
	connect(this, SIGNAL(csvchange()), filewidget, SLOT(checkcsv()));

	dataview = p1;
	connect(dataview, SIGNAL(askdata(double, double, double, double)), this, SLOT(setdata(double, double, double, double)));
	connect(dataview, SIGNAL(send_number(int)), this, SLOT(show_tips(int)));
	connect(this, SIGNAL(senddata(QVector<QPointF>)), dataview, SLOT(setdata(QVector<QPointF>)));
	connect(this, SIGNAL(senddata2(QVector<QPointF>)), dataview, SLOT(setdata2(QVector<QPointF>)));
	connect(this, SIGNAL(sendeventlist(QVector<QPointF>)), dataview, SLOT(seteventlist(QVector<QPointF>)));
	connect(this, SIGNAL(sendeventlist2(QVector<QPointF>)), dataview, SLOT(seteventlist2(QVector<QPointF>)));
	connect(this, SIGNAL(sendeventlist3(QVector<QPointF>)), dataview, SLOT(seteventlist3(QVector<QPointF>)));

	worker = new CalWorker;
	connect(worker, &CalWorker::setprogress, this, &VNPController::setprogress);
	connect(worker, &CalWorker::finish, filewidget, &VNPTreeWidget::checkcsv);
	connect(this, &VNPController::startauto, worker, &CalWorker::run);

	configdialog = new ConfigDialog();
	connect(this, SIGNAL(showconfig()), configdialog, SLOT(show()));
	connect(configdialog, SIGNAL(accepted()), this, SLOT(readparams()));

	//pywidget = p3;
	

	fpworker = new FindPeakWorker();
	fpworker->moveToThread(&calthread);
	connect(this, SIGNAL(startfp()), fpworker, SLOT(run()));
	connect(fpworker, SIGNAL(setevent(QVector<QPointF>)), dataview, SLOT(seteventlist2(QVector<QPointF>)));
	connect(fpworker, SIGNAL(finish()), this, SLOT(readeventlist()));
	calthread.start();
}

VNPController::~VNPController() {
	dat.close();
	calthread.quit();
	//pythread.quit();
	delete worker;
	//delete pyworker;
}

void VNPController::readeventlist() {
	eventlist_temp = fpworker->eventlist;
	emit setprogress(0);
}

/*
void VNPController::startpy(bool ischeck) {
	if (ischeck && !pystarted) {
		pyworker = new PYWorker();
		readparams();
		pyworker->moveToThread(&pythread);
		connect(pywidget, SIGNAL(textinput(QString)), pyworker, SLOT(run_command(QString)));
		connect(pywidget, SIGNAL(sendcomp(QString)), pyworker, SLOT(completion(QString)));
		connect(pyworker, SIGNAL(result_command(QString)), pywidget, SLOT(showtext(QString)));
		connect(pyworker, SIGNAL(send_completion(QString)), pywidget, SLOT(showcompletion(QString)));
		connect(this, SIGNAL(setdatapy(QString)), pyworker, SLOT(setdata(QString)));
		pythread.start();

		QLineEdit* pyedit = configdialog->findChild<QLineEdit*>("pyedit");
		std::string str = pyedit->text().toStdString();
		std::replace(str.begin(), str.end(), '/', '\\');
		std::string pypath = "PYTHONPATH=" + str;
		pyworker->setpath(pypath);
		auto r = pyworker->run();
		if (r) {
			pystarted = true;
			emit setdatapy(fndata);
		}
	}
	
}
*/
void VNPController::opendatlist() {
	foldername = filewidget->open1();
}

void VNPController::opendat(QString& fn) {
	emit setprogress(100);
	std::string csvfn = fn.toStdString().substr(0, fn.size() - 3) + "csv";
	eventlist.clear();
	if (QFileInfo::exists(QString::fromStdString(csvfn))) {
		eventlist = readcsv(csvfn);
	}
	QDir qdir = QFileInfo(fn).absoluteDir();
	cwdpath = qdir.absolutePath().toStdString();
	fndata = fn;
	dat.open(fndata.toStdString(), 1);
	n = dat.size();
	double xmin = 0;
	double xmax = dat.size() * interval / 1000;
	std::pair<double, double> y = dat.valminmax();
	double ymax = std::max(y.first, y.second);
	double ymin = std::min(y.first, y.second);
	dataview->history.clear();
	dataview->history.push_back({ xmin, xmax, ymin, ymax });
	dataview->home();
	seteventlist();
	//if (pystarted)
	//	emit setdatapy(fn);
	emit setprogress(0);
	return;
}

void VNPController::opendat2dialog(bool isopen) {
	if (isopen) {
		fndata2 = QFileDialog::getOpenFileName(filewidget,
			tr("Open DAT file"), "/home", tr("DAT Files (*.dat)"));
		if (QFileInfo::exists(fndata2))
			opendat2(fndata2);
	}
	else {
		dat2.close();
		QVector<QPointF> point;
		emit senddata2(point);
	}
}

void VNPController::show_Imin_Imax(bool isshow) {
	if (isshow) {
		QVector<QPointF> point;
		for (const auto it : eventlist) {
			if (it.Imin == 0)
				continue;
			point.append(QPointF(it.start, it.baseline - it.Imin));
			point.append(QPointF(it.end, it.baseline - it.Imax));
		}
		emit sendeventlist3(point);
	}
	else {
		QVector<QPointF> point;
		emit sendeventlist3(point);
	}
}

void VNPController::show_tips(int number) {
	std::list<Peak>::iterator it = eventlist.begin();
	std::advance(it, number);
	QString msg = QString("shape_oblate: ") + QString::number(it->shape_o) + "\n"\
		+ QString("volume_oblate: ") + QString::number(it->volume_o) + "\n"\
		+ QString("shape_prolate: ") + QString::number(it->shape_p) + "\n"\
		+ QString("volume_prolate: ") + QString::number(it->volume_p);
	QMessageBox::information(filewidget, "events information", msg);
	
}

void VNPController::opendat2(QString& fn) {
	emit setprogress(100);
	dat2.open(fn.toStdString(), 2);
	fndata2 = fn;
	double xmin = 0;
	double xmax = 0;
	double ymin = 0;
	double ymax = 0;
	dataview->getaxis(xmin, xmax, ymin, ymax);
	setdata(xmin, xmax, ymin, ymax);
	emit setprogress(0);
}

void VNPController::seteventlist() {
	QVector<QPointF> point;
	for (auto it : eventlist) {
		point.append(QPointF(it.start, it.baseline));
		point.append(QPointF(it.start, it.currentpeak));
		point.append(QPointF(it.end, it.currentpeak));
		point.append(QPointF(it.end, it.baseline));
	}
	emit sendeventlist(point);
	QSpinBox* spinbox = dataview->findChild<QSpinBox*>("spinBox");
	spinbox->setSuffix(" /" + QString::number(eventlist.size()));
}

void VNPController::setdata(double xmin, double xmax, double ymin, double ymax) {
	emit setprogress(100);
	int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	
	QVector<QPointF> point;
	std::vector<float> data = dat.datafig(s, e);
	int k = ceil(double(e - s) / double(data.size()));
	for (int i = 0; i < data.size(); i++) {
		point.append(QPointF((double)(i * k + s) * interval / 1000, data[i]));
	}
	if (dat2.size() == n) {
		QVector<QPointF> point2;
		data = dat2.datafig(s, e);
		for (int i = 0; i < data.size(); i++) {
			point2.append(QPointF((double)(i * k + s) * interval / 1000, data[i]));
		}
		emit senddata2(point2);
	}
	//clock_t t1 = clock();
	/*
	int skip = (e - s) / 1500;
	int j;
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
	if (dat2.size()==n) {
		QVector<QPointF> point2;
		if (skip <= 1) {
			for (int i = s; i < e; i += 1) {
				point2.append(QPointF((double)i * interval / 1000, dat2.at(i)));
			}
		}
		else {
			for (int i = s; i < e; i += skip) {
				j = (i + skip <= e) ? i + skip : e;
				std::pair<float, float> x = dat2.valminmax(i, j);
				point2.append(QPointF(i * interval / 1000, x.first));
				point2.append(QPointF(i * interval / 1000, x.second));
			}
		}
		emit senddata2(point2);
	}*/
	emit senddata(point);
	emit setprogress(0);
	return;
}

void VNPController::filter(bool check) {
	if (dat.size() == 0) {
		return;
	}
	emit setprogress(100);
	if (!check) {
		dat.open(fndata.toStdString(), 1);
		n = dat.size();
		double xmin = 0;
		double xmax = 0;
		double ymin = 0;
		double ymax = 0;
		dataview->getaxis(xmin, xmax, ymin, ymax);
		setdata(xmin, xmax, ymin, ymax);
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

		std::ofstream wf;
		std::string temppath = "filter_can_delete.dat";
		wf.open(temppath, std::ios::out | std::ios::binary);
		wf.write(reinterpret_cast<const char*>(data), n * sizeof(float));
		wf.close();
		delete[] data;
		QString fn = QString::fromStdString(temppath);
		dat.open(fn.toStdString(),1);
		n = dat.size();
		double xmin = 0;
		double xmax = 0;
		double ymin = 0;
		double ymax = 0;
		dataview->getaxis(xmin, xmax, ymin, ymax);
		setdata(xmin, xmax, ymin, ymax);
	}
	emit setprogress(0);
}


void VNPController::findpeak(bool draw) {
	if (dat.size() == 0)
		return;
	emit setprogress(100);
	if (draw) {
		 interval = mymap["interval"];
		 int stats = dataview->method;
		if (stats==2) {
			double xmin = 0;
			double xmax = 0;
			double eventcurrent = 0;
			double baseline = 0;
			dataview->getbar(xmin, xmax, eventcurrent, baseline);
			if (xmin == xmax || eventcurrent == baseline)
				return;
			int s = xmin * 1000 / interval;
			int e = xmax * 1000 / interval;
			Peak point = { xmin, xmax, eventcurrent, baseline, s, e, s};
			eventlist_temp.clear();
			eventlist_temp.push_back(point);
		}
		else if (stats==1) {
			double xmin = 0;
			double xmax = 0;
			double eventcurrent = 0;
			double baseline = 0;
			dataview->getbar(xmin, xmax, eventcurrent, baseline);
			if (xmin == xmax || eventcurrent == baseline)
				return;
			std::vector<float> dats = dat.data(0, n, 1);
			eventlist_temp = findPeak_manual(dats, mymap, xmin, xmax, baseline, abs(eventcurrent - baseline));
		}
		else if(stats==0) {
			double xmin = 0;
			double xmax = 0;
			double eventcurrent = 0;
			double baseline = 0;
			dataview->getbar(xmin, xmax, eventcurrent, baseline);
			if (xmin != xmax) {
				fpworker->mymap = mymap;
				fpworker->filename = QString::fromStdString(dat.getfilename());
				fpworker->xmin = xmin;
				fpworker->xmax = xmax;
				emit startfp();
				return;
			}	
			//std::vector<float> dats = dat.data(0, n, 1);
			//if (int(mymap["auto"]) == 2)
				//eventlist_temp = findPeak_longevent(dats, mymap, xmin, xmax);
			//else if (int(mymap["auto"]) == 3)
			
				//eventlist_temp = findPeak_parallel(dats, mymap, xmin, xmax);
			//else
				//eventlist_temp = findPeak(dats, mymap, xmin, xmax);
		}
	}
	else {
		eventlist_temp.clear();
	}
	QVector<QPointF> p;
	for (auto& it : eventlist_temp) {
		p.append(QPointF(it.start, it.baseline));
		p.append(QPointF(it.start, it.currentpeak));
		p.append(QPointF(it.end, it.currentpeak));
		p.append(QPointF(it.end, it.baseline));
	}
	emit sendeventlist2(p);
	emit setprogress(0);
}

void VNPController::opencsv(bool isopen) {
	if (isopen) {
		fneventlist = QFileDialog::getOpenFileName(filewidget,
			tr("Open csv file"), "/home", tr("DAT Files (*.csv)"));
		if (QFileInfo::exists(fneventlist)) {
			std::string str = fneventlist.toStdString();
			eventlist = readcsv(str);
		}
		
	}
	else {
		std::string csvfn = fndata.toStdString().substr(0, fndata.size() - 3) + "csv";
		
		eventlist.clear();
		if (QFileInfo::exists(QString::fromStdString(csvfn))) {
			eventlist = readcsv(csvfn);
		}
			
	}
	seteventlist();
}





void VNPController::insertevent() {
	for (auto& i : eventlist_temp) {
		std::list<Peak>::iterator poss;
		std::list<Peak>::iterator pose;

		Peak point = i;
		poss = findposs(point.start);
		pose = findpose(point.end);
		eventlist.erase(poss, pose);
		eventlist.insert(pose, point);
	}
	eventlist_temp.clear();
	seteventlist();
	return;
}

void VNPController::removeevent() {
	double xmin = 0;
	double xmax = 0;
	double eventcurrent = 0;
	double baseline = 0;
	dataview->getbar(xmin, xmax, eventcurrent, baseline);
	if (xmin == xmax)
		return;
	std::list<Peak>::iterator poss;
	std::list<Peak>::iterator pose;
	poss = findposs(xmin);
	pose = findpose(xmax);
	eventlist.erase(poss, pose);
	seteventlist();
	return;
}

std::list<Peak>::iterator VNPController::findposs(double start) {
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

std::list<Peak>::iterator VNPController::findpose(double end) {
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


void VNPController::saveeventlist() {
	emit setprogress(100);
	std::string csvfn = fndata.toStdString().substr(0, fndata.size() - 3) + "csv";
	if (eventlist.size() == 0) {
		std::remove(csvfn.c_str());
		return;
	}
		
	
	std::ofstream file(csvfn, std::ofstream::out | std::ofstream::trunc);
	file << "start,end,start(ms),end(ms),I0(pA),I1(pA),begin\n";
	for (auto& it : eventlist) {
		file << std::to_string(it.s) << ","
			<< std::to_string(it.e) << ","
			<< std::to_string(it.start) << ","
			<< std::to_string(it.end) << ","
			<< std::to_string(it.baseline) << ","
			<< std::to_string(it.currentpeak) << ","
			<< std::to_string(it.s0) << "\n";
	}
	file.close();
	emit csvchange();
	emit setprogress(0);
	//vnpfile->seteventlist(currentgroup.c_str(), eventlist);
}

void VNPController::autorun() {
	worker->mymap = mymap;
	worker->filenames = foldername;
	worker->moveToThread(&calthread);

	
	calthread.start();
	emit startauto();
}

void VNPController::readparams() {
	emit setprogress(100);
	QSpinBox* spinBox = configdialog->findChild<QSpinBox*>("spinBox");
	QSpinBox* spinBox_2 = configdialog->findChild<QSpinBox*>("spinBox_2");
	QComboBox* baselineMethodComboBox = configdialog->findChild<QComboBox*>("baselineMethodComboBox");
	QSpinBox* moveWindowSpinBox = configdialog->findChild<QSpinBox*>("moveWindowSpinBox");
	QSpinBox* orderSpinBox = configdialog->findChild<QSpinBox*>("orderSpinBox");
	QSpinBox* resolutionSpinBox = configdialog->findChild<QSpinBox*>("resolutionSpinBox");
	QSpinBox* stepSizeSpinBox = configdialog->findChild<QSpinBox*>("stepSizeSpinBox");
	QSpinBox* hSpinBox = configdialog->findChild<QSpinBox*>("hSpinBox");
	QSpinBox* thresholdSpinBox = configdialog->findChild<QSpinBox*>("thresholdSpinBox");
	QSpinBox* startPointSpinBox = configdialog->findChild<QSpinBox*>("startPointSpinBox");
	QSpinBox* endPointSpinBox = configdialog->findChild<QSpinBox*>("endPointSpinBox");
	QSpinBox* minWindowSpinBox = configdialog->findChild<QSpinBox*>("minWindowSpinBox");
	QComboBox* directionComboBox = configdialog->findChild<QComboBox*>("directionComboBox");
	QLineEdit* pyedit = configdialog->findChild<QLineEdit*>("pyedit");
	QSpinBox* parallelSpinBox = configdialog->findChild<QSpinBox*>("parallelSpinBox");

	mymap["direction"] = (directionComboBox->currentText() == "Negative") ? -1 : 1;
	interval = 1.0 / double(spinBox->value()) * 1000;
	mymap["interval"] = interval;
	mymap["cutoff"] = spinBox_2->value();
	mymap["fs"] = spinBox->value();
	mymap["order"] = orderSpinBox->value();
	mymap["parallel"] = parallelSpinBox->value();
	if (baselineMethodComboBox->currentText() == "Local Baseline") {
		mymap["auto"] = 2;
		mymap["resolution"] = moveWindowSpinBox->value();
		mymap["maxtime"] = resolutionSpinBox->value();
	}
	else if (baselineMethodComboBox->currentText() == "Moving average") {
		mymap["auto"] = 0;
		mymap["resolution"] = moveWindowSpinBox->value();
	}
	else if(baselineMethodComboBox->currentText() == "Moving median") {
		mymap["auto"] = 1;
		mymap["resolution"] = moveWindowSpinBox->value();

	}
	mymap["threshold"] = thresholdSpinBox->value();
	mymap["window"] = minWindowSpinBox->value();
	mymap["startpoint"] = startPointSpinBox->value();
	mymap["endpoint"] = endPointSpinBox->value();
	
	emit setprogress(0);
}

void VNPController::copydata() {
	if (dat.size() == 0) {
		return;
	}
	emit setprogress(100);
	double x1, x2, y1, y2;
	dataview->getaxis(x1, x2, y1, y2);
	//QSpinBox* spinbox = dataview->findChild<QSpinBox*>("spinBox");
	//int i = spinbox->value();
	//int s = std::next(eventlist.begin(), i)->s0;
	//int e = std::next(eventlist.begin(), i)->e;
	int s = x1 / interval * 1000;
	int e = x2 / interval * 1000;
	if (e > dat.size())
		e = dat.size();
	if (s < 0)
		s = 0;
	std::vector<float> data = dat.datafig(s, e);
	int k = ceil(double(e - s) / double(data.size()));
	std::ofstream myfile;
	std::string fn = fndata.toStdString().substr(0, fndata.size() - 4) + "_" + std::to_string(x1) + "_ms_" + std::to_string(x2) + "_ms.csv";
	myfile.open(fn, std::ofstream::out | std::ofstream::trunc);
	myfile << "dt(ms),current(pA)\n";
	for (int i = 0; i < data.size(); i++) {
		myfile << std::to_string((double)(i * k) * interval / 1000) + "," + std::to_string(data[i]) + "\n";
	}
	myfile.close();
	emit setprogress(0);
}
