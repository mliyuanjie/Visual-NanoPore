#ifndef MANUAL_H
#define MAUNAL_H

#include <QtCore/qobject.h>
#include <QtWidgets/QMdiSubWindow>
#include <list>
#include <utility>
#include <vector>
#include "manual peakfind.h"
#include "tools.h"
#include "datio.h"


class ManualPeakFind :public QMdiSubWindow {
	Q_OBJECT
public:
	ManualPeakFind(QWidget* p = nullptr);
	~ManualPeakFind();


public slots:
	void opendat(QString fn, double fs);
	void getdata(double xmin, double xmax, bool mainview);
	void getdatadone();
	void meansd(double xmin, double xmax);
	void home();
	void backward();
	void forward();
	void insertregion();
	void removeregion();
	void insertevent();
	void removeevent();
	void geteventlist();
	void saveeventlist();
	void backwardwindow();
	void forwardwindow();
	void seteventlist(std::list<Peak>);
	void setdatadone(std::list<std::pair<double, double>>);
	void filter(bool);

signals:
	void senddata1(QVector<QPointF>);
	void senddata2(QVector<QPointF>);
	void senddatadone(QVector<QPointF>);
	void sendxscale1(double, double);
	void sendyscale(double, double);
	void sendxscale2(double, double);
	void sendeventlist(QVector<QPointF>);
	void sendsaveeventlist(QVector<QPointF>);
	void sendmean(double);
	void sendsd(double);

private:
	Ui::Form ui;
	QWidget* widget;
	std::string filename;
	std::list<std::pair<double, double>> history;
	std::list<std::pair<double, double>> datadone;
	int windowsize = 500000;
	double interval = 2;
	std::list<Peak> eventlist;
	DATIO dat;
	int n;
	std::list<std::pair<double, double>>::iterator pos;
	std::list<Peak>::iterator findposs(double);
	std::list<Peak>::iterator findpose(double);
};

#endif //MAUNAL_H