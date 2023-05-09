#include <stdlib.h>

#include "pyworker.h"


PYWorker::~PYWorker() {
	p::finalize_interpreter();
}

void PYWorker::setpath(std::string str2) {
	pythonpath = str2;
}

bool PYWorker::run() {
	//char* a = getenv("PATH");
	try {
		putenv(pythonpath.c_str());
		//system("python -i 'print('hello')");
		//Py_Initialize();
		//p::initialize_interpreter();
		//p::print("Hello, World from Python!");
		//main_module = p::import("__main__");
		//main_namespace = p::extract<p::dict>(main_module.attr("__dict__"));
		//std::string initpy = "exec(open('"+ cwdpath + "/initvnp.py').read())";
		//guard = new p::scoped_interpreter{};
		p::initialize_interpreter();
		p::exec(initpy, p::globals());
		return true;
	}
	catch (...) {
		emit result_command(QString("Python Initialization Error"));
		return false;
	}
}

void PYWorker::setdata(QString fn) {
	try {
		QString str = "try:\n\tdata = _loadDAT('" + fn + "')\nexcept:\n\tprint('.dat file error')\n";
		QByteArray qbitstr = str.toUtf8();
		const char* cstr = qbitstr.constData();
		p::exec(cstr, p::globals());
	}
	catch (...) {
		emit result_command(QString("Set DATA Error"));
	}
}

void PYWorker::stop() {
	//Py_Finalize();
}

void PYWorker::run_command(QString str) {
	QRegExp rx("print(.*)");
	if (rx.exactMatch(str)) {
		str = "try:\n\t" + str + "\nexcept:\n\tprint('error')\n";
	}
	else {
		str.replace(QString("'"), QString("\""));
		str = "try:\n\tprint(eval('" + str + "'))\n" + "except:\n\ttry:\n\t\t" + str + "\n\texcept:\n\t\tprint('error')\n";
	}
		

	QByteArray qbitstr = str.toUtf8();
	const char* cstr = qbitstr.constData();
	std::string res;
	try {
		p::exec(cstr, p::globals());
		auto globals = p::globals();
		p::object catcher = globals["_catchOutErr"].cast<p::object>();
		// = main_module.attr("_catchOutErr");
		auto res = catcher.attr("value").cast<std::string>();
		if (!res.empty())
			emit result_command(QString::fromStdString(res));
		globals["_catchOutErr"].attr("flush")();
	}
	catch (...) {	
		emit result_command(QString("Exec Error"));
	}
	return;
}

void PYWorker::completion(QString str) {
	if (str == "")
		return;
	str.replace(QString("'"), QString("\""));
	str = "print(_completion('"+str+"'))";
	QByteArray qbitstr = str.toUtf8();
	const char* cstr = qbitstr.constData();
	p::exec(cstr, p::globals());
	auto globals = p::globals();
	p::object catcher = globals["_catchOutErr"].cast<p::object>();
	// = main_module.attr("_catchOutErr");
	auto res = catcher.attr("value").cast<std::string>();
	emit send_completion(QString::fromStdString(res));
	globals["_catchOutErr"].attr("flush")();
}
