#ifndef SCALEFRAME_H
#define SCALEFRAME_H

#include <QtWidgets>



class ScalexFrame : public QFrame
{
    Q_OBJECT;
public:
    ScalexFrame(QWidget* parent = NULL);

signals:
    void sendscale(double, double);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QPoint p;
};

class ScaleyFrame : public QFrame
{
    Q_OBJECT;
public:
    ScaleyFrame(QWidget* parent = NULL);

signals:
    void sendscale(double, double);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QPoint p;
};

#endif //HVLINEWIDGET_H
