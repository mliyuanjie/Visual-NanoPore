#include "manual.h"
#include "vnpmainwindow.h" 
#include "createvnp.h"
#include "vnptreewidget.h"
#include "tools.h"
#include "configdialog.h"



VNPMainWindow::VNPMainWindow(QWidget* parent) :QMainWindow(parent) {
	ui.setupUi(this);
	QToolBar* toolbar = this->findChild<QToolBar*>("toolBar");
	QAction* actionopen = this->findChild<QAction*>("actionopen");
	QAction* actionnew = this->findChild<QAction*>("actionnew");
	QAction* actionparameter = this->findChild<QAction*>("actionparameter");
	QAction* actionfilter = this->findChild<QAction*>("actionfilter");
	QAction* actionfindpeak = this->findChild<QAction*>("actionfindpeak");
	QAction* actionexport_csv = this->findChild<QAction*>("actionexport_csv");
	QAction* actionmergedata = this->findChild<QAction*>("actionmergedata");
	connect(actionopen, SIGNAL(triggered()), this, SLOT(openfile()));
	connect(actionnew, SIGNAL(triggered()), this, SLOT(createfile()));
	connect(actionparameter, SIGNAL(triggered()), this, SLOT(createconfig()));
	connect(actionfilter, SIGNAL(toggled(bool)), this, SLOT(filter(bool)));
	connect(actionfindpeak, SIGNAL(triggered()), this, SLOT(findpeak()));
	connect(actionexport_csv, SIGNAL(triggered()), this, SLOT(tocsv()));
	connect(actionmergedata, SIGNAL(triggered()), this, SLOT(mergedata()));
	mymap = readconfig("config.txt");
}

void VNPMainWindow::openfile() {
	VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
	treewidget->clear();
	treewidget->open1();
}

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
		treewidget->open2(newvnp->filepath);
	}
}

void VNPMainWindow::createconfig() {
	ConfigDialog* configdialog = new ConfigDialog();
	configdialog->show();
	QTableWidget* tablewidget = configdialog->findChild<QTableWidget*>("tableWidget");
	tablewidget->setRowCount(mymap.size());
	int i = 0;
	for (std::pair<std::string, double> element : mymap)
	{
		QTableWidgetItem* itemkey = new QTableWidgetItem(QString::fromStdString(element.first));
		QTableWidgetItem* itemvalue = new QTableWidgetItem(QString::number(element.second));
		tablewidget->setItem(i, 0, itemkey);
		tablewidget->setItem(i, 1, itemvalue);
		i++;
	}
	configdialog->deleteLater();
	if (configdialog->exec() == QDialog::Accepted) {
		
		int row = tablewidget->rowCount();
		for (int i = 0; i < row; i++) {
			mymap[tablewidget->item(i, 0)->text().toStdString()] = tablewidget->item(i, 1)->text().toDouble();
		}
		VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
		
	}
}

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
	subwindow->findpeak(mymap);
	return;
}

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
