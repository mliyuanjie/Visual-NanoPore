#ifndef LOGIN_H
#define LOGIN_H


#include <QtCharts>
#include "loginui.h"


QT_CHARTS_USE_NAMESPACE

class Login :public QDialog
{
    Q_OBJECT
public:
    Login(QWidget* parent = nullptr);
public slots:
    void check();
private:
    Ui::login ui;


};

#endif // !LOGIN_H
