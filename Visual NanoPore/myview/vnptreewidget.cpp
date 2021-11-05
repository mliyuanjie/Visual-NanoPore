#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMdiArea>

#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qmenu.h>
#include <QtCore/qdebug.h>
#include <QtCore/qfileinfo.h>
#include <QtWidgets/QDockWidget>
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
		"project file (*.vnp)");
	open2(filename.toStdString());

}

void VNPTreeWidget::open2(std::string fn) {
	filename = QString::fromStdString(fn);
	vnpfile.open(fn);
	std::vector<std::string> filelist = vnpfile.getfilelist();
	for (int i = 0; i < filelist.size(); i++) {
		QTreeWidgetItem* items = new QTreeWidgetItem(this);
		items->setText(0, QString::fromStdString(filelist[i]));
		this->insertTopLevelItem(i, items);
	}
}

void VNPTreeWidget::doubleclick(QTreeWidgetItem* item, int column) {
	QDir dir = QFileInfo(filename).absoluteDir();
	currentgroup = item->text(0);
	QString datafilename = dir.absoluteFilePath(item->text(0)+".dat");
	QMdiArea* mdiarea = this->parent()->parent()->parent()->findChild<QMdiArea*>("mdiArea");
	ManualPeakFind* manualtask = new ManualPeakFind();
	connect(manualtask, SIGNAL(senddatadone(QVector<QPointF>)), this, SLOT(savedatadone(QVector<QPointF>)));
	connect(manualtask, SIGNAL(sendsaveeventlist(QVector<QPointF>)), this, SLOT(saveeventlist(QVector<QPointF>)));
	manualtask->opendat(datafilename, 2);
	manualtask->setdatadone(vnpfile.getdatadone(std::string("/") + currentgroup.toStdString() + "/datadone"));
	manualtask->seteventlist(vnpfile.geteventlist(std::string("/") + currentgroup.toStdString() + "/eventlist"));
	mdiarea->addSubWindow(manualtask);
	manualtask->show();
	
	return;
}

void VNPTreeWidget::savedatadone(QVector<QPointF> datadonelist) {
	std::list<std::pair<double, double>> datadone;
	for (auto i : datadonelist) {
		datadone.push_back(std::pair<double, double>(i.x(), i.y()));
	}
	vnpfile.setdatadone("/" + currentgroup.toStdString() + "/datadone", datadone);
}

void VNPTreeWidget::saveeventlist(QVector<QPointF> peaklist) {
	std::list<Peak> eventlist;
	for (int i = 0; i < peaklist.size() / 2;i++) {
		eventlist.push_back({ peaklist[i * 2].x(), peaklist[i * 2].y(), peaklist[i * 2 + 1].x(), peaklist[i * 2 + 1].y() });
	}
	vnpfile.seteventlist(currentgroup.toStdString() + "/eventlist", eventlist);
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