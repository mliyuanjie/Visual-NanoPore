#ifndef DATMODEL_H
#define DATMODEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include <gsl/gsl_vector.h>
#include "datio.h"
#include "tools.h"

class DATModel:public QObject {
	Q_OBJECT
public: ~DATModel();
public slots:
	void load(std::string);
	void draw(double xmin, double xmax);
	void meansd(double xmin, double xmax);
	void home();
	void setinterval(double);

signals:
	void sendData(QVector<QPointF>);
	void sendAxis(double xmin, double xmax, double ymin, double ymax);
	void sendMean(double);
	void sendSD(double);

private:
	DATIO dat;
	std::string fn;
	float interval;
	std::vector<Peak> sigs;
	size_t n;
	std::vector<float> data_smooth;
};



#endif //DATMODEL_H