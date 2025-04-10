#include "vnpnetio.h"
#include "login.h" 

Login::Login(QWidget* parent) : QDialog(parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	QPushButton* selectbutton = this->findChild<QPushButton*>("pushButton");
	connect(selectbutton, SIGNAL(clicked()), this, SLOT(check()));
	QPushButton* selectbutton2 = this->findChild<QPushButton*>("pushButton_2");
	connect(selectbutton2, SIGNAL(clicked()), this, SIGNAL(reject()));
}

void Login::check() {
	QLineEdit* namelable = this->findChild<QLineEdit*>("lineEdit");
	std::string name = namelable->text().toStdString();

	QLineEdit* pwdlable = this->findChild<QLineEdit*>("lineEdit_2");
	std::string pwd = pwdlable->text().toStdString();

	std::string message = login("115.159.22.158", 8087, name, pwd);
	if (message == "ok") {
		emit accept();
	}
	else {
		QMessageBox msgBox;
		msgBox.setText(message.c_str());
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.show();
		if (msgBox.exec() == QMessageBox::Yes)
			return;
	}
	return;
}