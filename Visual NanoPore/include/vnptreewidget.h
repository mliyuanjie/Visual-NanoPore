#ifndef VNPTREEWIDGET_H
#define VNPTREEWIDGET_H


#include "vnpio.h"

class VNPTreeWidget : public QTreeWidget {
	Q_OBJECT;
public:
	VNPTreeWidget(QWidget* parent);
	VNPIO vnpfile;
public slots:
	void open1();
	void open2(std::string);
	void doubleclick(QTreeWidgetItem* item, int column);
	void saveeventlist(QVector<QPointF>);
	void savedatadone(QVector<QPointF>);

signals:
	void showdat(QString fn);

private:
	QString filename;
	QString currentgroup;
};
#endif // !VNPTREEWIDGET_H
