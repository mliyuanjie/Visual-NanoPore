#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qmenu.h>
#include <QtCore/qdebug.h>
#include <QtCore/qfileinfo.h>
#include <QtWidgets/QDockWidget>
#include <fstream>
#include <vnptreewidget.h>


VNPTreeWidget::VNPTreeWidget(QWidget* parent) :
	QTreeWidget(parent) {
	connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(doubleclick(QTreeWidgetItem*, int)));
	
} 

QStringList VNPTreeWidget::open1() {
	filenames = QFileDialog::getOpenFileNames(
		this,
		"Select one to open",
		"/home",
		"project file (*.dat)");

	for (int i = 0; i < filenames.size(); i++) {
		QTreeWidgetItem* items = new QTreeWidgetItem(this);
		info = QFileInfo(filenames[i]);
		items->setText(0, info.completeBaseName());
		QString csvname = info.path() + "/" + info.completeBaseName() + ".csv";
		if (QFileInfo::exists(csvname))
			items->setForeground(0, Qt::green);
		this->insertTopLevelItem(i, items);
	}
	if (filenames.size() == 0) {
		return QStringList();
	}
	return filenames;
}

void VNPTreeWidget::checkcsv() {
	QTreeWidgetItem* items = NULL;
	for (int i = 0; i < this->topLevelItemCount(); i++) {
		items = this->topLevelItem(i);
		QString csvfn = info.path() + "/" + items->text(0) + ".csv";
		info = QFileInfo(csvfn);
		if (QFileInfo::exists(csvfn))
			items->setForeground(0, Qt::green);
	}
}

/*
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
*/
void VNPTreeWidget::doubleclick(QTreeWidgetItem* item, int column) {
	QString datfn = info.path() + "/" + item->text(0) + ".dat";
	emit showdat(datfn);
	return;
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