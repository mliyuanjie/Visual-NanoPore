#include <stdlib.h>
#include "pyworker.h"
/*
std::string stdOutErr = "import sys\nimport rlcompleter\nclass CatchOutErr:\n\
	def __init__(self):\n\
		self.value = ''\n\
	def write(self, txt):\n\
		self.value += txt\n\
	def flush(self):\n\
		self.value = ''\n\
catchOutErr = CatchOutErr()\n\
sys.stdout = catchOutErr\n\
sys.stderr = catchOutErr\n\
_completer = rlcompleter.Completer()\n\
def _completion(s):\n\
	res = ''+s\n\
	for i in range(50):\n\
		items = _completer.complete(s, i)\n\
		if items is None:\n\
			break\n\
		else:\n\
			res=res+','+items\n\
	return res\n"; //this is python code to redirect stdouts/stderr
	"PYTHONPATH=C:\\Users\\LiYu\\Anaconda3;C:\\Users\\LiYu\\Anaconda3\\Scripts;C:\\Users\\LiYu\\Anaconda3\\lib;C:\\Users\\LiYu\\Anaconda3\\DLLs"
	
		std::string pyscript = "import numpy as np\ndef load_dat(fn = None):\n\
	return np.memmap(fn, dtype = 'float32', mode = 'r', )\n\data = None";
*/
void PYWorker::setpath(std::string str1, std::string str2) {
	cwdpath = str1;
	pythonpath = str2;
	
}

void PYWorker::run(bool ischeck) {
	if (!ischeck) {
		try {
			p::object ignor = p::exec("globals().clear()", main_namespace, main_namespace);
		}
		catch (...) {}
		running = false;
		return;
	}

	//char* a = getenv("PATH");
	try {
		std::string pypath = "PYTHONPATH=" + pythonpath;
		putenv(pypath.c_str());
		Py_Initialize();
		main_module = p::import("__main__");
		main_namespace = p::extract<p::dict>(main_module.attr("__dict__"));
		std::string initpy = "exec(open('"+ cwdpath + "/initvnp.py').read())";
		p::object ignor = p::exec(initpy.c_str(), main_namespace, main_namespace);
		running = true;
	}
	catch (...) {
		emit result_command(QString("Python Initialization Error"));
	}
}

void PYWorker::setdata(QString fn) {
	if (!running)
		return;
	try {
		QString str = "try:\n\tdata = _loadDAT('" + fn + "')\n\tevent = _loadCSV('"+fn+"')\nexcept:\n\tprint('.dat file error')\n";
		QByteArray qbitstr = str.toUtf8();
		const char* cstr = qbitstr.constData();
		p::object ignored = p::exec(cstr, main_namespace, main_namespace);
	}
	catch (...) {
		emit result_command(QString("Set DATA Error"));
	}
}

void PYWorker::stop() {
	Py_Finalize();
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
		p::object ignored = p::exec(cstr, main_namespace, main_namespace);
		p::object catcher = main_module.attr("_catchOutErr");
		res = p::extract<std::string>(catcher.attr("value"));
		if (!res.empty())
			emit result_command(QString::fromStdString(res));
		main_module.attr("_catchOutErr").attr("flush")();
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
	p::object ignor = p::exec(cstr, main_namespace, main_namespace);
	p::object catcher = main_module.attr("_catchOutErr");
	std::string res = p::extract<std::string>(catcher.attr("value"));
	emit send_completion(QString::fromStdString(res));
	main_module.attr("_catchOutErr").attr("flush")();
}
