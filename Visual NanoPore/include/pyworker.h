#pragma once

#ifndef PYWORKER_H
#define PYWORKER_H

#include <QtCore/qobject.h>
#include <list>
#include <unordered_map>
#include <string>

#pragma push_macro("slots")
#undef slots
#include <boost/python.hpp>

#pragma pop_macro("slots")

namespace p = boost::python;




class PYWorker : public QObject {
	Q_OBJECT;

public:
	void setpath(std::string, std::string);

public slots:
	void run(bool);
	void stop();
	void run_command(QString);
	void setdata(QString);
	void completion(QString);

signals:
	void setprogress(int);
	void finish();
	void result_command(QString);
	void send_completion(QString);
private:
	p::object main_module;
	p::dict main_namespace;
	bool running = false;
	std::string cwdpath;
	std::string pythonpath;
};


#endif //PYWORKER_H
