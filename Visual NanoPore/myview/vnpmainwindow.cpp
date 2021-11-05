#include "vnpmainwindow.h" 
#include "createvnp.h"
#include "vnptreewidget.h"
#include "configdialog.h"



VNPMainWindow::VNPMainWindow(QWidget* parent) :QMainWindow(parent) {
	ui.setupUi(this);
	QToolBar* toolbar = this->findChild<QToolBar*>("toolBar");
	QAction* actionopen = this->findChild<QAction*>("actionopen");
	QAction* actionnew = this->findChild<QAction*>("actionnew");
	QAction* actionautopeakfind = this->findChild<QAction*>("actionautopeakfind");
	connect(actionopen, SIGNAL(triggered()), this, SLOT(openfile()));
	connect(actionnew, SIGNAL(triggered()), this, SLOT(createfile()));
	connect(actionautopeakfind, SIGNAL(triggered()), this, SLOT(createconfig()));
}

void VNPMainWindow::openfile() {
	VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
	treewidget->open1();
}

void VNPMainWindow::createfile() {
	createvnp* newvnp = new createvnp();
	newvnp->setconfig(mymap);
	newvnp->show();
	if (newvnp->exec() == QDialog::Accepted) {
		VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
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

	if (configdialog->exec() == QDialog::Accepted) {
		
		int row = tablewidget->rowCount();
		for (int i = 0; i < row; i++) {
			mymap[tablewidget->item(i, 0)->text().toStdString()] = tablewidget->item(i, 1)->text().toDouble();
		}
		VNPTreeWidget* treewidget = this->findChild<VNPTreeWidget*>("treeWidget");
		configdialog->deleteLater();
	}
}
