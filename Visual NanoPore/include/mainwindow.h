/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
#include "pythonwidget.h"
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
    QMenu *menuExtensions;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    VNPTreeWidget *treeWidget;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    PythonWidget *widget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionopen->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon);
        actionparameter = new QAction(MainWindow);
        actionparameter->setObjectName(QStringLiteral("actionparameter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionparameter->setIcon(icon1);
        actionstart_python = new QAction(MainWindow);
        actionstart_python->setObjectName(QStringLiteral("actionstart_python"));
        actionstart_python->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/python.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstart_python->setIcon(icon2);
        actionauto_run = new QAction(MainWindow);
        actionauto_run->setObjectName(QStringLiteral("actionauto_run"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/autorun.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionauto_run->setIcon(icon3);
        actionstop_auto = new QAction(MainWindow);
        actionstop_auto->setObjectName(QStringLiteral("actionstop_auto"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstop_auto->setIcon(icon4);
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QStringLiteral("actionfilter"));
        actionfilter->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfilter->setIcon(icon5);
        actionfind_peak = new QAction(MainWindow);
        actionfind_peak->setObjectName(QStringLiteral("actionfind_peak"));
        actionfind_peak->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfind_peak->setIcon(icon6);
        actioncommand = new QAction(MainWindow);
        actioncommand->setObjectName(QStringLiteral("actioncommand"));
        actionfilebrowsers = new QAction(MainWindow);
        actionfilebrowsers->setObjectName(QStringLiteral("actionfilebrowsers"));
        actionfilebrowsers->setCheckable(true);
        actionload_csv = new QAction(MainWindow);
        actionload_csv->setObjectName(QStringLiteral("actionload_csv"));
        actionload_csv->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/loadcsvfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_csv->setIcon(icon7);
        actionload_dat = new QAction(MainWindow);
        actionload_dat->setObjectName(QStringLiteral("actionload_dat"));
        actionload_dat->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/loaddatfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_dat->setIcon(icon8);
        actionsave_to_csv = new QAction(MainWindow);
        actionsave_to_csv->setObjectName(QStringLiteral("actionsave_to_csv"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave_to_csv->setIcon(icon9);
        actioninsert_event = new QAction(MainWindow);
        actioninsert_event->setObjectName(QStringLiteral("actioninsert_event"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/add_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioninsert_event->setIcon(icon10);
        actionremove_event = new QAction(MainWindow);
        actionremove_event->setObjectName(QStringLiteral("actionremove_event"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/delete_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionremove_event->setIcon(icon11);
        actionshow_plot = new QAction(MainWindow);
        actionshow_plot->setObjectName(QStringLiteral("actionshow_plot"));
        actionshow_plot->setCheckable(true);
        actioncopy_data = new QAction(MainWindow);
        actioncopy_data->setObjectName(QStringLiteral("actioncopy_data"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/duplicate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy_data->setIcon(icon12);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 12));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 2, 0, 0);
        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 10));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 10, 0, 10);

        verticalLayout_4->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuPython = new QMenu(menubar);
        menuPython->setObjectName(QStringLiteral("menuPython"));
        menuExtensions = new QMenu(menubar);
        menuExtensions->setObjectName(QStringLiteral("menuExtensions"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(134, 166));
        dockWidget->setMaximumSize(QSize(524287, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new VNPTreeWidget(dockWidgetContents);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(91, 200));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget = new PythonWidget(dockWidgetContents_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout_6->addWidget(widget);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_2);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuPython->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuExtensions->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionopen);
        menuFile->addAction(actionload_csv);
        menuFile->addAction(actionload_dat);
        menuFile->addAction(actionsave_to_csv);
        menuTools->addAction(actionauto_run);
        menuTools->addAction(actionstop_auto);
        menuTools->addAction(actionfilter);
        menuTools->addAction(actionfind_peak);
        menuTools->addAction(actioninsert_event);
        menuTools->addAction(actionremove_event);
        menuPython->addAction(actioncommand);
        menuPython->addAction(actionfilebrowsers);
        menuPython->addAction(actionshow_plot);
        menuExtensions->addAction(actionstart_python);
        menuSettings->addAction(actionparameter);
        toolBar->addAction(actionopen);
        toolBar->addAction(actionfilter);
        toolBar->addAction(actionfind_peak);
        toolBar->addAction(actionsave_to_csv);
        toolBar->addAction(actionauto_run);
        toolBar->addAction(actionstop_auto);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionload_dat);
        toolBar->addAction(actionload_csv);
        toolBar->addAction(actionparameter);
        toolBar->addSeparator();
        toolBar->addAction(actioninsert_event);
        toolBar->addAction(actionremove_event);
        toolBar->addSeparator();
        toolBar->addAction(actioncopy_data);

        retranslateUi(MainWindow);
        QObject::connect(actionfilebrowsers, SIGNAL(triggered(bool)), dockWidget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "open folder", Q_NULLPTR));
        actionparameter->setText(QApplication::translate("MainWindow", "parameter", Q_NULLPTR));
        actionstart_python->setText(QApplication::translate("MainWindow", "start python", Q_NULLPTR));
        actionauto_run->setText(QApplication::translate("MainWindow", "auto run", Q_NULLPTR));
        actionstop_auto->setText(QApplication::translate("MainWindow", "stop auto", Q_NULLPTR));
        actionfilter->setText(QApplication::translate("MainWindow", "filter", Q_NULLPTR));
        actionfind_peak->setText(QApplication::translate("MainWindow", "find peak", Q_NULLPTR));
        actioncommand->setText(QApplication::translate("MainWindow", "show python", Q_NULLPTR));
        actionfilebrowsers->setText(QApplication::translate("MainWindow", "filebrowsers", Q_NULLPTR));
        actionload_csv->setText(QApplication::translate("MainWindow", "load csv", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionload_csv->setToolTip(QApplication::translate("MainWindow", "load csv", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionload_dat->setText(QApplication::translate("MainWindow", "load dat", Q_NULLPTR));
        actionsave_to_csv->setText(QApplication::translate("MainWindow", "save to csv", Q_NULLPTR));
        actioninsert_event->setText(QApplication::translate("MainWindow", "insert event", Q_NULLPTR));
        actionremove_event->setText(QApplication::translate("MainWindow", "remove event", Q_NULLPTR));
        actionshow_plot->setText(QApplication::translate("MainWindow", "show plot", Q_NULLPTR));
        actioncopy_data->setText(QApplication::translate("MainWindow", "copy data", Q_NULLPTR));
        progressBar->setFormat(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuPython->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuExtensions->setTitle(QApplication::translate("MainWindow", "Extensions", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
