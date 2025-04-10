/********************************************************************************
** Form generated from reading UI file 'configui_backup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONFIGUI_BACKUP_H
#define CONFIGUI_BACKUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
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
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *movingWindowLabel;
    QSpinBox *movingWindowSpinBox;
    QWidget *tab_2;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_6;
    QLabel *movingWindowLabel_2;
    QSpinBox *movingWindowSpinBox_2;
    QLabel *resolutionLabel;
    QSpinBox *resolutionSpinBox;
    QWidget *tab_3;
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

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName(QStringLiteral("configDialog"));
        configDialog->resize(487, 817);
        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 570, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(configDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 466, 525));
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
        font1.setItalic(true);
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
        label_4->setFont(font1);
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

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(10);
        font2.setItalic(true);
        tabWidget->setFont(font2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 10, 421, 41));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        movingWindowLabel = new QLabel(formLayoutWidget);
        movingWindowLabel->setObjectName(QStringLiteral("movingWindowLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, movingWindowLabel);

        movingWindowSpinBox = new QSpinBox(formLayoutWidget);
        movingWindowSpinBox->setObjectName(QStringLiteral("movingWindowSpinBox"));
        movingWindowSpinBox->setMaximum(1000000000);
        movingWindowSpinBox->setSingleStep(10);
        movingWindowSpinBox->setValue(2000);

        formLayout->setWidget(0, QFormLayout::FieldRole, movingWindowSpinBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayoutWidget_3 = new QWidget(tab_2);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(20, 10, 421, 71));
        formLayout_6 = new QFormLayout(formLayoutWidget_3);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(0, 0, 0, 0);
        movingWindowLabel_2 = new QLabel(formLayoutWidget_3);
        movingWindowLabel_2->setObjectName(QStringLiteral("movingWindowLabel_2"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, movingWindowLabel_2);

        movingWindowSpinBox_2 = new QSpinBox(formLayoutWidget_3);
        movingWindowSpinBox_2->setObjectName(QStringLiteral("movingWindowSpinBox_2"));
        movingWindowSpinBox_2->setMaximum(100);
        movingWindowSpinBox_2->setSingleStep(1);
        movingWindowSpinBox_2->setValue(5);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, movingWindowSpinBox_2);

        resolutionLabel = new QLabel(formLayoutWidget_3);
        resolutionLabel->setObjectName(QStringLiteral("resolutionLabel"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, resolutionLabel);

        resolutionSpinBox = new QSpinBox(formLayoutWidget_3);
        resolutionSpinBox->setObjectName(QStringLiteral("resolutionSpinBox"));
        resolutionSpinBox->setMaximum(10000);
        resolutionSpinBox->setValue(100);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, resolutionSpinBox);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
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

        formLayout_5->setWidget(3, QFormLayout::FieldRole, minWindowSpinBox);


        verticalLayout->addLayout(formLayout_5);


        retranslateUi(configDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), configDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QApplication::translate("configDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("configDialog", "Sampling rate(Hz):", Q_NULLPTR));
        label_4->setText(QApplication::translate("configDialog", "Filter (IIR-5 order)", Q_NULLPTR));
        label_5->setText(QApplication::translate("configDialog", "Low pass(Hz):", Q_NULLPTR));
        label_2->setText(QApplication::translate("configDialog", "Baseline", Q_NULLPTR));
        movingWindowLabel->setText(QApplication::translate("configDialog", "Moving window: ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("configDialog", "Moving baseline", Q_NULLPTR));
        movingWindowLabel_2->setText(QApplication::translate("configDialog", "Order:                ", Q_NULLPTR));
        resolutionLabel->setText(QApplication::translate("configDialog", "Resolution:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("configDialog", "Polynomial fit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("configDialog", "CUMSUM fit", Q_NULLPTR));
        label_6->setText(QApplication::translate("configDialog", "Event Detection", Q_NULLPTR));
        thresholdLabel->setText(QApplication::translate("configDialog", "Threshold:         ", Q_NULLPTR));
        startPointLabel->setText(QApplication::translate("configDialog", "Start point:", Q_NULLPTR));
        endPointLabel->setText(QApplication::translate("configDialog", "End point:", Q_NULLPTR));
        minWindowLabel->setText(QApplication::translate("configDialog", "Min window:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONFIGUI_BACKUP_H
