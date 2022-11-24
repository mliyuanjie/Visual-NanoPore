#ifndef VNPMAINWINDOW_H
#define VNPMAINWINDOW_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QMainWindow>
#include <unordered_map>
#include "mainwindow.h"
#include "vnpcontroller.h"

QT_CHARTS_USE_NAMESPACE

class VNPMainWindow :public QMainWindow
{
    Q_OBJECT;
public:
    VNPMainWindow(QWidget* parent = nullptr);

 
public slots:
    void pythonvisible(bool);
    void datavisible(bool);

private:
    Ui::MainWindow ui;
   
    VNPController* controller;
    
    
};



#endif // !VNPMAINWINDOW_H

