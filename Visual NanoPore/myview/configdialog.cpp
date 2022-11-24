#include "configdialog.h" 

ConfigDialog::ConfigDialog(QWidget* parent) :QDialog(parent) {
	ui.setupUi(this);
	QComboBox* bmbox = this->findChild<QComboBox*>("baselineMethodComboBox");
	connect(bmbox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(changebm(const QString&)));
	hLabel = this->findChild<QLabel*>("hLabel");
	moveWindowLabel = this->findChild<QLabel*>("moveWindowLabel");
	orderLabel = this->findChild<QLabel*>("orderLabel");
	resolutionLabel = this->findChild<QLabel*>("resolutionLabel");
	stepSizeLabel = this->findChild<QLabel*>("stepSizeLabel");
	hSpinBox = this->findChild<QSpinBox*>("hSpinBox");
	moveWindowSpinBox = this->findChild<QSpinBox*>("moveWindowSpinBox");
	orderSpinBox = this->findChild<QSpinBox*>("orderSpinBox");
	resolutionSpinBox = this->findChild<QSpinBox*>("resolutionSpinBox");
	stepSizeSpinBox = this->findChild<QSpinBox*>("stepSizeSpinBox");

	hLabel->setVisible(false);
	orderLabel->setVisible(false);
	resolutionLabel->setVisible(false);
	stepSizeLabel->setVisible(false);
	hSpinBox->setVisible(false);
	orderSpinBox->setVisible(false);
	resolutionSpinBox->setVisible(false);
	stepSizeSpinBox->setVisible(false);
}

void ConfigDialog::changebm(const QString& name) {
	hLabel->setVisible(false);
	moveWindowLabel->setVisible(false);
	orderLabel->setVisible(false);
	resolutionLabel->setVisible(false);
	stepSizeLabel->setVisible(false);
	hSpinBox->setVisible(false);
	moveWindowSpinBox->setVisible(false);
	orderSpinBox->setVisible(false);
	resolutionSpinBox->setVisible(false);
	stepSizeSpinBox->setVisible(false);
	if (name == "Moving average" || name == "Self Adapt" || name == "Moving median") {
		moveWindowLabel->setVisible(true);
		moveWindowSpinBox->setVisible(true);
	}
	else if (name == "Polynomial fit") {
		orderLabel->setVisible(true);
		resolutionLabel->setVisible(true);
		orderSpinBox->setVisible(true);
		resolutionSpinBox->setVisible(true);
	}
	else if (name == "CUMSUM fit") {
		hLabel->setVisible(true);
		stepSizeLabel->setVisible(true);
		hSpinBox->setVisible(true);
		stepSizeSpinBox->setVisible(true);
	}
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