#ifndef QTDATAVIEW_H
#define QTDATAVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
/*
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qareaseries.h>
#include <QtCharts/qvalueaxis.h>
*/
#include <QtCharts>
#include "nlineseries.h"

QT_CHARTS_USE_NAMESPACE

class DataView : public QChartView
{
    Q_OBJECT;
public:
    DataView(QWidget* parent);


    QLineSeries* series;
    QLineSeries* series_event;
    QLineSeries* series_event_temp;
    QLineSeries* line_1;
    QLineSeries* line_2;
    QLineSeries* line_3;
    QLineSeries* line_4;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QRubberBand* rubberBand = NULL;
    QVector<NLineSeries*> linestack;

public slots:
    //void setFilename(QString s);
    void setxscale(double, double);
    void setyscale(double, double);
    void update_data(QVector<QPointF>);
    void update_event(QVector<QPointF>);
    void update_event_temp(QVector<QPointF>);
    void zoomdata(double, double);
    void centerline();
    void changestats(QString);
signals:
    void request_data(double, double, double, double);
    void send_eventstart(QString);
    void send_eventend(QString);
    void send_eventbaseline(QString);
    void send_eventcurrent(QString);
    void mousepress(QPointF);
    void mousemove(QPointF);
    void mouserelease(QPointF);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


private:
    int stats = 0;
    int color = 0;
    bool isclick = false;
    
};

#endif //QTDATAVIEW_H