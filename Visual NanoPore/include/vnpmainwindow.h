#ifndef VNPMAINWINDOW_H
#define VNPMAINWINDOW_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QMainWindow>
#include <unordered_map>
#include "configdialog.h"
#include "mainwindow.h"
#include "manual.h"

QT_CHARTS_USE_NAMESPACE

class VNPMainWindow :public QMainWindow
{
    Q_OBJECT
public:
    VNPMainWindow(QWidget* parent = nullptr);
    std::unordered_map<std::string, double> mymap;
public slots:
    void openfile();
    //void createfile();
    void createconfig();
    //void filter(bool);
    //void tocsv();
 
signals:
    void configchange();
    void autorun();

 
private:
    Ui::MainWindow ui;
    ConfigDialog* configdialog;
    ManualPeakFind* manualtask;
    
    
};



#endif // !VNPMAINWINDOW_H

