#include "npsio.h"
#include "datmodel.h"


DATModel::~DATModel() {
	dat.close();
}

void DATModel::load(std::string f) {
	fn = f;
	dat.open(fn);
	interval = dat.interval();
	n = dat.size();
	double xmin = 0;
	double xmax = dat.size() * interval / 1000;
	std::pair<double, double> y = dat.valminmax();
	double ymax = std::max(y.first, y.second);
	double ymin = std::min(y.first, y.second);
	emit sendAxis(xmin, xmax, ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin));
	return;
}

void DATModel::home() {
	double xmin = 0;
	double xmax = n * interval / 1000;
	std::pair<double, double> y = dat.valminmax();
	double ymax = std::max(y.first, y.second);
	double ymin = std::min(y.first, y.second);
	emit sendAxis(xmin, xmax, ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin));
	return;
}

void DATModel::draw(double xmin, double xmax) {
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >=0) ? xmax * 1000 / interval : n;
	unsigned int skip = (e-s) / 1500;
	unsigned int j;
	QVector<QPointF> point;	
	if (skip <= 1) {
		for (unsigned int i = s; i < e; i += 1) {
			point.append(QPointF((double)i * interval / 1000, dat.at(i)));
		}
	}
	else {
		for (unsigned int i = s; i < e; i += skip) {
			j = (i + skip <= e) ? i + skip : e;
			std::pair<float, float> x = dat.valminmax(i, j);
			point.append(QPointF(i * interval / 1000, x.first));
			point.append(QPointF(i * interval / 1000, x.second));
		}
	}
	emit sendData(point);
	return;
}

void DATModel::meansd(double xmin, double xmax) {
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	std::pair<float, float> y = dat.meansd();
	emit sendMean(y.first);
	emit sendSD(y.second);
	return;
}

void DATModel::setinterval(double a) {
	interval = 1 / a * 1000;
	home();
}
