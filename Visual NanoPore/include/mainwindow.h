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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
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
    QAction *actionbaseline;
    QAction *actionfind_peak;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuPython;
    QMenu *menuExtensions;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    VNPTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1800, 944);
        MainWindow->setMinimumSize(QSize(1500, 800));
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
        actionauto_run = new QAction(MainWindow);
        actionauto_run->setObjectName(QStringLiteral("actionauto_run"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/autorun.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionauto_run->setIcon(icon2);
        actionstop_auto = new QAction(MainWindow);
        actionstop_auto->setObjectName(QStringLiteral("actionstop_auto"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstop_auto->setIcon(icon3);
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QStringLiteral("actionfilter"));
        actionfilter->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/waveform-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfilter->setIcon(icon4);
        actionbaseline = new QAction(MainWindow);
        actionbaseline->setObjectName(QStringLiteral("actionbaseline"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/align.png"), QSize(), QIcon::Normal, QIcon::On);
        actionbaseline->setIcon(icon5);
        actionfind_peak = new QAction(MainWindow);
        actionfind_peak->setObjectName(QStringLiteral("actionfind_peak"));
        actionfind_peak->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/C:/Users/LiYu/source/repos/Visual NanoPore/Visual NanoPore/resources/vector-curve-off.png"), QSize(), QIcon::Normal, QIcon::On);
        actionfind_peak->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 1881, 1000));
        mdiArea->setMinimumSize(QSize(1462, 1000));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 26));
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
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(348, 258));
        dockWidget->setMaximumSize(QSize(348, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        treeWidget = new VNPTreeWidget(dockWidgetContents);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuPython->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuExtensions->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionopen);
        menuTools->addAction(actionauto_run);
        menuTools->addAction(actionstop_auto);
        menuTools->addAction(actionfilter);
        menuTools->addAction(actionbaseline);
        menuTools->addAction(actionfind_peak);
        menuExtensions->addAction(actionstart_python);
        menuSettings->addAction(actionparameter);
        toolBar->addAction(actionopen);
        toolBar->addAction(actionparameter);
        toolBar->addAction(actionstop_auto);
        toolBar->addSeparator();
        toolBar->addAction(actionfilter);
        toolBar->addAction(actionbaseline);
        toolBar->addAction(actionfind_peak);
        toolBar->addAction(actionauto_run);

        retranslateUi(MainWindow);
        QObject::connect(treeWidget, SIGNAL(progress(int)), progressBar, SLOT(setValue(int)));

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
        actionbaseline->setText(QApplication::translate("MainWindow", "baseline", Q_NULLPTR));
        actionfind_peak->setText(QApplication::translate("MainWindow", "find peak", Q_NULLPTR));
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
