#include "vnpmainwindow.h" 
#include "manual.h"
#include "vnptreewidget.h"





VNPMainWindow::VNPMainWindow(QWidget* parent) :QMainWindow(parent) {
	ui.setupUi(this);
	QToolBar* toolbar = this->findChild<QToolBar*>("toolBar");
	QAction* actionopen = this->findChild<QAction*>("actionopen");
	QAction* actionparameter = this->findChild<QAction*>("actionparameter");
	QAction* actionauto_run = this->findChild<QAction*>("actionauto_run");
	QAction* actionstop_auto = this->findChild<QAction*>("actionstop_auto");
	QAction* actionfilter = this->findChild<QAction*>("actionfilter");
	QAction* actionestimation = this->findChild<QAction*>("actionestimation");
	QAction* actionfind_peak = this->findChild<QAction*>("actionfind_peak");
	QAction* actioninsert_event = this->findChild<QAction*>("actioninsert_event");
	QAction* actionremove_event = this->findChild<QAction*>("actionremove_event");
	QAction* actionsave_to_csv = this->findChild<QAction*>("actionsave_to_csv");
	QAction* actionload_csv = this->findChild<QAction*>("actionload_csv");
	QAction* actionload_dat = this->findChild<QAction*>("actionload_dat");
	//QAction* actionstart_python = this->findChild<QAction*>("actionstart_python");
	QAction* actionshow_plot = this->findChild<QAction*>("actionshow_plot");
	QAction* actioncopy_data = this->findChild<QAction*>("actioncopy_data");
	QAction* actionshow_Imin_Imax = this->findChild<QAction*>("actionshow_Imin_Imax");

	ManualPeakFind* p1 = this->findChild<ManualPeakFind*>("widget_2");
	VNPTreeWidget* p2 = this->findChild<VNPTreeWidget*>("treeWidget");
	//PythonWidget* p3 = this->findChild<PythonWidget*>("widget");
	QProgressBar* progressbar = this->findChild<QProgressBar*>("progressBar");
	controller = new VNPController(this, p1, p2);
	connect(controller, SIGNAL(setprogress(int)), progressbar, SLOT(setValue(int)));
	connect(actionopen, SIGNAL(triggered()), controller, SLOT(opendatlist()));
	connect(actionauto_run, SIGNAL(triggered()), controller, SLOT(autorun()));
	connect(actionparameter, SIGNAL(triggered()), controller, SIGNAL(showconfig()));
	connect(actionfilter, SIGNAL(triggered(bool)), controller, SLOT(filter(bool)));
	connect(actionfind_peak, SIGNAL(triggered(bool)), controller, SLOT(findpeak(bool)));
	connect(actioninsert_event, SIGNAL(triggered()), controller, SLOT(insertevent()));
	connect(actionremove_event, SIGNAL(triggered()), controller, SLOT(removeevent()));
	connect(actioninsert_event, SIGNAL(triggered()), controller, SLOT(insertevent()));
	connect(actionestimation, SIGNAL(triggered()), controller, SLOT(estimationevent()));
	connect(actionsave_to_csv, SIGNAL(triggered()), controller, SLOT(saveeventlist()));
	connect(actioncopy_data, SIGNAL(triggered()), controller, SLOT(copydata()));
	connect(actionload_csv, SIGNAL(triggered(bool)), controller, SLOT(opencsv(bool)));
	connect(actionload_dat, SIGNAL(triggered(bool)), controller, SLOT(opendat2dialog(bool)));
	//connect(actionstart_python, SIGNAL(triggered(bool)), controller, SLOT(startpy(bool)));
	//connect(actionstart_python, SIGNAL(triggered(bool)), this, SLOT(pythonvisible(bool)));
	connect(actionshow_plot, SIGNAL(triggered(bool)), this, SLOT(datavisible(bool)));
	connect(actionshow_Imin_Imax, SIGNAL(triggered(bool)), controller, SLOT(show_Imin_Imax(bool)));
	//QDockWidget* pw = this->findChild<QDockWidget*>("dockWidget_2");
	//pw->setVisible(false);
}

//void VNPMainWindow::pythonvisible(bool ischeck) {
//	QDockWidget* pw = this->findChild<QDockWidget*>("dockWidget_2");
//	pw->setVisible(ischeck);
//}

void VNPMainWindow::datavisible(bool ischeck) {
	ManualPeakFind* pw = this->findChild<ManualPeakFind*>("widget_2");
	pw->setVisible(ischeck);
}