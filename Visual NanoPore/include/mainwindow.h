/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "manual.h"
#include "vnptreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionparameter;
    QAction *actionstart_python;
    QAction *actionauto_run;
    QAction *actionstop_auto;
    QAction *actionfilter;
    QAction *actionfind_peak;
    QAction *actioncommand;
    QAction *actionfilebrowsers;
    QAction *actionload_csv;
    QAction *actionload_dat;
    QAction *actionsave_to_csv;
    QAction *actioninsert_event;
    QAction *actionremove_event;
    QAction *actionshow_plot;
    QAction *actioncopy_data;
    QAction *actionestimation;
    QAction *actionestimation2;
    QAction *actionfilter_save;
    QAction *actionshow_Imin_Imax;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar;
    ManualPeakFind *widget_2;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuPython;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    VNPTreeWidget *treeWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1326, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName("actionopen");
        actionopen->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon);
        actionparameter = new QAction(MainWindow);
        actionparameter->setObjectName("actionparameter");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionparameter->setIcon(icon1);
        actionstart_python = new QAction(MainWindow);
        actionstart_python->setObjectName("actionstart_python");
        actionstart_python->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/python.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstart_python->setIcon(icon2);
        actionauto_run = new QAction(MainWindow);
        actionauto_run->setObjectName("actionauto_run");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/autorun.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionauto_run->setIcon(icon3);
        actionstop_auto = new QAction(MainWindow);
        actionstop_auto->setObjectName("actionstop_auto");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstop_auto->setIcon(icon4);
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName("actionfilter");
        actionfilter->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfilter->setIcon(icon5);
        actionfind_peak = new QAction(MainWindow);
        actionfind_peak->setObjectName("actionfind_peak");
        actionfind_peak->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfind_peak->setIcon(icon6);
        actioncommand = new QAction(MainWindow);
        actioncommand->setObjectName("actioncommand");
        actionfilebrowsers = new QAction(MainWindow);
        actionfilebrowsers->setObjectName("actionfilebrowsers");
        actionfilebrowsers->setCheckable(true);
        actionload_csv = new QAction(MainWindow);
        actionload_csv->setObjectName("actionload_csv");
        actionload_csv->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/loadcsvfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_csv->setIcon(icon7);
        actionload_dat = new QAction(MainWindow);
        actionload_dat->setObjectName("actionload_dat");
        actionload_dat->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/loaddatfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_dat->setIcon(icon8);
        actionsave_to_csv = new QAction(MainWindow);
        actionsave_to_csv->setObjectName("actionsave_to_csv");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave_to_csv->setIcon(icon9);
        actioninsert_event = new QAction(MainWindow);
        actioninsert_event->setObjectName("actioninsert_event");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/add_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioninsert_event->setIcon(icon10);
        actionremove_event = new QAction(MainWindow);
        actionremove_event->setObjectName("actionremove_event");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/delete_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionremove_event->setIcon(icon11);
        actionshow_plot = new QAction(MainWindow);
        actionshow_plot->setObjectName("actionshow_plot");
        actionshow_plot->setCheckable(true);
        actioncopy_data = new QAction(MainWindow);
        actioncopy_data->setObjectName("actioncopy_data");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/duplicate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy_data->setIcon(icon12);
        actionestimation = new QAction(MainWindow);
        actionestimation->setObjectName("actionestimation");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/circuit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionestimation->setIcon(icon13);
        actionestimation2 = new QAction(MainWindow);
        actionestimation2->setObjectName("actionestimation2");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionestimation2->setIcon(icon14);
        actionfilter_save = new QAction(MainWindow);
        actionfilter_save->setObjectName("actionfilter_save");
        actionshow_Imin_Imax = new QAction(MainWindow);
        actionshow_Imin_Imax->setObjectName("actionshow_Imin_Imax");
        actionshow_Imin_Imax->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(16777215, 12));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 2, 0, 0);
        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(16777215, 10));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"	background-color: rgb(0, 170, 0);\n"
"	border-radius: 5px;\n"
"}\n"
"QProgressBar::chunk {\n"
"	border-radius: 5px;\n"
"	background-color: rgb(255, 0, 0);\n"
"}"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        horizontalLayout_2->addWidget(progressBar);


        verticalLayout_4->addWidget(widget_3);

        widget_2 = new ManualPeakFind(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 10, 0, 10);

        verticalLayout_4->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1326, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuPython = new QMenu(menubar);
        menuPython->setObjectName("menuPython");
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName("menuWindow");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setMinimumSize(QSize(134, 166));
        dockWidget->setMaximumSize(QSize(524287, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        treeWidget = new VNPTreeWidget(dockWidgetContents);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuPython->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionopen);
        menuFile->addAction(actionload_csv);
        menuFile->addAction(actionload_dat);
        menuFile->addAction(actionsave_to_csv);
        menuTools->addAction(actionauto_run);
        menuTools->addAction(actionstop_auto);
        menuTools->addAction(actionfilter);
        menuTools->addAction(actionestimation);
        menuTools->addAction(actionfind_peak);
        menuTools->addAction(actioninsert_event);
        menuTools->addAction(actionremove_event);
        menuTools->addAction(actionestimation2);
        menuTools->addAction(actionfilter_save);
        menuPython->addAction(actioncommand);
        menuPython->addAction(actionfilebrowsers);
        menuPython->addAction(actionshow_plot);
        menuPython->addAction(actionshow_Imin_Imax);
        menuSettings->addAction(actionparameter);
        toolBar->addAction(actionopen);
        toolBar->addAction(actionload_dat);
        toolBar->addAction(actionload_csv);
        toolBar->addAction(actioncopy_data);
        toolBar->addSeparator();
        toolBar->addAction(actionfilter);
        toolBar->addSeparator();
        toolBar->addAction(actionfind_peak);
        toolBar->addAction(actionestimation);
        toolBar->addAction(actioninsert_event);
        toolBar->addAction(actionremove_event);
        toolBar->addAction(actionsave_to_csv);
        toolBar->addSeparator();
        toolBar->addAction(actionestimation2);
        toolBar->addSeparator();
        toolBar->addAction(actionauto_run);
        toolBar->addAction(actionstop_auto);
        toolBar->addSeparator();
        toolBar->addAction(actionparameter);
        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionfilebrowsers, &QAction::triggered, dockWidget, &QDockWidget::setVisible);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "open folder", nullptr));
        actionparameter->setText(QCoreApplication::translate("MainWindow", "parameter", nullptr));
        actionstart_python->setText(QCoreApplication::translate("MainWindow", "start python", nullptr));
        actionauto_run->setText(QCoreApplication::translate("MainWindow", "auto run", nullptr));
        actionstop_auto->setText(QCoreApplication::translate("MainWindow", "stop auto", nullptr));
        actionfilter->setText(QCoreApplication::translate("MainWindow", "filter", nullptr));
        actionfind_peak->setText(QCoreApplication::translate("MainWindow", "find peak", nullptr));
        actioncommand->setText(QCoreApplication::translate("MainWindow", "show python", nullptr));
        actionfilebrowsers->setText(QCoreApplication::translate("MainWindow", "filebrowsers", nullptr));
        actionload_csv->setText(QCoreApplication::translate("MainWindow", "load csv", nullptr));
#if QT_CONFIG(tooltip)
        actionload_csv->setToolTip(QCoreApplication::translate("MainWindow", "load csv", nullptr));
#endif // QT_CONFIG(tooltip)
        actionload_dat->setText(QCoreApplication::translate("MainWindow", "load dat", nullptr));
        actionsave_to_csv->setText(QCoreApplication::translate("MainWindow", "save to csv", nullptr));
        actioninsert_event->setText(QCoreApplication::translate("MainWindow", "insert event", nullptr));
        actionremove_event->setText(QCoreApplication::translate("MainWindow", "remove event", nullptr));
        actionshow_plot->setText(QCoreApplication::translate("MainWindow", "show plot", nullptr));
        actioncopy_data->setText(QCoreApplication::translate("MainWindow", "copy data", nullptr));
        actionestimation->setText(QCoreApplication::translate("MainWindow", "Estimation", nullptr));
#if QT_CONFIG(tooltip)
        actionestimation->setToolTip(QCoreApplication::translate("MainWindow", "Estimation Protein", nullptr));
#endif // QT_CONFIG(tooltip)
        actionestimation2->setText(QCoreApplication::translate("MainWindow", "remove baseline", nullptr));
#if QT_CONFIG(tooltip)
        actionestimation2->setToolTip(QCoreApplication::translate("MainWindow", "undefine", nullptr));
#endif // QT_CONFIG(tooltip)
        actionfilter_save->setText(QCoreApplication::translate("MainWindow", "filter save", nullptr));
        actionshow_Imin_Imax->setText(QCoreApplication::translate("MainWindow", "show Imin Imax", nullptr));
        progressBar->setFormat(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuPython->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("MainWindow", "Window", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
