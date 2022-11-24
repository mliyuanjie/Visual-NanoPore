#pragma once
#ifndef VNPCONTROLLER_H
#define VNPCONTROLLER_H

#include <QtCore/qobject.h>
#include <QtWidgets/QMdiSubWindow>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <QtWidgets/QFileDialog>
#include <QtCore/qfileinfo.h>
#include <filesystem>
#include "vnptreewidget.h"
#include "manual.h"
#include "configdialog.h"
#include "tools.h"
#include "datio.h"
#include "calworker.h"
#include "pyworker.h"
#include "pythonwidget.h"


class VNPController :public QObject {
	Q_OBJECT;
public:
	VNPController(QObject* p, ManualPeakFind* p1, VNPTreeWidget* p2, PythonWidget* p3);
	~VNPController();


public slots:
	void opendatlist();
	void opendat2dialog(bool);
	void opencsv(bool);
	void opendat(QString&);
	void opendat2(QString&);
	void autorun();
	void filter(bool);
	void findpeak(bool);
	void insertevent();
	void removeevent();
	void seteventlist();
	void saveeventlist();
	void setdata(double, double, double, double);	
	void readparams();


signals:
	void senddata(QVector<QPointF>);
	void senddata2(QVector<QPointF>);
	void sendeventlist(QVector<QPointF>);
	void sendeventlist2(QVector<QPointF>);
	void startpy(bool);
	void csvchange();
	void startauto();
	void setprogress(int);
	void showconfig();
	void setdatapy(QString);

private:
	QStringList foldername;
	QString fndata;
	QString fndata2;
	QString fneventlist;
	QString fneventlist2;
	std::string cwdpath;
	
	std::list<Peak> eventlist;
	std::list<Peak> eventlist_temp;
	

	int n = 0;
	int datastate = 0;
	double interval = 2;
	std::list<Peak>::iterator pos;
	std::list<Peak>::iterator findposs(double);
	std::list<Peak>::iterator findpose(double);
	std::unordered_map<std::string, double> mymap;

	QThread calthread;
	QThread pythread;
	ManualPeakFind* dataview;
	VNPTreeWidget* filewidget;
	DATIO dat;
	DATIO dat2;
	CalWorker* worker;
	PYWorker* pyworker;
	ConfigDialog* configdialog;
	PythonWidget* pywidget;
};

#endif //VNPCONTROLLER_H
