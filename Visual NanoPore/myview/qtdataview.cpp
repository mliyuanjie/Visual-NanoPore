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

DataView::DataView(QWidget* parent) :
    QChartView(parent)
{
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    series = new QLineSeries();
    series->setPen(QPen(Qt::black, 1)); 
    series_event = new QLineSeries();
    series_event->setPen(QPen(Qt::green, 2));

    line_1 = new QLineSeries();
    line_1->setPen(QPen(QColor(0, 255, 255), 2, Qt::DotLine));
    line_2 = new QLineSeries();
    line_2->setPen(QPen(QColor(170, 170, 255), 2, Qt::DotLine));
    line_3 = new QLineSeries();
    line_3->setPen(QPen(QColor(255, 170, 255), 2, Qt::DotLine));
    line_4 = new QLineSeries();
    line_4->setPen(QPen(QColor(255, 255, 0), 2, Qt::DotLine));
    *line_1 << QPointF(0, 0) << QPointF(0, 0);
    *line_2 << QPointF(0, 0) << QPointF(0, 0);
    *line_3 << QPointF(0, 0) << QPointF(0, 0);
    *line_4 << QPointF(0, 0) << QPointF(0, 0);
    //series->setUseOpenGL(true);
    charts = new QtCharts::QChart();
    charts->addAxis(axisx, Qt::AlignBottom);
    charts->addAxis(axisy, Qt::AlignLeft);
    charts->addSeries(series);
    charts->addSeries(series_event);
    charts->addSeries(line_1);
    charts->addSeries(line_2);
    charts->addSeries(line_3);
    charts->addSeries(line_4);
    series->attachAxis(axisx);
    series->attachAxis(axisy);
    series_event->attachAxis(axisx);
    series_event->attachAxis(axisy);
    line_1->attachAxis(axisx);
    line_1->attachAxis(axisy);
    line_2->attachAxis(axisx);
    line_2->attachAxis(axisy);
    line_3->attachAxis(axisx);
    line_3->attachAxis(axisy);
    line_4->attachAxis(axisx);
    line_4->attachAxis(axisy);

    charts->legend()->hide();
    setChart(charts);
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
}

void DataView::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    
    if (event->button() == Qt::LeftButton) {
        color = -1 * color;
        emit mousepress(pf);
        return;
    }  
    rubberBand->setGeometry(QRect(p, QSize()));
    rubberBand->show();
    isclick = true;
}

void DataView::centerline() {
    QVector<QPointF> line;
    line.push_back(QPointF(axisx->min(), axisy->min()+0.6*(axisy->max()-axisy->min())));
    line.push_back(QPointF(axisx->max(), axisy->min() + 0.6 * (axisy->max() - axisy->min())));
    line_3->replace(line);
    line.clear();
    line.push_back(QPointF(axisx->min(), axisy->min() + 0.3 * (axisy->max() - axisy->min())));
    line.push_back(QPointF(axisx->max(), axisy->min() + 0.3 * (axisy->max() - axisy->min())));
    line_4->replace(line);
    line.clear();
    line.push_back(QPointF(axisx->min() + 0.6 * (axisx->max() - axisx->min()), axisy->min()));
    line.push_back(QPointF(axisx->min() + 0.6 * (axisx->max() - axisx->min()), axisy->max()));
    line_2->replace(line);
    line.clear();
    line.push_back(QPointF(axisx->min() + 0.3 * (axisx->max() - axisx->min()), axisy->min()));
    line.push_back(QPointF(axisx->min() + 0.3 * (axisx->max() - axisx->min()), axisy->max()));
    line_1->replace(line);

    emit send_eventbaseline(QString::number(line_4->at(0).y(), 'g', 12));
    emit send_eventcurrent(QString::number(line_3->at(0).y(), 'g', 12));
    emit send_eventstart(QString::number(line_1->at(0).x(), 'g', 12));
    emit send_eventend(QString::number(line_2->at(0).x(), 'g', 12));
}

void DataView::mouseMoveEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    emit mousemove(pf);
    rubberBand->setGeometry(QRect(rubberBand->pos(), event->pos())); 
    if (isclick)
        return;
    if (color <= 0) {
        
        QPointF pf1 = charts->mapToPosition(QPointF(line_1->at(0).x(), line_3->at(0).y()));
        QPointF pf2 = charts->mapToPosition(QPointF(line_2->at(0).x(), line_4->at(0).y()));
        pf1 = charts->mapToScene(pf1);
        pf2 = charts->mapToScene(pf2);
        QPoint p1 = mapFromScene(pf1);
        QPoint p2 = mapFromScene(pf2);
        int distance1 = abs(p.x() - p1.x());
        int distance2 = abs(p.x() - p2.x());
        int distance3 = abs(p.y() - p1.y());
        int distance4 = abs(p.y() - p2.y());
        if (distance1 < 10) {
            this->setCursor(Qt::SplitHCursor);
            color = -1;
        }
        else if (distance2 < 10) {
            this->setCursor(Qt::SplitHCursor);
            color = -2;
        }
        else if (distance3 < 10) {
            this->setCursor(Qt::SplitVCursor);
            color = -3;
        }
        else if (distance4 < 10) {
            this->setCursor(Qt::SplitVCursor);
            color = -4;
        }
        else {
            this->setCursor(Qt::ArrowCursor);
            color = 0;
        }
    }
    else if (color == 3) {
        QVector<QPointF> line;
        line.push_back(QPointF(axisx->min(), pf.y()));
        line.push_back(QPointF(axisx->max(), pf.y()));
        line_3->replace(line);
        emit send_eventcurrent(QString::number(pf.y(), 'g', 12));
        return;
    }
    else if (color == 4) {
        QVector<QPointF> line;
        line.push_back(QPointF(axisx->min(), pf.y()));
        line.push_back(QPointF(axisx->max(), pf.y()));
        line_4->replace(line);
        emit send_eventbaseline(QString::number(pf.y(), 'g', 12));
        return;
    }
    else if (color == 2) {
        QVector<QPointF> line;
        line.push_back(QPointF(pf.x(), axisy->min()));
        line.push_back(QPointF(pf.x(), axisy->max()));
        line_2->replace(line);
        emit send_eventend(QString::number(pf.x(), 'g', 12));
    }
    else if (color == 1) {
        QVector<QPointF> line;
        line.push_back(QPointF(pf.x(), axisy->min()));
        line.push_back(QPointF(pf.x(), axisy->max()));
        line_1->replace(line);
        emit send_eventstart(QString::number(pf.x(), 'g', 12));
    }
}

void DataView::mouseReleaseEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    emit mouserelease(pf);
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
        emit request_data(x.first, x.second, y.first, y.second); 
    }
    rubberBand->hide();
    color = 0;
    isclick = false;
}

void DataView::setxscale(double x1, double x2) {
    axisx->setRange(x1, x2);   
    QVector<QPointF> line;
    line.push_back(QPointF(axisx->min(), line_3->at(0).y()));
    line.push_back(QPointF(axisx->max(), line_3->at(1).y()));
    line_3->replace(line);
    line.clear();
    line.push_back(QPointF(axisx->min(), line_4->at(0).y()));
    line.push_back(QPointF(axisx->max(), line_4->at(1).y()));
    line_4->replace(line);
}

void DataView::zoomdata(double x1, double x2) {
    request_data(x1, x2, axisy->min(), axisy->max());
}


void DataView::setyscale(double y1, double y2) {
    axisy->setRange(y1, y2);   
    QVector<QPointF> line;
    line.push_back(QPointF(line_1->at(0).x(), axisy->min()));
    line.push_back(QPointF(line_1->at(1).x(), axisy->max()));
    line_1->replace(line);
    line.clear();
    line.push_back(QPointF(line_2->at(0).x(), axisy->min()));
    line.push_back(QPointF(line_2->at(1).x(), axisy->max()));
    line_2->replace(line);
}

void DataView::update_data(QVector<QPointF> data) {
    series->replace(data);
    return;
}

void DataView::update_event(QVector<QPointF> data) {
    series_event->replace(data);
    return;
}

/**
void DataView::update_done(QVector<QPointF> data) {
    for (auto i : series_done) {
        charts->removeSeries(i);
    }
    series_done.clear();
    for (int i = 0; i < data.size(); i++) {
        QLineSeries* line = new QLineSeries();
        *line << QPointF(data[i].x(), 300000) << QPointF(data[i].y(), 300000);
        QAreaSeries* area = new QAreaSeries(line);
        QBrush brush = QBrush(QColor(224, 224, 224, 100));
        area->setBrush(brush);
        area->setBorderColor(QColor(224, 224, 224, 100));
        charts->addSeries(area);
        series_done.push_back(area);
        charts->setAxisX(axisx, area);
        charts->setAxisY(axisy, area);
    }
    return;
}
**/

void DataView::update_done(QVector<QPointF> data) {
    for (auto i : linestack) {
        charts->removeSeries(i);
    }
    linestack.clear();
    for (int i = 0; i < data.size(); i++) {
        NLineSeries* line = new NLineSeries();
        *line << QPointF(data[i].x(), 0.5 * (axisy->max() + axisy->min()));
        *line << QPointF(data[i].y(), 0.5 * (axisy->max() + axisy->min()));
        charts->addSeries(line);
        linestack.push_back(line);
        charts->setAxisX(axisx, line);
        charts->setAxisY(axisy, line);
        connect(this, SIGNAL(mousepress(QPointF)), line, SLOT(mousepress(QPointF)));
        connect(this, SIGNAL(mousemove(QPointF)), line, SLOT(mousemove(QPointF)));
        connect(this, SIGNAL(mouserelease(QPointF)), line, SLOT(mouserelease(QPointF)));
    }
    return;
}