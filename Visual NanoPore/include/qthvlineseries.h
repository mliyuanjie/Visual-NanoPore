#ifndef QTHVLINESERIES_H
#define QTHVLINESERIES_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>

QT_CHARTS_USE_NAMESPACE

class HVLineSeries : public QLineSeries
{
    Q_OBJECT;
public:
    HVLineSeries(QObject* parent = nullptr) :QLineSeries(parent) {};
    int color;

public slots:
    void onhovered(QPointF, bool);

signals:
    void changecursor(QCursor);
};



#endif //QTHVLINESERIES_H
