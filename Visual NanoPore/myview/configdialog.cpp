#include "configdialog.h" 

ConfigDialog::ConfigDialog(QWidget* parent) :QDialog(parent) {
	ui.setupUi(this);
	QPushButton* selectbutton = this->findChild<QPushButton*>("pushButton");
	connect(selectbutton, SIGNAL(clicked()), this, SLOT(selectfile()));
}

void ConfigDialog::selectfile() {
	QString filename = QFileDialog::getOpenFileName(
		this,
		"Select one to open",
		"/home",
		"project file (*.txt)");
	std::unordered_map<std::string, double> mymap = readconfig(filename.toStdString());
	QTableWidget* tablewidget = this->findChild<QTableWidget*>("tableWidget");
	tablewidget->setRowCount(mymap.size());
	int i = 0;
	for (std::pair<std::string, double> element : mymap)
	{
		QTableWidgetItem* itemkey = new QTableWidgetItem(QString::fromStdString(element.first));
		QTableWidgetItem* itemvalue = new QTableWidgetItem(QString::number(element.second));
		tablewidget->setItem(i, 0, itemkey);
		tablewidget->setItem(i, 1, itemvalue);
		i++;
	}
}