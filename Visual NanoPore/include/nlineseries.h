#ifndef NLINESERIES_H
#define NLINESERIES_H

#include <QtCharts>

//QT_CHARTS_USE_NAMESPACE



class NLineSeries : public QLineSeries
{
    Q_OBJECT;
public:
    NLineSeries(QObject* parent = NULL);

public slots:
    void mousepress(QPointF);
    void mousemove(QPointF);
    void mouserelease(QPointF);

private:
    bool move_or_not = false;
};

#endif //NLINESERIES_H