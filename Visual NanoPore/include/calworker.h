#pragma once

#ifndef CALWORKER_H
#define CALWORKER_H

#include <QtCore/qobject.h>
#include <list>
#include <unordered_map>
#include <string>


class CalWorker : public QObject {
	Q_OBJECT

public:
	std::unordered_map<std::string, double> mymap;
	QStringList filenames;

public slots:
	void run();


signals:
	void setprogress(int);
	void finish();
};


#endif //CALWORKER_H