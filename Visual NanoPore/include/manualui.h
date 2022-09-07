/********************************************************************************
** Form generated from reading UI file 'manualui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MANUALUI_H
#define MANUALUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qtdataview.h"
#include "scaleframe.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    DataView *graphicsView;
    QLabel *label;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_22;
    ScaleyFrame *frame;
    ScalexFrame *frame_2;
    QLabel *label_20;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_4;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_15;
    QPushButton *pushButton_17;
    QPushButton *pushButton_19;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_23;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1501, 834);
        Form->setMinimumSize(QSize(1462, 834));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 20, 71, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit_2->setFont(font);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 10, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);
        pushButton_11 = new QPushButton(Form);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 10, 40, 40));
        pushButton_11->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(40, 40));
        pushButton_11->setFlat(true);
        pushButton_12 = new QPushButton(Form);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(80, 10, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon2);
        pushButton_12->setIconSize(QSize(40, 40));
        pushButton_12->setFlat(true);
        graphicsView = new DataView(Form);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 60, 1471, 751));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 20, 31, 31));
        label->setFont(font);
        pushButton_10 = new QPushButton(Form);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(370, 20, 30, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/cc-arrow-right-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon3);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);
        pushButton_13 = new QPushButton(Form);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(330, 20, 30, 30));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/cc-arrow-left-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(30, 30));
        pushButton_13->setFlat(true);
        pushButton_22 = new QPushButton(Form);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(430, 10, 40, 40));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/Zoom-In.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_22->setIcon(icon5);
        pushButton_22->setIconSize(QSize(40, 40));
        pushButton_22->setCheckable(true);
        pushButton_22->setChecked(false);
        pushButton_22->setAutoRepeat(false);
        pushButton_22->setAutoExclusive(false);
        pushButton_22->setFlat(true);
        frame = new ScaleyFrame(Form);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1470, 0, 31, 831));
        frame->setCursor(QCursor(Qt::OpenHandCursor));
        frame->setStyleSheet(QStringLiteral("background-color:rgb(17, 230, 184)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new ScalexFrame(Form);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 800, 1471, 31));
        frame_2->setCursor(QCursor(Qt::OpenHandCursor));
        frame_2->setStyleSheet(QStringLiteral("background-color:rgb(17, 230, 184)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(Form);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1180, 10, 121, 21));
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral("color:rgb(255, 170, 255)"));
        label_14 = new QLabel(Form);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1320, 10, 131, 21));
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0)"));
        label_16 = new QLabel(Form);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1320, 30, 141, 20));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0)"));
        label_17 = new QLabel(Form);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1030, 10, 101, 21));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color:rgb(170, 170, 255)"));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(890, 10, 111, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255)"));
        label_4->setTextFormat(Qt::PlainText);
        label_18 = new QLabel(Form);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(890, 30, 131, 20));
        label_18->setFont(font);
        label_18->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255)"));
        label_18->setScaledContents(false);
        label_19 = new QLabel(Form);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1030, 30, 121, 20));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color:rgb(170, 170, 255)"));
        label_15 = new QLabel(Form);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1180, 30, 131, 20));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color:rgb(255, 170, 255)"));
        pushButton_17 = new QPushButton(Form);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(820, 10, 40, 51));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon6);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_17->setFlat(true);
        pushButton_19 = new QPushButton(Form);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(750, 10, 40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/delete_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon7);
        pushButton_19->setIconSize(QSize(40, 40));
        pushButton_19->setFlat(true);
        pushButton_8 = new QPushButton(Form);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(680, 10, 40, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/add_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setIconSize(QSize(40, 40));
        pushButton_8->setFlat(true);
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(570, 20, 31, 31));
        label_2->setFont(font);
        lineEdit_3 = new QLineEdit(Form);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(490, 20, 71, 31));
        lineEdit_3->setFont(font);
        pushButton_23 = new QPushButton(Form);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(620, 10, 40, 40));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon9);
        pushButton_23->setIconSize(QSize(40, 40));
        pushButton_23->setCheckable(true);
        pushButton_23->setChecked(false);
        pushButton_23->setAutoRepeat(false);
        pushButton_23->setAutoExclusive(false);
        pushButton_23->setFlat(true);
        graphicsView->raise();
        lineEdit_2->raise();
        pushButton->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        label->raise();
        pushButton_10->raise();
        pushButton_13->raise();
        pushButton_22->raise();
        frame->raise();
        frame_2->raise();
        label_20->raise();
        label_14->raise();
        label_16->raise();
        label_17->raise();
        label_4->raise();
        label_18->raise();
        label_19->raise();
        label_15->raise();
        pushButton_17->raise();
        pushButton_19->raise();
        pushButton_8->raise();
        label_2->raise();
        lineEdit_3->raise();
        pushButton_23->raise();

        retranslateUi(Form);
        QObject::connect(frame, SIGNAL(sendscale(double,double)), graphicsView, SLOT(setyscale(double,double)));
        QObject::connect(frame_2, SIGNAL(sendscale(double,double)), graphicsView, SLOT(zoomdata(double,double)));
        QObject::connect(graphicsView, SIGNAL(send_eventstart(QString)), label_18, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventend(QString)), label_19, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventcurrent(QString)), label_15, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventbaseline(QString)), label_16, SLOT(setText(QString)));
        QObject::connect(pushButton_22, SIGNAL(clicked(bool)), graphicsView, SLOT(centerline(bool)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Form", "200", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        label->setText(QApplication::translate("Form", "ms", Q_NULLPTR));
        pushButton_10->setText(QString());
        pushButton_13->setText(QString());
        pushButton_22->setText(QString());
        label_20->setText(QApplication::translate("Form", "mean(pA)", Q_NULLPTR));
        label_14->setText(QApplication::translate("Form", "Baseline(pA)", Q_NULLPTR));
        label_16->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("Form", "end(ms)", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "start(ms)", Q_NULLPTR));
        label_18->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_19->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_15->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        pushButton_17->setText(QString());
        pushButton_19->setText(QString());
        pushButton_8->setText(QString());
        label_2->setText(QApplication::translate("Form", "pA", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("Form", "300", Q_NULLPTR));
        pushButton_23->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MANUALUI_H
