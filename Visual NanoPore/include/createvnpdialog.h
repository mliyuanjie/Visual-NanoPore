/********************************************************************************
** Form generated from reading UI file 'createvnpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEVNPDIALOG_H
#define CREATEVNPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *select;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(476, 294);
        select = new QDialogButtonBox(Dialog);
        select->setObjectName("select");
        select->setGeometry(QRect(30, 240, 431, 32));
        select->setOrientation(Qt::Horizontal);
        select->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 30, 251, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 71, 31));
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 30, 41, 31));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 70, 71, 31));
        label_3->setFont(font);
        listWidget = new QListWidget(Dialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(90, 80, 371, 151));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 30, 81, 32));

        retranslateUi(Dialog);
        QObject::connect(select, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(select, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEdit->setText(QCoreApplication::translate("Dialog", "new", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", ".vnp", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Data List:", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEVNPDIALOG_H
