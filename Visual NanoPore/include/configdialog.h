#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QDialog>
#include "tools.h"
#include "paramsgui.h"

QT_CHARTS_USE_NAMESPACE

class ConfigDialog :public QDialog
{
    Q_OBJECT
public:
    ConfigDialog(QWidget* parent = nullptr);
public slots:
    void selectfile();
    void changebm(const QString& name);

private:
    Ui::configDialog ui;
    QLabel* hLabel;
    QLabel* moveWindowLabel;
    QLabel* orderLabel;
    QLabel* resolutionLabel;
    QLabel* stepSizeLabel;
    QSpinBox* hSpinBox;
    QSpinBox* moveWindowSpinBox;
    QSpinBox* orderSpinBox;
    QSpinBox* resolutionSpinBox;
    QSpinBox* stepSizeSpinBox;
};



#endif // !CONFIGDIALOG_H
