/********************************************************************************
** Form generated from reading UI file 'manualui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MANUALUI_H
#define MANUALUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtdataview.h"
#include "scaleframe.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QPushButton *pushButton_22;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox_1;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QSpinBox *spinBox;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    ScaleyFrame *frame;
    ScalexFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_20;
    QLabel *label_15;
    DataView *graphicsView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(991, 611);
        Form->setMinimumSize(QSize(991, 300));
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setMaximumSize(QSize(30, 30));
        pushButton_11->setFocusPolicy(Qt::NoFocus);
        pushButton_11->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(30, 30));
        pushButton_11->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setMaximumSize(QSize(30, 30));
        pushButton_12->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon1);
        pushButton_12->setIconSize(QSize(30, 30));
        pushButton_12->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_12);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName("pushButton_10");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setMaximumSize(QSize(30, 30));
        pushButton_10->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_10);

        pushButton_22 = new QPushButton(widget);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setMaximumSize(QSize(30, 30));
        pushButton_22->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/aim.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon3);
        pushButton_22->setIconSize(QSize(30, 30));
        pushButton_22->setCheckable(false);
        pushButton_22->setChecked(false);
        pushButton_22->setAutoRepeat(false);
        pushButton_22->setAutoExclusive(false);
        pushButton_22->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_22);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(false);
        checkBox->setFont(font);
        checkBox->setFocusPolicy(Qt::NoFocus);
        checkBox->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        horizontalLayout_2->addWidget(checkBox);

        doubleSpinBox_1 = new QDoubleSpinBox(widget);
        doubleSpinBox_1->setObjectName("doubleSpinBox_1");
        doubleSpinBox_1->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        doubleSpinBox_1->setFont(font1);
        doubleSpinBox_1->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        doubleSpinBox_1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_1->setDecimals(3);
        doubleSpinBox_1->setMaximum(10000000000000.000000000000000);
        doubleSpinBox_1->setValue(200.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        comboBox->setFont(font2);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(comboBox);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox->setFont(font2);
        doubleSpinBox->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox->setStyleSheet(QString::fromUtf8("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setMaximum(100000000000000005366162204393472.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(widget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_2->setFont(font2);
        doubleSpinBox_2->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_2->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setMaximum(989999999999999920952336632578475196506177536.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(widget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_3->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_3->setStyleSheet(QString::fromUtf8("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setMinimum(-100000000000000000.000000000000000);
        doubleSpinBox_3->setMaximum(8999999999999999910729679699914547789824.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_3);

        doubleSpinBox_4 = new QDoubleSpinBox(widget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_4->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_4->setStyleSheet(QString::fromUtf8("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_4->setMinimum(-999999999999999945575230987042816.000000000000000);
        doubleSpinBox_4->setMaximum(8999999999999999939063878597132419072.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_4);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setFont(font2);
        spinBox->setFocusPolicy(Qt::ClickFocus);
        spinBox->setStyleSheet(QString::fromUtf8("border:0 px;background: rgb(0, 0, 0);color:rgb(255, 170, 0);"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMaximum(1000000000);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(Form);
        widget_3->setObjectName("widget_3");
        QFont font3;
        font3.setBold(true);
        widget_3->setFont(font3);
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new ScaleyFrame(widget_3);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(40, 0));
        frame->setCursor(QCursor(Qt::OpenHandCursor));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-color: rgb(255, 255, 255);\n"
"border:5px;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 1, 1, 1);

        frame_2 = new ScalexFrame(widget_3);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setCursor(QCursor(Qt::OpenHandCursor));
        frame_2->setFocusPolicy(Qt::NoFocus);
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(212, 212, 212)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(90, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(33, 255, 241);\n"
"background-color: rgb(0, 0, 0);"));
        label_4->setTextFormat(Qt::PlainText);

        horizontalLayout_4->addWidget(label_4);

        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color:rgb(0, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_18->setScaledContents(false);

        horizontalLayout_4->addWidget(label_18);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");
        label_17->setMaximumSize(QSize(80, 16777215));
        label_17->setFont(font4);
        label_17->setStyleSheet(QString::fromUtf8("color:rgb(255, 85, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_17);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName("label_19");
        label_19->setFont(font4);
        label_19->setStyleSheet(QString::fromUtf8("color:rgb(255, 85, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_19);

        label_14 = new QLabel(frame_2);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(60, 16777215));
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_14);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setFont(font4);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_16);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName("label_20");
        label_20->setMaximumSize(QSize(60, 16777215));
        label_20->setFont(font4);
        label_20->setStyleSheet(QString::fromUtf8("color:rgb(255, 137, 139);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_20);

        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setFont(font4);
        label_15->setStyleSheet(QString::fromUtf8("color:rgb(255, 137, 139);\n"
"background-color: rgb(0, 0, 0);\n"
""));

        horizontalLayout_4->addWidget(label_15);


        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);

        graphicsView = new DataView(widget_3);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget_2 = new QWidget(Form);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(widget_2);


        retranslateUi(Form);
        QObject::connect(frame, SIGNAL(sendscale(double,double)), graphicsView, SLOT(setyscale(double,double)));
        QObject::connect(frame_2, SIGNAL(sendscale(double,double)), graphicsView, SLOT(zoomdata(double,double)));
        QObject::connect(graphicsView, SIGNAL(send_eventstart(QString)), label_18, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventend(QString)), label_19, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventcurrent(QString)), label_15, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventbaseline(QString)), label_16, SLOT(setText(QString)));
        QObject::connect(pushButton_22, &QPushButton::clicked, graphicsView, qOverload<>(&DataView::centerline));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), graphicsView, SLOT(linevisible(bool)));
        QObject::connect(graphicsView, SIGNAL(send_number(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), graphicsView, SLOT(set_number(int)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_10->setText(QString());
        pushButton_22->setText(QString());
        checkBox->setText(QCoreApplication::translate("Form", "Event", nullptr));
        doubleSpinBox_1->setSuffix(QCoreApplication::translate("Form", " ms", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Form", "Auto", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Form", "Half Auto", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Form", "Pick", nullptr));

        doubleSpinBox->setPrefix(QCoreApplication::translate("Form", "x0: ", nullptr));
        doubleSpinBox->setSuffix(QString());
        doubleSpinBox_2->setPrefix(QCoreApplication::translate("Form", "x1: ", nullptr));
        doubleSpinBox_2->setSuffix(QString());
        doubleSpinBox_3->setPrefix(QCoreApplication::translate("Form", "y0: ", nullptr));
        doubleSpinBox_3->setSuffix(QString());
        doubleSpinBox_4->setPrefix(QCoreApplication::translate("Form", "y1: ", nullptr));
        doubleSpinBox_4->setSuffix(QString());
        spinBox->setSuffix(QCoreApplication::translate("Form", "/0", nullptr));
        label_4->setText(QCoreApplication::translate("Form", " start(ms):", nullptr));
        label_18->setText(QCoreApplication::translate("Form", "0", nullptr));
        label_17->setText(QCoreApplication::translate("Form", "end(ms):", nullptr));
        label_19->setText(QCoreApplication::translate("Form", "0", nullptr));
        label_14->setText(QCoreApplication::translate("Form", "I0(pA):", nullptr));
        label_16->setText(QCoreApplication::translate("Form", "0", nullptr));
        label_20->setText(QCoreApplication::translate("Form", "I1(pA):", nullptr));
        label_15->setText(QCoreApplication::translate("Form", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MANUALUI_H
