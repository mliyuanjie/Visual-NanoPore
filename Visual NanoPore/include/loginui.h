/********************************************************************************
** Form generated from reading UI file 'loginui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINUI_H
#define LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(386, 255);
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 30, 251, 41));
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 90, 251, 41));
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 101, 31));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 101, 41));
        label_2->setFont(font);
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 160, 91, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setUnderline(true);
        label_3->setFont(font1);
        pushButton = new QPushButton(login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 200, 93, 31));
        QFont font2;
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(280, 200, 93, 31));
        pushButton_2->setFont(font2);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QCoreApplication::translate("login", "User Name:", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-size:14pt; color:#0055ff;\">register</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("login", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINUI_H
