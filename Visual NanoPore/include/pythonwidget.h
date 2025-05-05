#pragma once
#ifndef PYTHONWIDGET_H
#define PYTHONEWIDGET_H

#include <QtCore/qobject.h>
#include <pythonui.h>

class PythonWidget :public QWidget {
	Q_OBJECT;
public:
	PythonWidget(QWidget* = nullptr);

public slots:
	void settext();
	void showtext(QString);
	void showcompletion(QString);

signals:
	void textinput(QString);
	void sendcomp(QString);

private:
	Ui::PythonForm ui;
	ConsoleLinEdit* lineedit;
	QComboBox* comboBox;
	QTextBrowser* textbrowser;
};



#endif // !VNPTREEWIDGET_H
