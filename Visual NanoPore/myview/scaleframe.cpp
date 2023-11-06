#include "qtdataview.h"
#include "scaleframe.h" 

ScaleyFrame::ScaleyFrame(QWidget* parent) :QFrame(parent) {
}

void ScaleyFrame::mousePressEvent(QMouseEvent* event) {
	p = event->pos(); 
	setCursor(Qt::ClosedHandCursor);
}

void ScaleyFrame::mouseReleaseEvent(QMouseEvent* event) {
	setCursor(Qt::OpenHandCursor);
	QPoint pnew = event->pos();
	DataView* dataview = parent()->findChild<DataView*>("graphicsView");
	p = dataview->mapFromParent(mapToParent(p));
	QPointF pf = dataview->mapToScene(p);
	pf = dataview->charts->mapFromScene(pf);
	pf = dataview->charts->mapToValue(pf);

	pnew = dataview->mapFromParent(mapToParent(pnew));
	QPointF pfnew = dataview->mapToScene(pnew);
	pfnew = dataview->charts->mapFromScene(pfnew);
	pfnew = dataview->charts->mapToValue(pfnew);

	if (pf.y() > pfnew.y())
		emit sendscale(pfnew.y(), pf.y());
	else {
		double delta = (pfnew.y() - pf.y());
		emit sendscale(dataview->axisy->min() - delta, dataview->axisy->max() + delta);
	}

}

ScalexFrame::ScalexFrame(QWidget* parent) :QFrame(parent) {
}

void ScalexFrame::mousePressEvent(QMouseEvent* event) {
	p = event->pos();
	setCursor(Qt::ClosedHandCursor);
}

void ScalexFrame::mouseReleaseEvent(QMouseEvent* event) {
	setCursor(Qt::OpenHandCursor);
	QPoint pnew = event->pos();
	DataView* dataview = parent()->findChild<DataView*>("graphicsView");
	p = dataview->mapFromParent(mapToParent(p));
	QPointF pf = dataview->mapToScene(p);
	pf = dataview->charts->mapFromScene(pf);
	pf = dataview->charts->mapToValue(pf);

	pnew = dataview->mapFromParent(mapToParent(pnew));
	QPointF pfnew = dataview->mapToScene(pnew);
	pfnew = dataview->charts->mapFromScene(pfnew);
	pfnew = dataview->charts->mapToValue(pfnew);

	if (pf.x() < pfnew.x())
		emit sendscale(pf.x(), pfnew.x());
	else {
		double delta = (pfnew.x() - pf.x());
		emit sendscale(dataview->axisx->min() + delta, dataview->axisx->max() - delta);
	}

}

