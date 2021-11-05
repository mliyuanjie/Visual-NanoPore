#include <QtGui/QMouseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QtMath>
#include <QtCore/qdebug.h>
#include <QtCore/qthread.h>
#include <QtCore/qmetatype.h>
#include "datviewwidget.h"

DATViewWidget::DATViewWidget(QWidget* p) :
    QWidget(parent)
{
    parent = p;
    Ui::DATViewUI ui;
    ui.setupUi(parent);
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    series = new QLineSeries();
    series->setPen(QPen(Qt::darkBlue, 2));
    charts = new QtCharts::QChart();
    charts->addSeries(series);
    charts->setAxisX(axisx, series);
    charts->setAxisY(axisy, series);
    charts->legend()->hide();
    chartview = parent->findChild<QChartView*>("graphicsView");
    chartview->setChart(charts);
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    rubberBand = new QRubberBand(QRubberBand::Rectangle, chartview);

    
    QPushButton* button_back = parent->findChild<QPushButton*>("pushButton_12");
    QPushButton* button_x1 = parent->findChild<QPushButton*>("pushButton_3");
    QPushButton* button_x2 = parent->findChild<QPushButton*>("pushButton_4");
    QPushButton* button_y1 = parent->findChild<QPushButton*>("pushButton_6");
    QPushButton* button_y2 = parent->findChild<QPushButton*>("pushButton_5");
    QPushButton* button_home = parent->findChild<QPushButton*>("pushButton_11");
    connect(button_home, SIGNAL(clicked()), this, SLOT(home()));
    connect(button_back, SIGNAL(clicked()), this, SLOT(back()));
    connect(button_x1, SIGNAL(clicked()), this, SLOT(x1()));
    connect(button_x2, SIGNAL(clicked()), this, SLOT(x2()));
    connect(button_y1, SIGNAL(clicked()), this, SLOT(y1()));
    connect(button_y2, SIGNAL(clicked()), this, SLOT(y2()));

    QLabel* label_current = parent->findChild<QLabel*>("label_7");
    QLabel* label_time = parent->findChild<QLabel*>("label_9");
    connect(this, SIGNAL(changecurrent(double)), label_current, SLOT(setNum(double)));
    connect(this, SIGNAL(changetime(double)), label_time, SLOT(setNum(double)));    
}

DATViewWidget::~DATViewWidget() {
    if (data != NULL)
        delete data;
    data = NULL;
}

void DATViewWidget::load(DATModel* p) {
    data = p;
    
    connect(data, SIGNAL(sendaxis(double, double, double, double)), this, SLOT(setaxis(double, double, double, double)));
    connect(data, SIGNAL(senddata(QVector<QPointF>)), this, SLOT(setdata(QVector<QPointF>)));
    connect(this, SIGNAL(getmeansd(double, double)), data, SLOT(meansd()));
    connect(this, SIGNAL(gethome()), data, SLOT(home()));
    connect(this, SIGNAL(getdata(double, double)), data, SLOT(draw(double, double)));

    QLabel* label_mean = parent->findChild<QLabel*>("label_11");
    QLabel* label_sd = parent->findChild<QLabel*>("label_13");
    connect(data, SIGNAL(sendMean(double)), label_mean, SLOT(setNum(double)));
    connect(data, SIGNAL(sendSD(double)), label_sd, SLOT(setNum(double)));  
}

void DATViewWidget::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = chartview->mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    start = pf.x();
    rubberBand->setGeometry(QRect(p, QSize()));
    rubberBand->show();
}

void DATViewWidget::mouseMoveEvent(QMouseEvent* event) {
    rubberBand->setGeometry(QRect(rubberBand->pos(), event->pos()));
    QPoint p = event->pos();
    QPointF pf = chartview->mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    emit changecurrent(pf.y());
}

void DATViewWidget::mouseReleaseEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = chartview->mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    end = pf.x();
    emit changetime(end - start);
    if (event->button() == Qt::RightButton) {
        QPair<double, double> x;
        QPair<double, double> y;
        x.second = pf.x();
        y.first = pf.y();
        pf = chartview->mapToScene(rubberBand->pos());
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        x.first = pf.x();
        y.second = pf.y();
        stx.push_back(x);
        sty.push_back(y);
        emit getdata(stx.back().first, stx.back().second);
        axisx->setRange(stx.back().first, stx.back().second);
        axisy->setRange(sty.back().first, sty.back().second);
    }
    else {
        double second = pf.x();
        pf = chartview->mapToScene(rubberBand->pos());
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        double first = pf.x();
        emit getmeansd(first, second);
    }
    rubberBand->hide();
}

void DATViewWidget::home() {
    emit gethome();
}

void DATViewWidget::back() {
    if (stx.size() <= 1)
        return;
    stx.pop_back();
    sty.pop_back();
    axisx->setRange(stx.back().first, stx.back().second);
    axisy->setRange(sty.back().first, sty.back().second);
    getdata(stx.back().first, stx.back().second);
}

void DATViewWidget::x1() {
    float range = stx.back().second - stx.back().first;
    stx.back().first = stx.back().first - 0.2 * range;
    stx.back().second = stx.back().second + 0.2 * range;
    axisx->setRange(stx.back().first, stx.back().second);
    emit getdata(stx.back().first, stx.back().second);
}

void DATViewWidget::x2() {
    float range = stx.back().second - stx.back().first;
    stx.back().first = stx.back().first + 0.2 * range;
    stx.back().second = stx.back().second - 0.2 * range;
    axisx->setRange(stx.back().first, stx.back().second);
    emit getdata(stx.back().first, stx.back().second);
}

void DATViewWidget::y1() {
    float range = sty.back().second - sty.back().first;
    sty.back().first = sty.back().first - 0.2 * range;
    sty.back().second = sty.back().second + 0.2 * range;
    axisy->setRange(sty.back().first, sty.back().second);
}

void DATViewWidget::y2() {
    float range = sty.back().second - sty.back().first;
    sty.back().first = sty.back().first + 0.2 * range;
    sty.back().second = sty.back().second - 0.2 * range;
    axisy->setRange(sty.back().first, sty.back().second);
}

void DATViewWidget::setdata(QVector<QPointF> d) {
    series->replace(d);
    return;
}

void DATViewWidget::setaxis(double a, double b, double c, double d) {
    axisx->setTitleText(QString("Time(ms)"));
    axisy->setTitleText(QString("Current(pA)"));
    stx.clear();
    sty.clear();
    stx.push_back(QPair<double, double>(a, b));
    sty.push_back(QPair<double, double>(c, d));
    axisx->setRange(a, b);
    axisy->setRange(c, d);
    emit getdata(a, b);
    return;
}
