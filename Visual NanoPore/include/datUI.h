/********************************************************************************
** Form generated from reading UI file 'datUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DATUI_H
#define DATUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_DATViewUI
{
public:
    QChartView *graphicsView;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *DATViewUI)
    {
        if (DATViewUI->objectName().isEmpty())
            DATViewUI->setObjectName(QStringLiteral("DATViewUI"));
        DATViewUI->resize(1029, 530);
        graphicsView = new QChartView(DATViewUI);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 50, 991, 451));
        pushButton_11 = new QPushButton(DATViewUI);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(40, 10, 40, 40));
        pushButton_11->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral("../resources/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(40, 40));
        pushButton_11->setFlat(true);
        pushButton_12 = new QPushButton(DATViewUI);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(90, 10, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon1);
        pushButton_12->setIconSize(QSize(40, 40));
        pushButton_12->setFlat(true);
        label_3 = new QLabel(DATViewUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 20, 91, 21));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_7 = new QLabel(DATViewUI);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 21, 55, 20));
        label_7->setFont(font);
        label_8 = new QLabel(DATViewUI);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(580, 20, 51, 21));
        label_8->setFont(font);
        label_9 = new QLabel(DATViewUI);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(640, 21, 55, 20));
        label_9->setFont(font);
        label_10 = new QLabel(DATViewUI);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(730, 20, 81, 21));
        label_10->setFont(font);
        label_11 = new QLabel(DATViewUI);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(810, 21, 55, 20));
        label_11->setFont(font);
        label_12 = new QLabel(DATViewUI);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(900, 20, 61, 21));
        label_12->setFont(font);
        label_13 = new QLabel(DATViewUI);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(960, 21, 55, 20));
        label_13->setFont(font);
        pushButton_5 = new QPushButton(DATViewUI);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(true);
        pushButton_5->setGeometry(QRect(0, 230, 30, 30));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(30, 30));
        pushButton_5->setMaximumSize(QSize(30, 30));
        pushButton_5->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resources/cc-arrow-up-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(30, 30));
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(DATViewUI);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 270, 30, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(30, 30));
        pushButton_6->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../resources/cc-arrow-down-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(30, 30));
        pushButton_6->setFlat(true);
        pushButton_4 = new QPushButton(DATViewUI);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(530, 500, 30, 30));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        QIcon icon4;
        icon4.addFile(QStringLiteral("../resources/cc-arrow-right-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(30, 30));
        pushButton_4->setFlat(true);
        pushButton_3 = new QPushButton(DATViewUI);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 500, 30, 30));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        QIcon icon5;
        icon5.addFile(QStringLiteral("../resources/cc-arrow-left-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setIconSize(QSize(30, 30));
        pushButton_3->setFlat(true);
        pushButton = new QPushButton(DATViewUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 10, 40, 40));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../resources/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon6);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(DATViewUI);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 10, 40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../resources/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon7);
        pushButton_2->setIconSize(QSize(40, 40));
        pushButton_2->setFlat(true);
        pushButton_7 = new QPushButton(DATViewUI);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(190, 10, 40, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../resources/Zoom-In.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon8);
        pushButton_7->setIconSize(QSize(40, 40));
        pushButton_7->setFlat(true);
        doubleSpinBox = new QDoubleSpinBox(DATViewUI);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(690, 500, 101, 31));
        doubleSpinBox->setFont(font);

        retranslateUi(DATViewUI);

        QMetaObject::connectSlotsByName(DATViewUI);
    } // setupUi

    void retranslateUi(QWidget *DATViewUI)
    {
        DATViewUI->setWindowTitle(QApplication::translate("DATViewUI", "DATView", Q_NULLPTR));
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        label_3->setText(QApplication::translate("DATViewUI", "Current pA:", Q_NULLPTR));
        label_7->setText(QApplication::translate("DATViewUI", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("DATViewUI", "dt ms:", Q_NULLPTR));
        label_9->setText(QApplication::translate("DATViewUI", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("DATViewUI", "mean pA:", Q_NULLPTR));
        label_11->setText(QApplication::translate("DATViewUI", "0", Q_NULLPTR));
        label_12->setText(QApplication::translate("DATViewUI", "sd pA:", Q_NULLPTR));
        label_13->setText(QApplication::translate("DATViewUI", "0", Q_NULLPTR));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DATViewUI: public Ui_DATViewUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATUI_H
