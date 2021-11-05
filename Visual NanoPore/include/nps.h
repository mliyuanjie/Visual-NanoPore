#ifndef NPS_H
#define NPS_H

#include <vector>
#include <string>
#include <unordered_map>
#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "matlab/IntraEventFit.h"
#include "datio.h"
#include "tools.h"
#include <list>

class NPS: public QObject {
	Q_OBJECT;	
public:
	~NPS();
public slots:
	void trace(float, float);
	//void multiFit();
	void fit();
	//void save();
	//void setPhysics(float, float, float, float, float);
	void load(std::string);
	void pretrace();
	void nexttrace();
	void prehist();
	void nexthist();
	void setIndex(int);
	void setBin(int);
	void sethist(float);
	void zoomin();
	void savenps();
	void fitall();
	void initui();
	void setpara(Physical, FitPara);
	void median();

signals:
	void sendtrace(QVector<QPointF>);
	void sendsig(QVector<QPointF>);
	void sendhist(QVector<QPointF>);
	void sendfit(QVector<QPointF>);
	void sendcursig(QVector<QPointF>);
	void sendaxis(float, float, float, float, bool);
	void sendhistaxis(float, float, float, float);
	void sendtracenum(int);
	void sendtracecur(int);
	void sendsignum(int);
	void sendindex(QString);
	void sendpara(PeakResult);
	void sendprocess(int);
	void sendmessage(QString);
	void sendDev(double);
	void sendmedian(float, float);

private:
	std::list<traceframe> history;
	std::vector<dataframe> filelist;
	
};

#endif // !NPS_H