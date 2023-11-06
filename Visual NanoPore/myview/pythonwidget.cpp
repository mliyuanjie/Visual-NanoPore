#include <QRegExp>
#include <pythonwidget.h> 

PythonWidget::PythonWidget(QWidget* p) :QWidget(p) {
	ui.setupUi(this);
	lineedit = this->findChild<ConsoleLinEdit*>("lineEdit");
	comboBox = this->findChild<QComboBox*>("comboBox");
	textbrowser = this->findChild<QTextBrowser*>("textBrowser");
	connect(lineedit, SIGNAL(returnPressed()), this, SLOT(settext()));
	connect(lineedit, SIGNAL(sendcomp(QString)), this, SIGNAL(sendcomp(QString)));
	lineedit->setFocusPolicy(Qt::StrongFocus);
	comboBox->setVisible(false);
}

void PythonWidget::settext() {	
	QString str = lineedit->text();
	if (str.size() == 0) {
		return;
	}
	lineedit->clear();
	if (str == "clear") {
		textbrowser->clear();
		return;
	}
	textbrowser->setTextColor(QColor("yellow"));
	textbrowser->append(">>" + str.simplified());
	emit textinput(str.simplified());
	comboBox->clear();
	comboBox->setVisible(false);
	return;
}

void PythonWidget::showtext(QString str) {
	textbrowser->setTextColor(QColor("green"));
	textbrowser->append(str.simplified());
	return;
}

void PythonWidget::showcompletion(QString str) {
	QStringList strlist = str.split(',');
	while (*strlist.begin() == "")
		strlist.pop_front();

	comboBox->clear();
	comboBox->insertItems(0, strlist);
	comboBox->setVisible(true);
	comboBox->showPopup();
}