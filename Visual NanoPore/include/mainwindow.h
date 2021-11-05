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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "vnptreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionremove_signal;
    QAction *actionadd_signal;
    QAction *actionedit;
    QAction *actionfilter;
    QAction *actionfindpeak;
    QAction *actionopen;
    QAction *actionsaveas;
    QAction *actionautopeakfind;
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
    VNPTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2216, 962);
        MainWindow->setMinimumSize(QSize(1000, 700));
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QStringLiteral("actionnew"));
        QIcon icon;
        icon.addFile(QStringLiteral("../resources/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnew->setIcon(icon);
        actionremove_signal = new QAction(MainWindow);
        actionremove_signal->setObjectName(QStringLiteral("actionremove_signal"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resources/delete_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionremove_signal->setIcon(icon1);
        actionadd_signal = new QAction(MainWindow);
        actionadd_signal->setObjectName(QStringLiteral("actionadd_signal"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resources/add_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionadd_signal->setIcon(icon2);
        actionedit = new QAction(MainWindow);
        actionedit->setObjectName(QStringLiteral("actionedit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../resources/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionedit->setIcon(icon3);
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QStringLiteral("actionfilter"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../resources/waveform.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfilter->setIcon(icon4);
        actionfindpeak = new QAction(MainWindow);
        actionfindpeak->setObjectName(QStringLiteral("actionfindpeak"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../resources/findpeak.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfindpeak->setIcon(icon5);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon6);
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QStringLiteral("actionsaveas"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../resources/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveas->setIcon(icon7);
        actionautopeakfind = new QAction(MainWindow);
        actionautopeakfind->setObjectName(QStringLiteral("actionautopeakfind"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(-20, 0, 1861, 1000));
        mdiArea->setMinimumSize(QSize(1462, 1000));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2216, 21));
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
        menuFile->addAction(actionnew);
        menuFile->addAction(actionopen);
        menuTools->addAction(actionadd_signal);
        menuTools->addAction(actionremove_signal);
        menuTools->addAction(actionfilter);
        menuTools->addAction(actionedit);
        menuTools->addSeparator();
        menuSettings->addAction(actionautopeakfind);
        toolBar->addAction(actionnew);
        toolBar->addAction(actionfilter);
        toolBar->addAction(actionfindpeak);
        toolBar->addSeparator();
        toolBar->addAction(actionedit);
        toolBar->addAction(actionadd_signal);
        toolBar->addAction(actionremove_signal);
        toolBar->addAction(actionopen);
        toolBar->addSeparator();
        toolBar->addAction(actionsaveas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionnew->setText(QApplication::translate("MainWindow", "new", Q_NULLPTR));
        actionremove_signal->setText(QApplication::translate("MainWindow", "remove signal", Q_NULLPTR));
        actionadd_signal->setText(QApplication::translate("MainWindow", "add signal", Q_NULLPTR));
        actionedit->setText(QApplication::translate("MainWindow", "edit", Q_NULLPTR));
        actionfilter->setText(QApplication::translate("MainWindow", "filter", Q_NULLPTR));
        actionfindpeak->setText(QApplication::translate("MainWindow", "findpeak", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        actionsaveas->setText(QApplication::translate("MainWindow", "saveas", Q_NULLPTR));
        actionautopeakfind->setText(QApplication::translate("MainWindow", "autopeakfind", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
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
