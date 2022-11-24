#ifndef VNPTREEWIDGET_H
#define VNPTREEWIDGET_H

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QFileDialog>



class VNPTreeWidget : public QTreeWidget {
	Q_OBJECT;
public:
	VNPTreeWidget(QWidget* parent);
	//VNPIO vnpfile;
	//void tocsv();
public slots:
	QStringList open1();
	//void open2(std::string);
	void doubleclick(QTreeWidgetItem* item, int column);
	//void closedata();
	void checkcsv();


signals:
	void showdat(QString& fn);
	void configchange();
	void stopauto();

private:
	QStringList filenames;
	QString currentgroup;
	QFileInfo info;
};
#endif // !VNPTREEWIDGET_H
