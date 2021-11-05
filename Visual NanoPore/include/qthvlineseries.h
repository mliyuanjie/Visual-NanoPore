#ifndef QTHVLINESERIES_H
#define QTHVLINESERIES_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>

QT_CHARTS_USE_NAMESPACE

class HLineSeries : public QLineSeries
{
    Q_OBJECT;
public:
    HLineSeries(QObject* parent = nullptr);

public slots:
    void onhovered(const QPointF& point, bool state);

signals:
    void changecursor(const QCursor&);
};

class VLineSeries : public QLineSeries
{
    Q_OBJECT;
public:
    VLineSeries(QObject* parent = nullptr);

public slots:
    void onhovered(const QPointF& point, bool state);

signals:
    void changecursor(const QCursor&);
};

#endif //QTHVLINESERIES_H
