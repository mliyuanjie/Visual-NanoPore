#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qmenu.h>
#include <QtCore/qdebug.h>
#include <QtCore/qfileinfo.h>
#include <QtWidgets/QDockWidget>
#include <fstream>
#include <vnptreewidget.h>
#include "manual.h"
#include "tools.h"

VNPTreeWidget::VNPTreeWidget(QWidget* parent) :
	QTreeWidget(parent) {
	connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(doubleclick(QTreeWidgetItem*, int)));
} 

void VNPTreeWidget::open1() {
	filename = QFileDialog::getOpenFileName(
		this,
		"Select one to open",
		"/home",
		"project file (*.h5 *.vnp)");
	open2(filename.toStdString());

}

void VNPTreeWidget::tocsv() {
	std::vector<std::string> filelist = vnpfile.getfilelist();
	std::list<Peak>::iterator it;
	for (int i = 1; i < filelist.size(); i++) {
		std::string newfile = filename.mid(0, filename.lastIndexOf("/")).toStdString() + "/" + filelist[i] + ".csv";
		std::ofstream file(newfile);
		file << "start time,end time,I0,event current\n";
		std::list<Peak> eventlist = vnpfile.geteventlist(filelist[i]);
		it = eventlist.begin();
		while (it != eventlist.end()) {
			file << std::to_string(it->start) << ',' << std::to_string(it->end) << ',' << std::to_string(it->baseline) << ',' << std::to_string(it->currentpeak) << '\n';
			++it;
		}
		file.close();
	}
	QMessageBox msgBox;
	msgBox.setText("Done!");
	msgBox.exec();
}

void VNPTreeWidget::open2(std::string fn) {
	filename = QString::fromStdString(fn);
	vnpfile.open(fn);
	std::vector<std::string> filelist = vnpfile.getfilelist();
	for (int i = 1; i < filelist.size(); i++) {
		QTreeWidgetItem* items = new QTreeWidgetItem(this);
		items->setText(0, QString::fromStdString(filelist[i]));
		if (!vnpfile.geteventlist(filelist[i]).empty())
			items->setTextColor(0, Qt::green);
		this->insertTopLevelItem(i - 1, items);
	}
}

void VNPTreeWidget::doubleclick(QTreeWidgetItem* item, int column) {
	item->setTextColor(0, Qt::red);
	QMdiArea* mdiarea = this->parent()->parent()->parent()->findChild<QMdiArea*>("mdiArea");
	ManualPeakFind* manualtask = new ManualPeakFind();
	manualtask->opendat(item->text(0), vnpfile);
	mdiarea->addSubWindow(manualtask);
	manualtask->show();
	connect(manualtask, SIGNAL(offline(QString)), this, SLOT(closedata(QString)));
	return;
}


void VNPTreeWidget::closedata(QString currentgroup) {
	std::vector<std::string> filelist = vnpfile.getfilelist();
	for (int i = 1; i < filelist.size(); i++) {
		if (currentgroup.toStdString() == filelist[i]) {
			QTreeWidgetItem* items = topLevelItem(i - 1);
			if (!vnpfile.geteventlist(filelist[i]).empty())
				items->setTextColor(0, Qt::green);
			else
				items->setTextColor(0, Qt::black);
			return;
		}
	}
}
/*
void VNPTreeWidget::contextMenuEvent(QContextMenuEvent* event)
{
	QMenu* popMenu = new QMenu(this);
	QModelIndex index = currentIndex();
	QFileInfo fileinfo = QFileInfo(this->textElideMode());
	if (fileinfo.isDir())
		return;
	// qDebug()<<"right:"<<i;
	QAction* ren = new QAction(QObject::tr("Rename"), this);
	QAction* del = new QAction(QObject::tr("Delete"), this);
	popMenu->addAction(ren);
	popMenu->addAction(del);
	connect(ren, SIGNAL(triggered()), this, SLOT(renamefile()));
	connect(del, SIGNAL(triggered()), this, SLOT(deletefile()));
	popMenu->exec(QCursor::pos());
}

void VNPTreeWidget::renamefile() {
	QModelIndex index = currentIndex();
	edit(index);
}

void VNPTreeWidget::deletefile() {
	QMessageBox msgBox;
	msgBox.setText(model->filePath(currentIndex()));
	msgBox.setInformativeText("Are you sure to delete it?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::No);
	int ret = msgBox.exec();
	switch (ret) {
	case QMessageBox::Yes:
		model->remove(currentIndex());
	case QMessageBox::No:
		break;
	default:
		break;
	}
	return;
}
*/