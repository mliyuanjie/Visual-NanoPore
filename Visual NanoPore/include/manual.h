#ifndef MANUAL_H
#define MAUNAL_H

#include <QtCore/qobject.h>
#include <QtWidgets/QMdiSubWindow>
#include <list>
#include <utility>
#include <vector>
#include "manualui.h"
#include "tools.h"
#include "datio.h"
#include "vnpio.h"

struct axisrange {
	double xmin;
	double xmax;
	double ymin;
	double ymax;
};

class ManualPeakFind :public QMdiSubWindow {
	Q_OBJECT
public:
	ManualPeakFind(QWidget* p = nullptr);
	~ManualPeakFind();


public slots:
	void opendat(QString, VNPIO&);
	void senddata(double xmin, double xmax, double ymin, double ymax);
	void home();
	void backward();
	void forward();
	void insertregion();
	void removeregion();
	void insertevent();
	void removeevent();
	void sendeventlist();
	void senddatadone();
	void saveeventlist();
	void savedatadone();
	void backwardwindow();
	void forwardwindow();
	void filter(std::unordered_map<std::string, double>&, bool);
	void findpeak(std::unordered_map<std::string, double>&);

signals:
	void senddata(QVector<QPointF>);
	void senddatadone(QVector<QPointF>);
	void sendxscale(double, double);
	void sendyscale(double, double);
	void sendeventlist(QVector<QPointF>);
	void offline(QString);

private:
	Ui::Form ui;
	QWidget* widget;
	std::string filename;
	std::list<Peak> history;
	std::list<std::pair<double, double>> datadone;
	int windowsize = 500000;
	double interval = 2;
	std::list<Peak> eventlist;
	DATIO dat;
	VNPIO* vnpfile = nullptr;
	std::string currentgroup;
	int n;
	std::list<Peak>::iterator pos;
	std::list<Peak>::iterator findposs(double);
	std::list<Peak>::iterator findpose(double);
};

#endif //MAUNAL_H