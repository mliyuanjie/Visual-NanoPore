/********************************************************************************
** Form generated from reading UI file 'pythonui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PYTHONUI_H
#define PYTHONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "consolelinedit.h"

QT_BEGIN_NAMESPACE

class Ui_PythonForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    ConsoleLinEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QWidget *PythonForm)
    {
        if (PythonForm->objectName().isEmpty())
            PythonForm->setObjectName(QStringLiteral("PythonForm"));
        PythonForm->resize(749, 490);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PythonForm->sizePolicy().hasHeightForWidth());
        PythonForm->setSizePolicy(sizePolicy);
        PythonForm->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        PythonForm->setFont(font);
        verticalLayout_2 = new QVBoxLayout(PythonForm);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(PythonForm);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        textBrowser->setFont(font1);
        textBrowser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textBrowser->setFocusPolicy(Qt::NoFocus);
        textBrowser->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0);color:rgb(0, 255, 0)"));
        textBrowser->setLineWrapMode(QTextEdit::WidgetWidth);

        verticalLayout_2->addWidget(textBrowser);

        lineEdit = new ConsoleLinEdit(PythonForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 40));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setFocusPolicy(Qt::StrongFocus);
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 127);"));
        lineEdit->setMaxLength(32767);

        verticalLayout_2->addWidget(lineEdit);

        comboBox = new QComboBox(PythonForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setMaximumSize(QSize(16777215, 30));
        comboBox->setFont(font);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 255);\n"
""));
        comboBox->setMaxVisibleItems(5);
        comboBox->setInsertPolicy(QComboBox::InsertAtCurrent);
        comboBox->setIconSize(QSize(0, 0));

        verticalLayout_2->addWidget(comboBox);


        retranslateUi(PythonForm);
        QObject::connect(comboBox, SIGNAL(highlighted(QString)), lineEdit, SLOT(setText(QString)));

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PythonForm);
    } // setupUi

    void retranslateUi(QWidget *PythonForm)
    {
        PythonForm->setWindowTitle(QApplication::translate("PythonForm", "Form", Q_NULLPTR));
        textBrowser->setDocumentTitle(QApplication::translate("PythonForm", "Python", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("PythonForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Python</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PythonForm: public Ui_PythonForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PYTHONUI_H
