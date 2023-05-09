#include<fstream>
#include "findpeakworker.h"
#include "findpeak.h"


void FindPeakWorker::run() {
	if (mymap["auto"] == 2) {
		run_short();
	}
	else if (mymap["auto"] == 1) {
		run_long();
	}
}

void FindPeakWorker::run_long() {
	std::ifstream ifn;
	ifn.open(filename.toStdString(), std::ifstream::in | std::ifstream::binary);
	if (!ifn)
		return;
	double interval = 1.0 / mymap["fs"];
	int length = xmax / interval;
	std::vector<float> data;
	int end = 0;
	int start = xmin / interval;
	long offset = (long)start * sizeof(float);
	ifn.seekg(offset, std::ios::beg);
	FindPeakRealTime peakfind = FindPeakRealTime(mymap["fs"], mymap["threshold"], mymap["resolution"], mymap["window"], mymap["direction"], start, false);
	while (start < length) {
		data.clear();
		end = start + 500000;
		if (end > length)
			end = length;
		data.resize(end - start);
		ifn.read((char*)data.data(), (end - start) * sizeof(float));
		peakfind.append(data);
		QVector<QPointF> point;
		eventlist = peakfind.result;
		for (auto it : eventlist) {
			point.append(QPointF(it.start, it.baseline));
			point.append(QPointF(it.start, it.currentpeak));
			point.append(QPointF(it.end, it.currentpeak));
			point.append(QPointF(it.end, it.baseline));
		}
		emit setevent(point);
		start += 500000;
	}
	emit finish();
	ifn.close();
}

void FindPeakWorker::run_short() {
	std::ifstream ifn;
	ifn.open(filename.toStdString(), std::ifstream::in | std::ifstream::binary);
	if (!ifn)
		return;
	double interval = 1.0 / mymap["fs"];
	int length = xmax / interval;
	std::vector<float> data;
	int end = 0;
	int start = xmin / interval;
	long offset = (long)start * sizeof(float);
	ifn.seekg(offset, std::ios::beg);
	FindPeakRealTimeShort peakfind = FindPeakRealTimeShort(mymap["fs"], mymap["threshold"], mymap["resolution"], mymap["window"], mymap["direction"], start, mymap["maxtime"]);
	while (start < length) {
		data.clear();
		end = start + 500000;
		if (end > length)
			end = length;
		data.resize(end - start);
		ifn.read((char*)data.data(), (end - start) * sizeof(float));
		peakfind.append(data);
		QVector<QPointF> point;
		eventlist = peakfind.result;
		for (auto it : eventlist) {
			point.append(QPointF(it.start, it.baseline));
			point.append(QPointF(it.start, it.currentpeak));
			point.append(QPointF(it.end, it.currentpeak));
			point.append(QPointF(it.end, it.baseline));
		}
		emit setevent(point);
		start += 500000;
	}
	emit finish();
	ifn.close();
}