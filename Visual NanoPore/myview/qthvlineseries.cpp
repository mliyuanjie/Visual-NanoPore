#include "qthvlineseries.h" 

void HVLineSeries::onhovered(QPointF point, bool state) {
	if (state && (color == 0 || color == 1)) {
		emit changecursor(Qt::SizeHorCursor);
	}
	else if (state && (color == 2 || color == 3)) {
		emit changecursor(Qt::SizeVerCursor);
	}
	else {
		emit changecursor(Qt::ArrowCursor);
	}
	return;
}
