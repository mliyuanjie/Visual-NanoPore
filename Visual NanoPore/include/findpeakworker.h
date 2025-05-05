#pragma once

#ifndef FINDPEAKWORKER_H
#define FINDPEAKWORKER_H

#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include  <QtCore/qpoint.h>
#include <list>
#include <unordered_map>
#include <string>
#include "tools.h"


class FindPeakWorker : public QObject {
	Q_OBJECT

public:
	std::unordered_map<std::string, double> mymap;
	QString filename;
	std::list<Peak> eventlist;
	double xmin;
	double xmax;
	void run_long();
	void run_short();

public slots:
	void run();

signals:
	void setevent(QVector<QPointF>);
	void finish();
};


#endif //FINDPEAKWORKER_H
