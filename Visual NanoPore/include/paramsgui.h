/********************************************************************************
** Form generated from reading UI file 'paramsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PARAMSGUI_H
#define PARAMSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QFormLayout *formLayout;
    QLabel *baselineMethodLabel;
    QComboBox *baselineMethodComboBox;
    QLabel *moveWindowLabel;
    QSpinBox *moveWindowSpinBox;
    QLabel *orderLabel;
    QSpinBox *orderSpinBox;
    QLabel *resolutionLabel;
    QSpinBox *resolutionSpinBox;
    QLabel *stepSizeLabel;
    QSpinBox *stepSizeSpinBox;
    QLabel *hLabel;
    QSpinBox *hSpinBox;
    QLabel *label_8;
    QFormLayout *formLayout_2;
    QLabel *cSVPathLabel;
    QLineEdit *pyedit;
    QLabel *label_6;
    QFormLayout *formLayout_5;
    QLabel *thresholdLabel;
    QSpinBox *thresholdSpinBox;
    QLabel *startPointLabel;
    QSpinBox *startPointSpinBox;
    QLabel *endPointLabel;
    QSpinBox *endPointSpinBox;
    QLabel *minWindowLabel;
    QSpinBox *minWindowSpinBox;
    QLabel *directionLabel;
    QComboBox *directionComboBox;
    QLabel *parallelLabel;
    QSpinBox *parallelSpinBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *prSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *plSpinBox_2;
    QLabel *label_9;
    QDoubleSpinBox *saltSpinBox_3;
    QLabel *label_10;
    QDoubleSpinBox *voltageSpinBox_4;
    QLabel *label_11;
    QDoubleSpinBox *iminSpinBox_5;
    QLabel *label_12;
    QDoubleSpinBox *imaxSpinBox_6;
    QLabel *label_13;
    QDoubleSpinBox *sdSpinBox_7;

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName("configDialog");
        configDialog->resize(1144, 831);
        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(200, 780, 161, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(configDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 551, 752));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setItalic(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setFont(font1);
        spinBox->setMaximum(5000);
        spinBox->setValue(500);

        horizontalLayout_5->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setFont(font1);
        spinBox_2->setMaximum(5000);
        spinBox_2->setValue(50);

        horizontalLayout_3->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        baselineMethodLabel = new QLabel(verticalLayoutWidget);
        baselineMethodLabel->setObjectName("baselineMethodLabel");
        baselineMethodLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, baselineMethodLabel);

        baselineMethodComboBox = new QComboBox(verticalLayoutWidget);
        baselineMethodComboBox->addItem(QString());
        baselineMethodComboBox->addItem(QString());
        baselineMethodComboBox->addItem(QString());
        baselineMethodComboBox->setObjectName("baselineMethodComboBox");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(12);
        font3.setItalic(true);
        baselineMethodComboBox->setFont(font3);

        formLayout->setWidget(1, QFormLayout::FieldRole, baselineMethodComboBox);

        moveWindowLabel = new QLabel(verticalLayoutWidget);
        moveWindowLabel->setObjectName("moveWindowLabel");
        moveWindowLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, moveWindowLabel);

        moveWindowSpinBox = new QSpinBox(verticalLayoutWidget);
        moveWindowSpinBox->setObjectName("moveWindowSpinBox");
        moveWindowSpinBox->setFont(font);
        moveWindowSpinBox->setMaximum(1000000000);
        moveWindowSpinBox->setValue(5000);

        formLayout->setWidget(2, QFormLayout::FieldRole, moveWindowSpinBox);

        orderLabel = new QLabel(verticalLayoutWidget);
        orderLabel->setObjectName("orderLabel");
        orderLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, orderLabel);

        orderSpinBox = new QSpinBox(verticalLayoutWidget);
        orderSpinBox->setObjectName("orderSpinBox");
        orderSpinBox->setFont(font);
        orderSpinBox->setValue(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, orderSpinBox);

        resolutionLabel = new QLabel(verticalLayoutWidget);
        resolutionLabel->setObjectName("resolutionLabel");
        resolutionLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, resolutionLabel);

        resolutionSpinBox = new QSpinBox(verticalLayoutWidget);
        resolutionSpinBox->setObjectName("resolutionSpinBox");
        resolutionSpinBox->setFont(font);
        resolutionSpinBox->setMaximum(1000000000);
        resolutionSpinBox->setValue(100);

        formLayout->setWidget(4, QFormLayout::FieldRole, resolutionSpinBox);

        stepSizeLabel = new QLabel(verticalLayoutWidget);
        stepSizeLabel->setObjectName("stepSizeLabel");
        stepSizeLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, stepSizeLabel);

        stepSizeSpinBox = new QSpinBox(verticalLayoutWidget);
        stepSizeSpinBox->setObjectName("stepSizeSpinBox");
        stepSizeSpinBox->setFont(font);
        stepSizeSpinBox->setValue(6);

        formLayout->setWidget(5, QFormLayout::FieldRole, stepSizeSpinBox);

        hLabel = new QLabel(verticalLayoutWidget);
        hLabel->setObjectName("hLabel");
        hLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, hLabel);

        hSpinBox = new QSpinBox(verticalLayoutWidget);
        hSpinBox->setObjectName("hSpinBox");
        hSpinBox->setFont(font);
        hSpinBox->setValue(6);

        formLayout->setWidget(6, QFormLayout::FieldRole, hSpinBox);


        verticalLayout->addLayout(formLayout);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        cSVPathLabel = new QLabel(verticalLayoutWidget);
        cSVPathLabel->setObjectName("cSVPathLabel");
        cSVPathLabel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, cSVPathLabel);

        pyedit = new QLineEdit(verticalLayoutWidget);
        pyedit->setObjectName("pyedit");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setItalic(false);
        pyedit->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pyedit);


        verticalLayout->addLayout(formLayout_2);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        thresholdLabel = new QLabel(verticalLayoutWidget);
        thresholdLabel->setObjectName("thresholdLabel");
        thresholdLabel->setFont(font1);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, thresholdLabel);

        thresholdSpinBox = new QSpinBox(verticalLayoutWidget);
        thresholdSpinBox->setObjectName("thresholdSpinBox");
        thresholdSpinBox->setFont(font1);
        thresholdSpinBox->setValue(5);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, thresholdSpinBox);

        startPointLabel = new QLabel(verticalLayoutWidget);
        startPointLabel->setObjectName("startPointLabel");
        startPointLabel->setFont(font1);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, startPointLabel);

        startPointSpinBox = new QSpinBox(verticalLayoutWidget);
        startPointSpinBox->setObjectName("startPointSpinBox");
        startPointSpinBox->setFont(font1);
        startPointSpinBox->setMaximum(1000000000);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, startPointSpinBox);

        endPointLabel = new QLabel(verticalLayoutWidget);
        endPointLabel->setObjectName("endPointLabel");
        endPointLabel->setFont(font1);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, endPointLabel);

        endPointSpinBox = new QSpinBox(verticalLayoutWidget);
        endPointSpinBox->setObjectName("endPointSpinBox");
        endPointSpinBox->setFont(font1);
        endPointSpinBox->setMaximum(1000000000);
        endPointSpinBox->setValue(10000000);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, endPointSpinBox);

        minWindowLabel = new QLabel(verticalLayoutWidget);
        minWindowLabel->setObjectName("minWindowLabel");
        minWindowLabel->setFont(font1);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, minWindowLabel);

        minWindowSpinBox = new QSpinBox(verticalLayoutWidget);
        minWindowSpinBox->setObjectName("minWindowSpinBox");
        minWindowSpinBox->setFont(font1);
        minWindowSpinBox->setMaximum(1000000000);
        minWindowSpinBox->setValue(5);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, minWindowSpinBox);

        directionLabel = new QLabel(verticalLayoutWidget);
        directionLabel->setObjectName("directionLabel");
        directionLabel->setFont(font);

        formLayout_5->setWidget(4, QFormLayout::LabelRole, directionLabel);

        directionComboBox = new QComboBox(verticalLayoutWidget);
        directionComboBox->addItem(QString());
        directionComboBox->addItem(QString());
        directionComboBox->setObjectName("directionComboBox");
        directionComboBox->setFont(font);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, directionComboBox);

        parallelLabel = new QLabel(verticalLayoutWidget);
        parallelLabel->setObjectName("parallelLabel");
        parallelLabel->setFont(font);

        formLayout_5->setWidget(5, QFormLayout::LabelRole, parallelLabel);

        parallelSpinBox = new QSpinBox(verticalLayoutWidget);
        parallelSpinBox->setObjectName("parallelSpinBox");
        parallelSpinBox->setFont(font);
        parallelSpinBox->setMinimum(1);
        parallelSpinBox->setValue(1);

        formLayout_5->setWidget(5, QFormLayout::FieldRole, parallelSpinBox);


        verticalLayout->addLayout(formLayout_5);

        verticalLayoutWidget_2 = new QWidget(configDialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(600, 20, 481, 751));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");
        QFont font5;
        font5.setPointSize(12);
        label_2->setFont(font5);
        label_2->setLayoutDirection(Qt::LeftToRight);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        prSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        prSpinBox->setObjectName("prSpinBox");
        prSpinBox->setFont(font5);
        prSpinBox->setAlignment(Qt::AlignCenter);
        prSpinBox->setDecimals(1);
        prSpinBox->setValue(10.000000000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, prSpinBox);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font5);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_3);

        plSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget_2);
        plSpinBox_2->setObjectName("plSpinBox_2");
        plSpinBox_2->setFont(font5);
        plSpinBox_2->setAlignment(Qt::AlignCenter);
        plSpinBox_2->setDecimals(1);
        plSpinBox_2->setValue(30.000000000000000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, plSpinBox_2);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setFont(font5);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_9);

        saltSpinBox_3 = new QDoubleSpinBox(verticalLayoutWidget_2);
        saltSpinBox_3->setObjectName("saltSpinBox_3");
        saltSpinBox_3->setFont(font5);
        saltSpinBox_3->setAlignment(Qt::AlignCenter);
        saltSpinBox_3->setDecimals(3);
        saltSpinBox_3->setValue(0.046000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, saltSpinBox_3);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setFont(font5);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_10);

        voltageSpinBox_4 = new QDoubleSpinBox(verticalLayoutWidget_2);
        voltageSpinBox_4->setObjectName("voltageSpinBox_4");
        voltageSpinBox_4->setFont(font5);
        voltageSpinBox_4->setAlignment(Qt::AlignCenter);
        voltageSpinBox_4->setValue(0.100000000000000);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, voltageSpinBox_4);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setFont(font5);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_11);

        iminSpinBox_5 = new QDoubleSpinBox(verticalLayoutWidget_2);
        iminSpinBox_5->setObjectName("iminSpinBox_5");
        iminSpinBox_5->setFont(font5);
        iminSpinBox_5->setAlignment(Qt::AlignCenter);
        iminSpinBox_5->setDecimals(0);
        iminSpinBox_5->setValue(5.000000000000000);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, iminSpinBox_5);

        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName("label_12");
        label_12->setFont(font5);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_12);

        imaxSpinBox_6 = new QDoubleSpinBox(verticalLayoutWidget_2);
        imaxSpinBox_6->setObjectName("imaxSpinBox_6");
        imaxSpinBox_6->setFont(font5);
        imaxSpinBox_6->setAlignment(Qt::AlignCenter);
        imaxSpinBox_6->setDecimals(0);
        imaxSpinBox_6->setValue(95.000000000000000);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, imaxSpinBox_6);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName("label_13");
        label_13->setFont(font5);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_13);

        sdSpinBox_7 = new QDoubleSpinBox(verticalLayoutWidget_2);
        sdSpinBox_7->setObjectName("sdSpinBox_7");
        sdSpinBox_7->setFont(font5);
        sdSpinBox_7->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, sdSpinBox_7);


        verticalLayout_2->addLayout(formLayout_3);


        retranslateUi(configDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, configDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, configDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QCoreApplication::translate("configDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("configDialog", "Sampling rate(kHz):", nullptr));
        label_4->setText(QCoreApplication::translate("configDialog", "Filter (IIR-5 order)", nullptr));
        label_5->setText(QCoreApplication::translate("configDialog", "Low pass(kHz):", nullptr));
        label_7->setText(QCoreApplication::translate("configDialog", "Baseline", nullptr));
        baselineMethodLabel->setText(QCoreApplication::translate("configDialog", "Baseline method:", nullptr));
        baselineMethodComboBox->setItemText(0, QCoreApplication::translate("configDialog", "Moving average", nullptr));
        baselineMethodComboBox->setItemText(1, QCoreApplication::translate("configDialog", "Moving median", nullptr));
        baselineMethodComboBox->setItemText(2, QCoreApplication::translate("configDialog", "Local Baseline", nullptr));

        moveWindowLabel->setText(QCoreApplication::translate("configDialog", "Move window:", nullptr));
        orderLabel->setText(QCoreApplication::translate("configDialog", "Order:", nullptr));
        resolutionLabel->setText(QCoreApplication::translate("configDialog", "Resolution:", nullptr));
        stepSizeLabel->setText(QCoreApplication::translate("configDialog", "Step size:", nullptr));
        hLabel->setText(QCoreApplication::translate("configDialog", "h:", nullptr));
        label_8->setText(QCoreApplication::translate("configDialog", "External File", nullptr));
        cSVPathLabel->setText(QCoreApplication::translate("configDialog", "Python Path:", nullptr));
        pyedit->setText(QCoreApplication::translate("configDialog", "C:/Users/LiYu/Anaconda3/lib;C:/Users/LiYu/Anaconda3/DLLs", nullptr));
        label_6->setText(QCoreApplication::translate("configDialog", "Event Detection (Block event detection)", nullptr));
        thresholdLabel->setText(QCoreApplication::translate("configDialog", "Threshold:         ", nullptr));
        startPointLabel->setText(QCoreApplication::translate("configDialog", "Start point:", nullptr));
        endPointLabel->setText(QCoreApplication::translate("configDialog", "End point:", nullptr));
        minWindowLabel->setText(QCoreApplication::translate("configDialog", "Min window:", nullptr));
        directionLabel->setText(QCoreApplication::translate("configDialog", "Direction:", nullptr));
        directionComboBox->setItemText(0, QCoreApplication::translate("configDialog", "Negative", nullptr));
        directionComboBox->setItemText(1, QCoreApplication::translate("configDialog", "Positive", nullptr));

        parallelLabel->setText(QCoreApplication::translate("configDialog", "Parallel:", nullptr));
        label_2->setText(QCoreApplication::translate("configDialog", "Pore Radius(nm):", nullptr));
        label_3->setText(QCoreApplication::translate("configDialog", "Pore Length(nm): ", nullptr));
        label_9->setText(QCoreApplication::translate("configDialog", "Salt(om): ", nullptr));
        label_10->setText(QCoreApplication::translate("configDialog", "Voltage(V): ", nullptr));
        label_11->setText(QCoreApplication::translate("configDialog", "Imin(%):", nullptr));
        label_12->setText(QCoreApplication::translate("configDialog", "Imax(%): ", nullptr));
        label_13->setText(QCoreApplication::translate("configDialog", "SD(pA):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PARAMSGUI_H
