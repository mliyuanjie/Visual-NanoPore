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

QT_CHARTS_USE_NAMESPACE

class FirstDataView : public QChartView
{
    Q_OBJECT;
public:
    FirstDataView(QWidget* parent);


    QLineSeries* series;
    QList<QAreaSeries*> series_mask;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QAreaSeries* series_select = NULL;
    QRubberBand* rubberBand = NULL;
    bool isclick;
    int zoomtype = 0;

public slots:
    //void setFilename(QString s);
    void setxscale(double, double);
    void setyscale(double, double);
    void update_data(QVector<QPointF>);
    void update_mask(QVector<QPointF>);
    void setselectarea(qreal, qreal);
    void changezoomtype(int);


signals:
    void request_data(double s, double e, bool mainview);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    
};
class SecondDataView : public QChartView
{
    Q_OBJECT;
public:
    SecondDataView(QWidget* parent);


    QLineSeries* series;
    QLineSeries* series_event;
    QLineSeries* series_upper;
    QLineSeries* series_down;
    QLineSeries* series_left;
    QLineSeries* series_right;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    int mousestate = -2;
    int whichline = 0;

public slots:
    //void setFilename(QString s);
    void setxscale(double, double);
    void setMin(qreal);
    void setMax(qreal);
    void update_data(QVector<QPointF>);
    void update_event(QVector<QPointF>);
    void eventbaseline();
    void eventcurrent();
    void eventstart();
    void eventend();

signals:
    void send_eventstart(double);
    void send_eventend(double);
    void send_eventbaseline(double);
    void send_eventcurrent(double);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


    
};

#endif //QTDATAVIEW_H