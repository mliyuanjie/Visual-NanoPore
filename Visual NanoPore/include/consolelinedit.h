#pragma once

#ifndef CONSOLELINEDIT_H
#define CONSOLELINEDIT_H

#include <QtCore/qobject.h>
#include <QLineEdit>
#include <QKeyEvent>
#include <list>
#include <string>

class ConsoleLinEdit : public QLineEdit {
	Q_OBJECT;
public:
	ConsoleLinEdit(QWidget* p);

public slots:
	void addhistory();

signals:
	void sendcomp(QString);

protected:
	void keyReleaseEvent(QKeyEvent*);
private:
	std::list<QString> history;
	std::list<QString>::iterator it;
};



#endif // !CONSOLELINEDIT_H
