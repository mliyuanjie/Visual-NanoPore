#include <QtWidgets/qapplication.h>
#include "vnpmainwindow.h"


int main(int argc, char* argv[]) {
		QApplication app(argc, argv);
		VNPMainWindow w;
		w.show();
		return app.exec();
}