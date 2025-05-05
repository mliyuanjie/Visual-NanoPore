#include "createvnp.h" 
#include "vnpio.h"


createvnp::createvnp(QWidget* parent) : QDialog(parent) {
	ui.setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose);
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

void createvnp::savefile() {
	VNPIO file;
	if (filenames.empty())
		return;
	QString foldername = QFileInfo(filenames[0]).absoluteDir().absolutePath();
	QString fn = foldername + '/' + this->findChild<QLineEdit*>("lineEdit")->text() + ".h5";
	file.create(fn.toStdString());
	for (const auto& i : filenames) {
		file.creategroup(i.split('/').last().toStdString());
		file.createattri(i.split('/').last().toStdString(), mymap);
	}
	file.close();
	filepath = fn.toStdString();
}

void createvnp::setconfig(std::unordered_map<std::string, double> map) {
	mymap = map;
}