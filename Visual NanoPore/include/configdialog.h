#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QDialog>
#include "tools.h"
#include "configui.h"

QT_CHARTS_USE_NAMESPACE

class ConfigDialog :public QDialog
{
    Q_OBJECT
public:
    ConfigDialog(QWidget* parent = nullptr);
public slots:
    void selectfile();

private:
    Ui::configDialog ui;
};



#endif // !CONFIGDIALOG_H
