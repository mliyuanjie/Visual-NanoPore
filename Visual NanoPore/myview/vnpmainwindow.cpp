#include "manual.h"
#include "vnpmainwindow.h" 
#include "createvnp.h"
#include "vnptreewidget.h"
#include "tools.h"




VNPMainWindow::VNPMainWindow(QWidget* parent) :QMainWindow(parent) {
	ui.setupUi(this);
	QToolBar* toolbar = this->findChild<QToolBar*>("toolBar");
	QAction* actionopen = this->findChild<QAction*>("actionopen");
	QAction* actionparameter = this->findChild<QAction*>("actionparameter");
	QAction* actionauto_run = this->findChild<QAction*>("actionauto_run");
	QAction* actionstop_auto = this->findChild<QAction*>("actionstop_auto");
	QAction* actionfilter = this->findChild<QAction*>("actionfilter");
	QAction* actionbaseline = this->findChild<QAction*>("actionbaseline");
	QAction* actionfind_peak = this->findChild<QAction*>("actionfind_peak");
	VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
	connect(actionopen, SIGNAL(triggered()), this, SLOT(openfile()));
	connect(actionauto_run, SIGNAL(triggered()), treewidget, SLOT(autorun()));
	connect(actionstop_auto, SIGNAL(triggered()), treewidget, SIGNAL(stopauto()));
	connect(this, SIGNAL(configchange()), treewidget, SIGNAL(configchange()));

	configdialog = new ConfigDialog();
	connect(actionparameter, SIGNAL(triggered()), configdialog, SLOT(show()));
	connect(configdialog, SIGNAL(accepted()), this, SLOT(createconfig()));

	manualtask = new ManualPeakFind();
	manualtask->setObjectName(QStringLiteral("manualtask"));

	QMdiArea* mdiarea = this->findChild<QMdiArea*>("mdiArea");
	connect(treewidget, SIGNAL(configchange()), manualtask, SLOT(readparams()));
	connect(manualtask, SIGNAL(csvchange()), treewidget, SLOT(checkcsv()));
	connect(treewidget, SIGNAL(stoprun()), manualtask, SLOT(stoprun()));
	mdiarea->addSubWindow(manualtask);
	manualtask->setVisible(false);
	mymap["direction"] = -1;
	mymap["interval"] = 2;
	mymap["cutoff"] = 50;
	mymap["fs"] = 500;
	mymap["order"] = 5;
	mymap["resolution"] = 5000;
	mymap["auto"] = -1;
	mymap["threshold"] = 5;
	mymap["window"] = 5;
	mymap["startpoint"] = 0;
	mymap["endpoint"] = 20000;
	connect(actionfilter, SIGNAL(triggered(bool)), manualtask, SLOT(filter(bool)));
	connect(actionbaseline, SIGNAL(triggered()), manualtask, SLOT(helpfn(bool)));
	connect(actionfind_peak, SIGNAL(triggered(bool)), manualtask, SLOT(addeventlist_temp(bool)));

}

void VNPMainWindow::openfile() {
	VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
	treewidget->clear();
	treewidget->open1();
}

/*
void VNPMainWindow::createfile() {
	createvnp* newvnp = new createvnp();
	newvnp->setconfig(mymap);
	newvnp->show();
	newvnp->deleteLater();
	if (newvnp->exec() == QDialog::Accepted) {
		newvnp->savefile();
		VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
		treewidget->clear();
		if (newvnp->filepath.empty())
			return;
//		treewidget->open2(newvnp->filepath);
	}
}
*/
void VNPMainWindow::createconfig() {
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
	mymap["direction"] = (directionComboBox->currentText() == "Negative") ? -1 : 1;
	mymap["interval"] = 1.0 / double(spinBox->value()) * 1000;
	mymap["cutoff"] = spinBox_2->value();
	mymap["fs"] = spinBox->value();
	mymap["order"] = orderSpinBox->value();
	if (baselineMethodComboBox->currentText() == "Polynomial fit") {
		mymap["auto"] = 1;
		mymap["resolution"] = resolutionSpinBox->value();
		mymap["order"] = orderSpinBox->value();
	}
	else if (baselineMethodComboBox->currentText() == "Moving average") {
		mymap["auto"] = 0;
		mymap["resolution"] = moveWindowSpinBox->value();
	}
	else if (baselineMethodComboBox->currentText() == "Self Adapt") {
		mymap["auto"] = 2;
		mymap["resolution"] = moveWindowSpinBox->value();
		
	}
	mymap["threshold"] = thresholdSpinBox->value();
	mymap["window"] = minWindowSpinBox->value();
	mymap["startpoint"] = startPointSpinBox->value();
	mymap["endpoint"] = endPointSpinBox->value();
	emit configchange();
}
/*
void VNPMainWindow::findpeak() {
	QMessageBox msgBox;
	msgBox.setText("auto find peak will change the event list,\n please use it before manual checking.\n Do you want to stop auto find peak?\n");
	msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	if (msgBox.exec() == QMessageBox::Yes)
		return;
	if (mymap.empty()) {
		QMessageBox msgBox;
		msgBox.setText("Please set config file");
		msgBox.exec();
		return;
	}
	ManualPeakFind* subwindow = qobject_cast<ManualPeakFind*>(findChild<QMdiArea*>("mdiArea")->activeSubWindow());
	subwindow->findpeak();
	return;
}
*/
/*
void VNPMainWindow::filter(bool isfilter) {
	if (mymap.empty()) {
		QMessageBox msgBox;
		msgBox.setText("Please set config file");
		msgBox.exec();
		return;
	}
	ManualPeakFind* subwindow = qobject_cast<ManualPeakFind*>(findChild<QMdiArea*>("mdiArea")->activeSubWindow());
	subwindow->filter(mymap, isfilter);
}

void VNPMainWindow::tocsv() {
	VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
	treewidget->tocsv();
}
*/
