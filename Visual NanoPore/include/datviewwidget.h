#ifndef DATVIEWWIDGET_H
#define DATVIEWWIDGET_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>
#include "datUI.h"
#include "datmodel.h"

QT_CHARTS_USE_NAMESPACE

class DATViewWidget : public QWidget
{
    Q_OBJECT;
public:
    DATViewWidget(QWidget* p);
    ~DATViewWidget();
    void load(DATModel* p);
    void filter(float cutoff);
    void saveas(QString fn);
    void cutbytime(int start, int end);


public slots:
    //void setFilename(QString s);
    void setaxis(double, double, double, double);
    void back();
    void home();
    void x1();
    void x2();
    void y1();
    void y2();
    void setdata(QVector<QPointF>);

signals:
    void changetime(double);
    void changecurrent(double);
    void getdata(double s, double e);
    void gethome();
    void getmeansd(double, double);


protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QLineSeries* series;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QChartView* chartview;
    QRubberBand* rubberBand = NULL;
    DATModel* data = NULL;
    QWidget* parent = NULL;
    double start = 0;
    double end = 0;
    std::vector<QPair<double, double>> stx;
    std::vector<QPair<double, double>> sty;

};
#endif //DATVIEWWIDGET_H
