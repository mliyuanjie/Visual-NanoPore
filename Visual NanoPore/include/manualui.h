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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QDoubleSpinBox *doubleSpinBox_2;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_21;
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
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(991, 611);
        Form->setMinimumSize(QSize(991, 300));
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMaximumSize(QSize(30, 30));
        pushButton_11->setFocusPolicy(Qt::NoFocus);
        pushButton_11->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(30, 30));
        pushButton_11->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMaximumSize(QSize(30, 30));
        pushButton_12->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon1);
        pushButton_12->setIconSize(QSize(30, 30));
        pushButton_12->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_12);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setMaximumSize(QSize(30, 30));
        pushButton_10->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_10);

        pushButton_22 = new QPushButton(widget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setMaximumSize(QSize(30, 30));
        pushButton_22->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/aim.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon3);
        pushButton_22->setIconSize(QSize(30, 30));
        pushButton_22->setCheckable(false);
        pushButton_22->setChecked(false);
        pushButton_22->setAutoRepeat(false);
        pushButton_22->setAutoExclusive(false);
        pushButton_22->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_22);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        checkBox->setFont(font);
        checkBox->setFocusPolicy(Qt::NoFocus);
        checkBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        horizontalLayout_2->addWidget(checkBox);

        doubleSpinBox_2 = new QDoubleSpinBox(widget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        doubleSpinBox_2->setFont(font1);
        doubleSpinBox_2->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMaximum(1e+13);
        doubleSpinBox_2->setValue(200);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        comboBox->setFont(font2);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(comboBox);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox->setFont(font2);
        doubleSpinBox->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox->setStyleSheet(QLatin1String("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setMaximum(1e+32);

        horizontalLayout_2->addWidget(doubleSpinBox);

        doubleSpinBox_21 = new QDoubleSpinBox(widget);
        doubleSpinBox_21->setObjectName(QStringLiteral("doubleSpinBox_21"));
        doubleSpinBox_21->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_21->setFont(font2);
        doubleSpinBox_21->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_21->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_21->setStyleSheet(QLatin1String("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_21->setMaximum(9.9e+44);

        horizontalLayout_2->addWidget(doubleSpinBox_21);

        doubleSpinBox_3 = new QDoubleSpinBox(widget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_3->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_3->setStyleSheet(QLatin1String("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setMinimum(-1e+17);
        doubleSpinBox_3->setMaximum(9e+39);

        horizontalLayout_2->addWidget(doubleSpinBox_3);

        doubleSpinBox_4 = new QDoubleSpinBox(widget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximumSize(QSize(16777215, 30));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox_4->setFocusPolicy(Qt::ClickFocus);
        doubleSpinBox_4->setStyleSheet(QLatin1String("border:0 px;background: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_4->setMinimum(-1e+33);
        doubleSpinBox_4->setMaximum(9e+36);

        horizontalLayout_2->addWidget(doubleSpinBox_4);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setFont(font2);
        spinBox->setFocusPolicy(Qt::ClickFocus);
        spinBox->setStyleSheet(QStringLiteral("border:0 px;background: rgb(0, 0, 0);color:rgb(255, 170, 0);"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMaximum(1000000000);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(Form);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        widget_3->setFont(font3);
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new ScaleyFrame(widget_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(40, 0));
        frame->setCursor(QCursor(Qt::OpenHandCursor));
        frame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-color: rgb(255, 255, 255);\n"
"border:5px;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 1, 1, 1);

        frame_2 = new ScalexFrame(widget_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setCursor(QCursor(Qt::OpenHandCursor));
        frame_2->setFocusPolicy(Qt::NoFocus);
        frame_2->setStyleSheet(QStringLiteral("background-color:rgb(212, 212, 212)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(90, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_4->setStyleSheet(QLatin1String("color: rgb(33, 255, 241);\n"
"background-color: rgb(0, 0, 0);"));
        label_4->setTextFormat(Qt::PlainText);

        horizontalLayout_4->addWidget(label_4);

        label_18 = new QLabel(frame_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font4);
        label_18->setStyleSheet(QLatin1String("color:rgb(0, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_18->setScaledContents(false);

        horizontalLayout_4->addWidget(label_18);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(80, 16777215));
        label_17->setFont(font4);
        label_17->setStyleSheet(QLatin1String("color:rgb(255, 85, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_17);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font4);
        label_19->setStyleSheet(QLatin1String("color:rgb(255, 85, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_19);

        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(60, 16777215));
        label_14->setFont(font4);
        label_14->setStyleSheet(QLatin1String("color: rgb(255, 170, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_14);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font4);
        label_16->setStyleSheet(QLatin1String("color: rgb(255, 170, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_16);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(60, 16777215));
        label_20->setFont(font4);
        label_20->setStyleSheet(QLatin1String("color:rgb(255, 137, 139);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_20);

        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font4);
        label_15->setStyleSheet(QLatin1String("color:rgb(255, 137, 139);\n"
"background-color: rgb(0, 0, 0);\n"
""));

        horizontalLayout_4->addWidget(label_15);


        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);

        graphicsView = new DataView(widget_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget_2 = new QWidget(Form);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(widget_2);


        retranslateUi(Form);
        QObject::connect(frame, SIGNAL(sendscale(double,double)), graphicsView, SLOT(setyscale(double,double)));
        QObject::connect(frame_2, SIGNAL(sendscale(double,double)), graphicsView, SLOT(zoomdata(double,double)));
        QObject::connect(graphicsView, SIGNAL(send_eventstart(QString)), label_18, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventend(QString)), label_19, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventcurrent(QString)), label_15, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(send_eventbaseline(QString)), label_16, SLOT(setText(QString)));
        QObject::connect(pushButton_22, SIGNAL(clicked()), graphicsView, SLOT(centerline()));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), graphicsView, SLOT(linevisible(bool)));
        QObject::connect(graphicsView, SIGNAL(send_number(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), graphicsView, SLOT(set_number(int)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_10->setText(QString());
        pushButton_22->setText(QString());
        checkBox->setText(QApplication::translate("Form", "Event", Q_NULLPTR));
        doubleSpinBox_2->setSuffix(QApplication::translate("Form", " ms", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "Auto", Q_NULLPTR)
         << QApplication::translate("Form", "Half Auto", Q_NULLPTR)
         << QApplication::translate("Form", "Pick", Q_NULLPTR)
        );
        doubleSpinBox->setPrefix(QApplication::translate("Form", "x0: ", Q_NULLPTR));
        doubleSpinBox->setSuffix(QString());
        doubleSpinBox_21->setPrefix(QApplication::translate("Form", "x1: ", Q_NULLPTR));
        doubleSpinBox_21->setSuffix(QString());
        doubleSpinBox_3->setPrefix(QApplication::translate("Form", "y0: ", Q_NULLPTR));
        doubleSpinBox_3->setSuffix(QString());
        doubleSpinBox_4->setPrefix(QApplication::translate("Form", "y1: ", Q_NULLPTR));
        doubleSpinBox_4->setSuffix(QString());
        spinBox->setSuffix(QApplication::translate("Form", "/0", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", " start(ms):", Q_NULLPTR));
        label_18->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("Form", "end(ms):", Q_NULLPTR));
        label_19->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_14->setText(QApplication::translate("Form", "I0(pA):", Q_NULLPTR));
        label_16->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        label_20->setText(QApplication::translate("Form", "I1(pA):", Q_NULLPTR));
        label_15->setText(QApplication::translate("Form", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MANUALUI_H
