#include<fstream>
#include <QtWidgets/QFileDialog>
#include <QtCore/qfileinfo.h>
#include "vnpmainwindow.h"
#include "vnptreewidget.h"
#include "qtdataview.h"
#include "Iir.h"
#include "manual.h" 
#include "calworker.h"

bool cover(double x, double x1, double x2) {
	if (x1 > x2 && x <= x1 && x >= x2)
		return true;
	if (x1 <= x2 && x <= x2 && x >= x1)
		return true;
	return false;
}

ManualPeakFind::ManualPeakFind(QWidget* p):QWidget(p) {
	ui.setupUi(this);

	firstview = this->findChild<DataView*>("graphicsView");
	spinbox = this->findChild<QSpinBox*>("spinBox");
	connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(zoomevent(int)));

	QPushButton* button_12 = this->findChild<QPushButton*>("pushButton_12");
	connect(button_12, SIGNAL(clicked()), this, SLOT(backward()));

	QPushButton* button = this->findChild<QPushButton*>("pushButton");
	connect(button, SIGNAL(clicked()), this, SLOT(forward()));

	QPushButton* button_11 = this->findChild<QPushButton*>("pushButton_11");
	connect(button_11, SIGNAL(clicked()), this, SLOT(home()));

	QPushButton* button_10 = this->findChild<QPushButton*>("pushButton_10");
	connect(button_10, SIGNAL(clicked()), this, SLOT(forwardwindow()));

	QComboBox* comboBox = this->findChild<QComboBox*>("comboBox");
	connect(comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(methodboxchange(QString)));

	QDoubleSpinBox* doubleSpinBox = this->findChild<QDoubleSpinBox*>("doubleSpinBox");
	connect(doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setx1(double)));

	QDoubleSpinBox* doubleSpinBox_2 = this->findChild<QDoubleSpinBox*>("doubleSpinBox_2");
	connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), this, SLOT(setx2(double)));

	QDoubleSpinBox* doubleSpinBox_3 = this->findChild<QDoubleSpinBox*>("doubleSpinBox_3");
	connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), this, SLOT(sety1(double)));

	QDoubleSpinBox* doubleSpinBox_4 = this->findChild<QDoubleSpinBox*>("doubleSpinBox_4");
	connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), this, SLOT(sety2(double)));

	connect(firstview, SIGNAL(request_data(double, double, double, double)), this, SLOT(setscale(double, double, double, double)));
	connect(firstview, SIGNAL(send_number(int)), this, SIGNAL(send_number(int)));
}


void ManualPeakFind::home() {
	if (history.empty())
		return;
	double xmin = history.front().xmin;
	double xmax = history.front().xmax;
	double ymax = history.front().ymax;
	double ymin = history.front().ymin;
	history.erase(std::next(history.begin()), history.end());
	firstview->setxscale(xmin, xmax);
	firstview->setyscale(ymin, ymax);
	emit askdata(xmin, xmax, ymin, ymax);
	return;
}

void ManualPeakFind::zoomevent(int currenteventitem) {
	if (currenteventitem >= eventlist.size() / 4)
		return;
	double xmin = eventlist[currenteventitem * 4].x();
	double xmax = eventlist[currenteventitem * 4 + 2].x();
	double dx = xmax - xmin;
	xmin = xmin - dx;
	xmax = xmax + dx;
	double ymin = firstview->axisy->min();
	double ymax = firstview->axisy->max();
	emit askdata(xmin, xmax, ymin, ymax);
	history.push_back({ xmin, xmax, ymin, ymax });
	firstview->setxscale(xmin, xmax);
	firstview->centerline();
}

void ManualPeakFind::forwardwindow() {
	if (eventlist.size() > 0 && firstview->series_event->isVisible()) {
		int currenteventitem = this->spinbox->value() + 1;
		if (currenteventitem >= eventlist.size() / 4)
			return;
		spinbox->setValue(currenteventitem);
	}
	else {
		double skip = this->findChild<QDoubleSpinBox*>("doubleSpinBox_2")->value();
		double xmax = firstview->axisx->max();
		double ymin = firstview->axisy->min();
		double ymax = firstview->axisy->max();
		emit askdata(xmax, xmax + skip, ymin, ymax);
		history.push_back({ xmax, xmax + skip, ymin, ymax });
		firstview->setxscale(xmax, xmax + skip);
	}
}

void ManualPeakFind::backward() {
	if (history.size() <= 1)
		return;
	history.pop_back();
	double xmin = history.back().xmin;
	double xmax = history.back().xmax;
	double ymin = history.back().ymin;
	double ymax = history.back().ymax;
	firstview->setxscale(xmin, xmax);
	firstview->setyscale(ymin, ymax);
	emit askdata(xmin, xmax, ymin, ymax);

}

void ManualPeakFind::methodboxchange(QString name) {
	if (name == "Auto")
		method = 0;
	else if (name == "Half Auto")
		method = 1;
	else if (name == "Pick")
		method = 2;
	firstview->changestats(name);
}

void ManualPeakFind::setscale(double xmin, double xmax, double ymin, double ymax) {
	history.push_back({ xmin, xmax, ymin, ymax });
	firstview->setxscale(xmin, xmax);
	firstview->setyscale(ymin, ymax);
	emit askdata(xmin, xmax, ymin, ymax);
}

void ManualPeakFind::setx1(double x) {
	double xmax = firstview->axisx->max();
	firstview->setxscale(x, xmax);
}

void ManualPeakFind::setx2(double x) {
	double xmin = firstview->axisx->min();
	firstview->setxscale(xmin, x);
}

void ManualPeakFind::sety1(double y) {
	double ymax = firstview->axisy->max();
	firstview->setyscale(y, ymax);
}

void ManualPeakFind::sety2(double y) {
	double ymin = firstview->axisy->min();
	firstview->setyscale(ymin, y);
}

void ManualPeakFind::setdata(QVector<QPointF> data) {
	firstview->series->replace(data);
}

void ManualPeakFind::setdata2(QVector<QPointF> data) {
	firstview->series_temp->replace(data);
}

void ManualPeakFind::seteventlist(QVector<QPointF> data) {
	firstview->series_event->replace(data);
	eventlist = data;
}

void ManualPeakFind::seteventlist2(QVector<QPointF> data) {
	firstview->series_event_temp->replace(data);
}

void ManualPeakFind::seteventlist3(QVector<QPointF> data) {
	firstview->series_star->replace(data);
}

void ManualPeakFind::getbar(double& xmin, double& xmax, double& ymin, double& ymax) {
	xmin = this->findChild<QLabel*>("label_18")->text().toDouble();
	xmax = this->findChild<QLabel*>("label_19")->text().toDouble();
	if (!cover(xmin, firstview->axisx->min(), firstview->axisx->max()) || !cover(xmax, firstview->axisx->min(), firstview->axisx->max()))
		xmin = xmax;
	
	ymin = this->findChild<QLabel*>("label_15")->text().toDouble();
	ymax = this->findChild<QLabel*>("label_16")->text().toDouble();
	if (!cover(ymin, firstview->axisy->min(), firstview->axisy->max()) || !cover(ymax, firstview->axisy->min(), firstview->axisy->max()))
		ymin = ymax;

	return;
}

void ManualPeakFind::getaxis(double& xmin, double& xmax, double& ymin, double& ymax) {
	xmin = firstview->axisx->min();
	xmax = firstview->axisx->max();
	ymin = firstview->axisy->min();
	ymax = firstview->axisy->max();
	return;
}