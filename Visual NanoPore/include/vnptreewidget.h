#ifndef VNPTREEWIDGET_H
#define VNPTREEWIDGET_H

#include <QtWidgets/QTreeWidget>
#include "vnpio.h"
#include "manual.h"

class VNPTreeWidget : public QTreeWidget {
	Q_OBJECT;
public:
	VNPTreeWidget(QWidget* parent);
	VNPIO vnpfile;
	void tocsv();
public slots:
	void open1();
	void open2(std::string);
	void doubleclick(QTreeWidgetItem* item, int column);
	void closedata(QString);

signals:
	void showdat(QString fn);

private:
	QString filename;
	QString currentgroup;
	ManualPeakFind* manualtask = NULL;
};
#endif // !VNPTREEWIDGET_H
