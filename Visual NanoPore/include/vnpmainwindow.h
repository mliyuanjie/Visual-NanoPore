#ifndef VNPMAINWINDOW_H
#define VNPMAINWINDOW_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QMainWindow>
#include <unordered_map>
#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE

class VNPMainWindow :public QMainWindow
{
    Q_OBJECT
public:
    VNPMainWindow(QWidget* parent = nullptr);
    std::unordered_map<std::string, double> mymap;
public slots:
    void openfile();
    void createfile();
    void createconfig();
    void filter(bool);
    void findpeak();
    void tocsv();

 
private:
    Ui::MainWindow ui;
    
    
};



#endif // !VNPMAINWINDOW_H

