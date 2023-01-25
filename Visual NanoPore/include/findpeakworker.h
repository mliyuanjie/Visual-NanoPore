#pragma once

#ifndef FINDPEAKWORKER_H
#define FINDPEAKWORKER_H

#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include <list>
#include <unordered_map>
#include <string>
#include "tools2.h"


class FindPeakWorker : public QObject {
	Q_OBJECT

public:
	std::unordered_map<std::string, double> mymap;
	QString filename;
	std::list<Peak> eventlist;
	double xmin;
	double xmax;

public slots:
	void run();


signals:
	void setevent(QVector<QPointF>);
	void finish();
};


#endif //FINDPEAKWORKER_H
