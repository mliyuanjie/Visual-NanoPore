#pragma once
#ifndef MANUAL_H
#define MAUNAL_H

#include <QtCore/qobject.h>
#include <list>
#include <utility>
#include <vector>
#include "manualui.h"
#include "tools.h"
#include "datio.h"
#include "qtdataview.h"

struct axisrange {
	double xmin;
	double xmax;
	double ymin;
	double ymax;
};

class ManualPeakFind :public QWidget {
	Q_OBJECT
public:
	ManualPeakFind(QWidget* p = nullptr);

	int method = 0;
	void getbar(double&, double&, double&, double&);
	void getaxis(double&, double&, double&, double&);
	std::list<axisrange> history;


public slots:
	//showing data interface, two float data and two event list
	void setdata(QVector<QPointF>);
	void setdata2(QVector<QPointF>);
	void seteventlist(QVector<QPointF>);
	void seteventlist2(QVector<QPointF>);

	//button in manual ui
	void setscale(double, double, double, double);
	void setx1(double);
	void setx2(double);
	void sety1(double);
	void sety2(double);
	void home();
	void backward();
	void forwardwindow();
	void methodboxchange(QString);


signals:
	void askdata(double xmin, double xmax, double ymin, double ymax);

private:
	Ui::Form ui;
	
	DataView* firstview = NULL;
};

#endif //MAUNAL_H