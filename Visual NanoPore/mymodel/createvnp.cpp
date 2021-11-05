#include "createvnp.h" 
#include "vnpio.h"


createvnp::createvnp(QWidget* parent) : QDialog(parent) {
	ui.setupUi(this);
	QPushButton* selectbutton = this->findChild<QPushButton*>("pushButton");
	connect(selectbutton, SIGNAL(clicked()), this, SLOT(selectdata()));
}

void createvnp::selectdata() {
	filenames = QFileDialog::getOpenFileNames(
		this,
		"Select one or more files to open",
		"/home",
		"Nanopore data (*.dat)");
	QListWidget* listwidget = this->findChild<QListWidget*>("listWidget");
	listwidget->addItems(filenames);
}

void createvnp::accept() {
	VNPIO file;
	QString foldername = QFileDialog::getExistingDirectory(this);
	QString fn = foldername+ '/'+this->findChild<QLineEdit*>("lineEdit")->text() + ".vnp";
	file.open(fn.toStdString());
	for (const auto& i : filenames) {
		file.creategroup(i.split('/').last().toStdString(), 2);
	}
	file.close();
}