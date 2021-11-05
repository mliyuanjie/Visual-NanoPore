#include <QtGui/QMouseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtMath>
#include <QtCore/qdebug.h>
#include <QtCore/qthread.h>
#include <QtCore/qmetatype.h>
#include "qtdataview.h"

FirstDataView::FirstDataView(QWidget* parent) :
    QChartView(parent)
{
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    series = new QLineSeries();
    series->setPen(QPen(Qt::black, 1)); 
    //series->setUseOpenGL(true);
    charts = new QtCharts::QChart();
    charts->addAxis(axisx, Qt::AlignBottom);
    charts->addAxis(axisy, Qt::AlignLeft);
    charts->addSeries(series);
    series->attachAxis(axisx);
    series->attachAxis(axisy);
    charts->legend()->hide();
    setChart(charts);
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    
}

void FirstDataView::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    rubberBand->setGeometry(QRect(p, QSize()));
    rubberBand->show();
}

void FirstDataView::mouseMoveEvent(QMouseEvent* event) {
    rubberBand->setGeometry(QRect(rubberBand->pos(), event->pos()));   
    //QPoint p = event->pos();
    //QPointF pf = mapToScene(p);
    //pf = charts->mapFromScene(pf);
    //pf = charts->mapToValue(pf);
}

void FirstDataView::mouseReleaseEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    if (event->button() == Qt::RightButton) {
        QPair<double, double> x;
        QPair<double, double> y;
        x.second = pf.x();
        y.first = pf.y();
        pf = mapToScene(rubberBand->pos());
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        x.first = pf.x();
        y.second = pf.y();
        
        if (zoomtype == 0) {
            emit request_data(x.first, x.second, true);
            axisy->setRange(y.first, y.second);
        }
        else if (zoomtype == 1) {
            emit request_data(x.first, x.second, true);
        }    
        else
            axisy->setRange(y.first, y.second);
    }
    else {
        QPair<double, double> x;
        x.second = pf.x();
        pf = mapToScene(rubberBand->pos());
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        x.first = pf.x();
        emit request_data(x.first, x.second, false);
    }
    rubberBand->hide();
}

void FirstDataView::setxscale(double x1, double x2) {
    axisx->setRange(x1, x2);
}

void FirstDataView::setselectarea(qreal x1, qreal x2) {
    if (series_select != NULL)
        charts->removeSeries(series_select);
    series_select = new QAreaSeries();
    QBrush brush = QBrush(QColor(255, 0, 0, 100));
    series_select->setBrush(brush);
    series_select->setBorderColor(QColor(255, 0, 0, 100));
    charts->addSeries(series_select);
    series_select->attachAxis(axisx);
    series_select->attachAxis(axisy);
    QLineSeries* line = new QLineSeries();
    *line << QPointF(x1, 300000) << QPointF(x2, 300000);
    series_select->setUpperSeries(line);
}


void FirstDataView::setyscale(double y1, double y2) {
    axisy->setRange(y1, y2);
    
}

void FirstDataView::update_data(QVector<QPointF> data) {
    series->replace(data);
    update();
    return;
}

void FirstDataView::changezoomtype(int a) {
    zoomtype = a;
    return;
}

void FirstDataView::update_mask(QVector<QPointF> data) {
    for (auto i : series_mask) {
        charts->removeSeries(i);
    }
    series_mask.clear();
    for (int i = 0; i < data.size(); i++) {
        QLineSeries* line = new QLineSeries();
        *line << QPointF(data[i].x(), 300000) << QPointF(data[i].y(), 300000);
        QAreaSeries* area = new QAreaSeries(line);
        QBrush brush = QBrush(QColor(0, 204, 102, 100));
        area->setBrush(brush);
        area->setBorderColor(QColor(0, 204, 102, 100));
        charts->addSeries(area);
        series_mask.push_back(area);
        charts->setAxisX(axisx, area);
        charts->setAxisY(axisy, area);
    }
    return;
}

//second graphic view
SecondDataView::SecondDataView(QWidget* parent) :
    QChartView(parent)
{
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    series = new QLineSeries();
    series_upper = new QLineSeries();
    series_down = new QLineSeries();
    series_left = new QLineSeries();
    series_right = new QLineSeries();
    series_event = new QLineSeries();
    series->setPen(QPen(Qt::darkBlue, 1));
    series_event->setPen(QPen(Qt::green, 2));
    series_upper->setPen(QPen(Qt::red, 1));
    series_down->setPen(QPen(Qt::red, 1));
    series_left->setPen(QPen(Qt::red, 1));
    series_right->setPen(QPen(Qt::red, 1));
    //series->setUseOpenGL(true);
    charts = new QtCharts::QChart();
    charts->addSeries(series);
    charts->addSeries(series_event);
    charts->addSeries(series_upper);
    charts->addSeries(series_down);
    charts->addSeries(series_left);
    charts->addSeries(series_right);
    charts->setAxisX(axisx, series);
    charts->setAxisY(axisy, series);
    charts->setAxisX(axisx, series_upper);
    charts->setAxisY(axisy, series_upper);
    charts->setAxisX(axisx, series_down);
    charts->setAxisY(axisy, series_down);
    charts->setAxisX(axisx, series_left);
    charts->setAxisY(axisy, series_left);
    charts->setAxisX(axisx, series_right);
    charts->setAxisY(axisy, series_right);
    charts->setAxisX(axisx, series_event);
    charts->setAxisY(axisy, series_event);
    charts->legend()->hide();
    setChart(charts);
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    connect(series_upper, SIGNAL(pointsReplaced()), this, SLOT(eventbaseline()));
    connect(series_down, SIGNAL(pointsReplaced()), this, SLOT(eventcurrent()));
    connect(series_left, SIGNAL(pointsReplaced()), this, SLOT(eventstart()));
    connect(series_right, SIGNAL(pointsReplaced()), this, SLOT(eventend()));

}

void SecondDataView::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    if (cursor().shape() != Qt::ArrowCursor) {
        mousestate = whichline;
    }
    else {
        mousestate = 0;
        QVector<QPointF> line_upper;
        QVector<QPointF> line_left;
        line_upper.push_back(QPointF(axisx->min(), pf.y()));
        line_upper.push_back(QPointF(axisx->max(), pf.y()));
        series_upper->replace(line_upper);
        line_left.push_back(QPointF(pf.x(), axisy->min()));
        line_left.push_back(QPointF(pf.x(), axisy->max()));
        series_left->replace(line_left); 
    }
        
}

void SecondDataView::mouseMoveEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);

    if (mousestate == 1) {
        QVector<QPointF> line;
        line.push_back(QPointF(axisx->min(), pf.y()));
        line.push_back(QPointF(axisx->max(), pf.y()));
        series_upper->replace(line);
        return;
    }
    else if (mousestate == 2) {
        QVector<QPointF> line;
        line.push_back(QPointF(axisx->min(), pf.y()));
        line.push_back(QPointF(axisx->max(), pf.y()));
        series_down->replace(line);
    }
    else if (mousestate == 3) {
        QVector<QPointF> line;
        line.push_back(QPointF(pf.x(), axisy->min()));
        line.push_back(QPointF(pf.x(), axisy->max()));
        series_left->replace(line);
    }
    else if (mousestate == 4) {
        QVector<QPointF> line;
        line.push_back(QPointF(pf.x(), axisy->min()));
        line.push_back(QPointF(pf.x(), axisy->max()));
        series_right->replace(line);
    }
    else if (mousestate == 0) {
        QVector<QPointF> line_down;
        QVector<QPointF> line_right;
        line_down.push_back(QPointF(axisx->min(), pf.y()));
        line_down.push_back(QPointF(axisx->max(), pf.y()));
        series_down->replace(line_down);
        line_right.push_back(QPointF(pf.x(), axisy->min()));
        line_right.push_back(QPointF(pf.x(), axisy->max()));
        series_right->replace(line_right);
    }
    else if(mousestate == -1)
        if (abs(pf.y() - series_upper->at(0).y()) <= 0.1) {
            this->parentWidget()->setCursor(Qt::SizeVerCursor);
            whichline = 1;
        } 
        else if (abs(pf.y() - series_down->at(0).y()) < 0.1) {
            this->parentWidget()->setCursor(Qt::SizeVerCursor);
            whichline = 2;
        }
        else if (abs(pf.x() - series_left->at(0).x()) < 0.001) {
            this->parentWidget()->setCursor(Qt::SizeHorCursor);
            whichline = 3;
        }
        else if( abs(pf.x() - series_right->at(0).x()) < 0.001) {
            this->parentWidget()->setCursor(Qt::SizeHorCursor);
            whichline = 4;
        }
        else 
            this->parentWidget()->setCursor(Qt::ArrowCursor);

}

void SecondDataView::mouseReleaseEvent(QMouseEvent* event) {
    mousestate = -1;
    this->parentWidget()->setCursor(Qt::ArrowCursor);
}

void SecondDataView::setxscale(double x1, double x2) {
    axisx->setRange(x1, x2);
}

void SecondDataView::setMin(qreal y) {
    axisy->setMin(y);
}

void SecondDataView::setMax(qreal y) {
    axisy->setMax(y);
}

void SecondDataView::update_data(QVector<QPointF> data) {
    series->replace(data);
    return;
}

void SecondDataView::update_event(QVector<QPointF> data) {
    series_event->replace(data);
    return;
}

void SecondDataView::eventbaseline() {
    emit send_eventbaseline(series_upper->at(0).y());
}

void SecondDataView::eventcurrent() {
    emit send_eventcurrent(series_down->at(0).y());
}

void SecondDataView::eventstart() {
    emit send_eventstart(series_left->at(0).x());
}

void SecondDataView::eventend() {
    emit send_eventend(series_right->at(0).x());
}