#include "qthvlineseries.h" 


HLineSeries::HLineSeries(QObject* p):QLineSeries(p) {
	
	connect(this, &QXYSeries::hovered, this, &HLineSeries::onhovered);
}

void HLineSeries::onhovered(const QPointF& point, bool state) {
	if (state) {
		emit changecursor(Qt::SizeVerCursor);
		this->setPen(QPen(Qt::red, 2));
	}
	else {
		emit changecursor(Qt::ArrowCursor);
		this->setPen(QPen(Qt::red, 1));
	}
}

VLineSeries::VLineSeries(QObject* p):QLineSeries(p) {
	connect(this, &QXYSeries::hovered, this, &VLineSeries::onhovered);
}

void VLineSeries::onhovered(const QPointF& point, bool state) {
	if (state) {
		emit changecursor(Qt::SizeHorCursor);
		this->setPen(QPen(Qt::red, 2));
	}
	else {
		emit changecursor(Qt::ArrowCursor);
		this->setPen(QPen(Qt::red, 1));
	}
}