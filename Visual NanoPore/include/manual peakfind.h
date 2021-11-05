/********************************************************************************
** Form generated from reading UI file 'manual peakfind.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MANUAL_20_PEAKFIND_H
#define MANUAL_20_PEAKFIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qtdataview.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    FirstDataView *graphicsView;
    QLabel *label;
    QPushButton *pushButton_15;
    SecondDataView *graphicsView_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_16;
    QPushButton *pushButton_19;
    QPushButton *pushButton_8;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_4;
    QPushButton *pushButton_17;
    QComboBox *comboBox;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1462, 871);
        Form->setMinimumSize(QSize(1462, 871));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(530, 20, 71, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit_2->setFont(font);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 10, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);
        pushButton_11 = new QPushButton(Form);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 10, 40, 40));
        pushButton_11->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(40, 40));
        pushButton_11->setFlat(true);
        pushButton_12 = new QPushButton(Form);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(50, 10, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon2);
        pushButton_12->setIconSize(QSize(40, 40));
        pushButton_12->setFlat(true);
        graphicsView = new FirstDataView(Form);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 1431, 381));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(610, 20, 31, 31));
        label->setFont(font);
        pushButton_15 = new QPushButton(Form);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(190, 10, 40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/findpeak.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon3);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_15->setFlat(true);
        graphicsView_2 = new SecondDataView(Form);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 440, 1431, 411));
        pushButton_10 = new QPushButton(Form);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(680, 20, 30, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/cc-arrow-right-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon4);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);
        pushButton_13 = new QPushButton(Form);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(640, 20, 30, 30));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/cc-arrow-left-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon5);
        pushButton_13->setIconSize(QSize(30, 30));
        pushButton_13->setFlat(true);
        pushButton_16 = new QPushButton(Form);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(140, 10, 40, 40));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon6);
        pushButton_16->setIconSize(QSize(40, 40));
        pushButton_16->setCheckable(true);
        pushButton_16->setFlat(true);
        pushButton_19 = new QPushButton(Form);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(340, 10, 40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/delete_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon7);
        pushButton_19->setIconSize(QSize(40, 40));
        pushButton_19->setFlat(true);
        pushButton_8 = new QPushButton(Form);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(290, 10, 40, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/add_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setIconSize(QSize(40, 40));
        pushButton_8->setFlat(true);
        pushButton_22 = new QPushButton(Form);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(400, 10, 40, 40));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon9);
        pushButton_22->setIconSize(QSize(40, 40));
        pushButton_22->setFlat(true);
        pushButton_23 = new QPushButton(Form);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(450, 10, 40, 40));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon10);
        pushButton_23->setIconSize(QSize(40, 40));
        pushButton_23->setFlat(true);
        label_14 = new QLabel(Form);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1310, 10, 131, 21));
        label_14->setFont(font);
        label_15 = new QLabel(Form);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1170, 30, 141, 20));
        label_15->setFont(font);
        label_16 = new QLabel(Form);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1310, 30, 151, 20));
        label_16->setFont(font);
        label_17 = new QLabel(Form);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1040, 10, 101, 21));
        label_17->setFont(font);
        label_18 = new QLabel(Form);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(900, 30, 131, 20));
        label_18->setFont(font);
        label_19 = new QLabel(Form);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1040, 30, 121, 20));
        label_19->setFont(font);
        label_20 = new QLabel(Form);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1170, 10, 121, 21));
        label_20->setFont(font);
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(900, 10, 111, 21));
        label_4->setFont(font);
        pushButton_17 = new QPushButton(Form);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(240, 10, 40, 40));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon11);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_17->setFlat(true);
        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(750, 20, 73, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        comboBox->setFont(font1);
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(140, -10, 3, 61));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Form);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(280, -10, 3, 61));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Form);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(500, -10, 3, 61));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Form);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(860, -10, 3, 61));
        line_4->setLineWidth(3);
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        retranslateUi(Form);
        QObject::connect(graphicsView_2, SIGNAL(send_eventstart(double)), label_18, SLOT(setNum(double)));
        QObject::connect(graphicsView_2, SIGNAL(send_eventend(double)), label_19, SLOT(setNum(double)));
        QObject::connect(graphicsView_2, SIGNAL(send_eventcurrent(double)), label_15, SLOT(setNum(double)));
        QObject::connect(graphicsView_2, SIGNAL(send_eventbaseline(double)), label_16, SLOT(setNum(double)));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), graphicsView, SLOT(changezoomtype(int)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Form", "1000", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        label->setText(QApplication::translate("Form", "ms", Q_NULLPTR));
        pushButton_15->setText(QString());
        pushButton_10->setText(QString());
        pushButton_13->setText(QString());
        pushButton_16->setText(QString());
        pushButton_19->setText(QString());
        pushButton_8->setText(QString());
        pushButton_22->setText(QString());
        pushButton_23->setText(QString());
        label_14->setText(QApplication::translate("Form", "Baseline(pA)", Q_NULLPTR));
        label_15->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_16->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("Form", "end(ms)", Q_NULLPTR));
        label_18->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_19->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_20->setText(QApplication::translate("Form", "mean(pA)", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "start(ms)", Q_NULLPTR));
        pushButton_17->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "XY", Q_NULLPTR)
         << QApplication::translate("Form", "X", Q_NULLPTR)
         << QApplication::translate("Form", "Y", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MANUAL_20_PEAKFIND_H
