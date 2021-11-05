#ifndef CREATEVNP_H
#define CREATEVNP_H

#include <QtCore/qobject.h>
#include <QtCharts>
#include <string>
#include <QtWidgets/QDialog>
#include <unordered_map>
#include "createvnpdialog.h"

QT_CHARTS_USE_NAMESPACE

class createvnp :public QDialog
{
    Q_OBJECT
public:
    createvnp(QWidget* parent = nullptr);
    void setconfig(std::unordered_map<std::string, double>);
    std::string filepath;
public slots:
    void selectdata();

private:
    QStringList filenames;
    Ui::Dialog ui;
    std::unordered_map<std::string, double> mymap;
};



#endif // !CREATEVNP_H
