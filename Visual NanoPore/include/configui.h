/********************************************************************************
** Form generated from reading UI file 'configui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONFIGUI_H
#define CONFIGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_configDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName("configDialog");
        configDialog->resize(339, 300);
        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(90, 260, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(configDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 40, 311, 211));
        pushButton = new QPushButton(configDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 10, 75, 24));

        retranslateUi(configDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, configDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, configDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QCoreApplication::translate("configDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("configDialog", "key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("configDialog", "value", nullptr));
        pushButton->setText(QCoreApplication::translate("configDialog", "Select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONFIGUI_H
