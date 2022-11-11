#ifndef VNPTREEWIDGET_H
#define VNPTREEWIDGET_H

#include <QtWidgets/QTreeWidget>
#include "vnpio.h"
#include "manual.h"

class VNPTreeWidget : public QTreeWidget {
	Q_OBJECT;
public:
	VNPTreeWidget(QWidget* parent);
	//VNPIO vnpfile;
	//void tocsv();
public slots:
	void open1();
	//void open2(std::string);
	void doubleclick(QTreeWidgetItem* item, int column);
	//void closedata();
	void autorun();
	void checkcsv();


signals:
	void showdat(QString fn);
	void configchange();
	void progress(int);
	void stopauto();

private:
	QStringList filenames;
	QString currentgroup;
	QFileInfo info;
};
#endif // !VNPTREEWIDGET_H
