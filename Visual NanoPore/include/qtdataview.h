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
    QLineSeries* series_temp;
    QLineSeries* series_event;
    QLineSeries* series_event_temp;
    QScatterSeries* series_star;
    QLineSeries* line_1;
    QLineSeries* line_2;
    QLineSeries* line_3;
    QLineSeries* line_4;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QRubberBand* rubberBand = NULL;
    QVector<NLineSeries*> linestack;
    void changestats(QString);
public slots:
    //void setFilename(QString s);
    void setxscale(double, double);
    void setyscale(double, double);
    void zoomdata(double, double);
    void centerline();
    void linevisible(bool);
    void set_number(int);
    
signals:
    void request_data(double, double, double, double);
    void send_eventstart(QString);
    void send_eventend(QString);
    void send_eventbaseline(QString);
    void send_eventcurrent(QString);
    void send_number(int);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);


private:
    int stats = 0;
    int color = 0;
    bool isclick = false;
    int binarySearch(double i);
};

#endif //QTDATAVIEW_H