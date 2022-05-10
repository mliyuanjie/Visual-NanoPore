#include "login.h"
#include "vnpmainwindow.h"
#include <QtWidgets/qapplication.h>


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	Login* login = new Login();
	login->show();
	if (login->exec() == QDialog::Accepted) {
		VNPMainWindow w;
		w.show();
		return app.exec();
	}
	return 0;
}