/********************************************************************************
** Form generated from reading UI file 'createvnpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEVNPDIALOG_H
#define CREATEVNPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
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
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(476, 294);
        select = new QDialogButtonBox(Dialog);
        select->setObjectName(QStringLiteral("select"));
        select->setGeometry(QRect(30, 240, 431, 32));
        select->setOrientation(Qt::Horizontal);
        select->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 251, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 71, 31));
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 30, 41, 31));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 71, 31));
        label_3->setFont(font);
        listWidget = new QListWidget(Dialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(90, 80, 371, 151));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 30, 81, 32));

        retranslateUi(Dialog);
        QObject::connect(select, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(select, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Dialog", "new", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", ".vnp", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Data List:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "Select", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEVNPDIALOG_H
