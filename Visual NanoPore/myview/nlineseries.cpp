#include "nlineseries.h" 

NLineSeries::NLineSeries(QObject* parent):QLineSeries(parent) {

}

void NLineSeries::mousepress(QPointF point) {
	if (point.x() > at(0).x() && point.x() < at(1).x() && abs(point.y() - at(0).y()) < 20) {
		move_or_not = true;
	}
}

void NLineSeries::mousemove(QPointF point) {
	if (!move_or_not)
		return;
	QVector<QPointF> data;
	data << QPointF(at(0).x(), point.y());
	data << QPointF(at(1).x(), point.y());
	replace(data);
}

void NLineSeries::mouserelease(QPointF point) {
	move_or_not = false;
}