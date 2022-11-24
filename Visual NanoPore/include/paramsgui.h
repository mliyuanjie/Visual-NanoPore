/********************************************************************************
** Form generated from reading UI file 'paramsgui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PARAMSGUI_H
#define PARAMSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName(QStringLiteral("configDialog"));
        configDialog->resize(574, 918);
        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(200, 780, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(configDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 551, 752));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setItalic(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setFont(font1);
        spinBox->setMaximum(5000);
        spinBox->setValue(500);

        horizontalLayout_5->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setFont(font1);
        spinBox_2->setMaximum(5000);
        spinBox_2->setValue(50);

        horizontalLayout_3->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        baselineMethodLabel = new QLabel(verticalLayoutWidget);
        baselineMethodLabel->setObjectName(QStringLiteral("baselineMethodLabel"));
        baselineMethodLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, baselineMethodLabel);

        baselineMethodComboBox = new QComboBox(verticalLayoutWidget);
        baselineMethodComboBox->setObjectName(QStringLiteral("baselineMethodComboBox"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(12);
        font3.setItalic(true);
        baselineMethodComboBox->setFont(font3);

        formLayout->setWidget(1, QFormLayout::FieldRole, baselineMethodComboBox);

        moveWindowLabel = new QLabel(verticalLayoutWidget);
        moveWindowLabel->setObjectName(QStringLiteral("moveWindowLabel"));
        moveWindowLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, moveWindowLabel);

        moveWindowSpinBox = new QSpinBox(verticalLayoutWidget);
        moveWindowSpinBox->setObjectName(QStringLiteral("moveWindowSpinBox"));
        moveWindowSpinBox->setFont(font);
        moveWindowSpinBox->setMaximum(1000000000);
        moveWindowSpinBox->setValue(5000);

        formLayout->setWidget(2, QFormLayout::FieldRole, moveWindowSpinBox);

        orderLabel = new QLabel(verticalLayoutWidget);
        orderLabel->setObjectName(QStringLiteral("orderLabel"));
        orderLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, orderLabel);

        orderSpinBox = new QSpinBox(verticalLayoutWidget);
        orderSpinBox->setObjectName(QStringLiteral("orderSpinBox"));
        orderSpinBox->setFont(font);
        orderSpinBox->setValue(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, orderSpinBox);

        resolutionLabel = new QLabel(verticalLayoutWidget);
        resolutionLabel->setObjectName(QStringLiteral("resolutionLabel"));
        resolutionLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, resolutionLabel);

        resolutionSpinBox = new QSpinBox(verticalLayoutWidget);
        resolutionSpinBox->setObjectName(QStringLiteral("resolutionSpinBox"));
        resolutionSpinBox->setFont(font);
        resolutionSpinBox->setMaximum(1000000000);
        resolutionSpinBox->setValue(100);

        formLayout->setWidget(4, QFormLayout::FieldRole, resolutionSpinBox);

        stepSizeLabel = new QLabel(verticalLayoutWidget);
        stepSizeLabel->setObjectName(QStringLiteral("stepSizeLabel"));
        stepSizeLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, stepSizeLabel);

        stepSizeSpinBox = new QSpinBox(verticalLayoutWidget);
        stepSizeSpinBox->setObjectName(QStringLiteral("stepSizeSpinBox"));
        stepSizeSpinBox->setFont(font);
        stepSizeSpinBox->setValue(6);

        formLayout->setWidget(5, QFormLayout::FieldRole, stepSizeSpinBox);

        hLabel = new QLabel(verticalLayoutWidget);
        hLabel->setObjectName(QStringLiteral("hLabel"));
        hLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, hLabel);

        hSpinBox = new QSpinBox(verticalLayoutWidget);
        hSpinBox->setObjectName(QStringLiteral("hSpinBox"));
        hSpinBox->setFont(font);
        hSpinBox->setValue(6);

        formLayout->setWidget(6, QFormLayout::FieldRole, hSpinBox);


        verticalLayout->addLayout(formLayout);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        cSVPathLabel = new QLabel(verticalLayoutWidget);
        cSVPathLabel->setObjectName(QStringLiteral("cSVPathLabel"));
        cSVPathLabel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, cSVPathLabel);

        pyedit = new QLineEdit(verticalLayoutWidget);
        pyedit->setObjectName(QStringLiteral("pyedit"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        font4.setItalic(false);
        pyedit->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pyedit);


        verticalLayout->addLayout(formLayout_2);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        thresholdLabel = new QLabel(verticalLayoutWidget);
        thresholdLabel->setObjectName(QStringLiteral("thresholdLabel"));
        thresholdLabel->setFont(font1);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, thresholdLabel);

        thresholdSpinBox = new QSpinBox(verticalLayoutWidget);
        thresholdSpinBox->setObjectName(QStringLiteral("thresholdSpinBox"));
        thresholdSpinBox->setFont(font1);
        thresholdSpinBox->setValue(5);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, thresholdSpinBox);

        startPointLabel = new QLabel(verticalLayoutWidget);
        startPointLabel->setObjectName(QStringLiteral("startPointLabel"));
        startPointLabel->setFont(font1);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, startPointLabel);

        startPointSpinBox = new QSpinBox(verticalLayoutWidget);
        startPointSpinBox->setObjectName(QStringLiteral("startPointSpinBox"));
        startPointSpinBox->setFont(font1);
        startPointSpinBox->setMaximum(1000000000);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, startPointSpinBox);

        endPointLabel = new QLabel(verticalLayoutWidget);
        endPointLabel->setObjectName(QStringLiteral("endPointLabel"));
        endPointLabel->setFont(font1);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, endPointLabel);

        endPointSpinBox = new QSpinBox(verticalLayoutWidget);
        endPointSpinBox->setObjectName(QStringLiteral("endPointSpinBox"));
        endPointSpinBox->setFont(font1);
        endPointSpinBox->setMaximum(1000000000);
        endPointSpinBox->setValue(10000000);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, endPointSpinBox);

        minWindowLabel = new QLabel(verticalLayoutWidget);
        minWindowLabel->setObjectName(QStringLiteral("minWindowLabel"));
        minWindowLabel->setFont(font1);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, minWindowLabel);

        minWindowSpinBox = new QSpinBox(verticalLayoutWidget);
        minWindowSpinBox->setObjectName(QStringLiteral("minWindowSpinBox"));
        minWindowSpinBox->setFont(font1);
        minWindowSpinBox->setMaximum(1000000000);
        minWindowSpinBox->setValue(5);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, minWindowSpinBox);

        directionLabel = new QLabel(verticalLayoutWidget);
        directionLabel->setObjectName(QStringLiteral("directionLabel"));
        directionLabel->setFont(font);

        formLayout_5->setWidget(4, QFormLayout::LabelRole, directionLabel);

        directionComboBox = new QComboBox(verticalLayoutWidget);
        directionComboBox->setObjectName(QStringLiteral("directionComboBox"));
        directionComboBox->setFont(font);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, directionComboBox);


        verticalLayout->addLayout(formLayout_5);


        retranslateUi(configDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), configDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QApplication::translate("configDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("configDialog", "Sampling rate(kHz):", Q_NULLPTR));
        label_4->setText(QApplication::translate("configDialog", "Filter (IIR-5 order)", Q_NULLPTR));
        label_5->setText(QApplication::translate("configDialog", "Low pass(kHz):", Q_NULLPTR));
        label_7->setText(QApplication::translate("configDialog", "Baseline", Q_NULLPTR));
        baselineMethodLabel->setText(QApplication::translate("configDialog", "Baseline method:", Q_NULLPTR));
        baselineMethodComboBox->clear();
        baselineMethodComboBox->insertItems(0, QStringList()
         << QApplication::translate("configDialog", "Moving average", Q_NULLPTR)
         << QApplication::translate("configDialog", "Moving median", Q_NULLPTR)
         << QApplication::translate("configDialog", "Self Adapt", Q_NULLPTR)
         << QApplication::translate("configDialog", "Polynomial fit", Q_NULLPTR)
         << QApplication::translate("configDialog", "CUMSUM fit", Q_NULLPTR)
        );
        moveWindowLabel->setText(QApplication::translate("configDialog", "Move window:", Q_NULLPTR));
        orderLabel->setText(QApplication::translate("configDialog", "Order:", Q_NULLPTR));
        resolutionLabel->setText(QApplication::translate("configDialog", "Resolution:", Q_NULLPTR));
        stepSizeLabel->setText(QApplication::translate("configDialog", "Step size:", Q_NULLPTR));
        hLabel->setText(QApplication::translate("configDialog", "h:", Q_NULLPTR));
        label_8->setText(QApplication::translate("configDialog", "External File", Q_NULLPTR));
        cSVPathLabel->setText(QApplication::translate("configDialog", "Python Path:", Q_NULLPTR));
        pyedit->setText(QApplication::translate("configDialog", "C:/Users/LiYu/Anaconda3;C:/Users/LiYu/Anaconda3/Scripts;C:/Users/LiYu/Anaconda3/lib;C:/Users/LiYu/Anaconda3/DLLs", Q_NULLPTR));
        label_6->setText(QApplication::translate("configDialog", "Event Detection (Block event detection)", Q_NULLPTR));
        thresholdLabel->setText(QApplication::translate("configDialog", "Threshold:         ", Q_NULLPTR));
        startPointLabel->setText(QApplication::translate("configDialog", "Start point:", Q_NULLPTR));
        endPointLabel->setText(QApplication::translate("configDialog", "End point:", Q_NULLPTR));
        minWindowLabel->setText(QApplication::translate("configDialog", "Min window:", Q_NULLPTR));
        directionLabel->setText(QApplication::translate("configDialog", "Direction:", Q_NULLPTR));
        directionComboBox->clear();
        directionComboBox->insertItems(0, QStringList()
         << QApplication::translate("configDialog", "Negative", Q_NULLPTR)
         << QApplication::translate("configDialog", "Positive", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PARAMSGUI_H
