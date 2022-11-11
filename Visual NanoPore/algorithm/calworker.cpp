#include<fstream>

#include "calworker.h"
#include "Iir.h"
#include "tools.h" 

void CalWorker::run() {
	if (filenames.empty() || mymap.empty())
		return;
	std::ifstream ifn;
	for (int i = 0; i < filenames.size(); i++) {
		ifn.open(filenames[i].toStdString(), std::ifstream::in | std::ifstream::binary);
		if (!ifn)
			continue;
		ifn.seekg(0, ifn.end);
		int length = ifn.tellg() / sizeof(float);
		ifn.seekg(0, ifn.beg);
		std::vector<float> data(length);
		ifn.read(reinterpret_cast<char*>(data.data()), length * sizeof(float));
		ifn.close();
		float samplingrate = mymap["fs"];
		float cutoff = mymap["cutoff"];
		Iir::Butterworth::LowPass<5> f;
		f.setup(samplingrate, cutoff);
		for (int j = 0; j < data.size(); j++) {
			data[j] = f.filter(data[j]);
		}
		std::list<Peak> res;
		double per = double(i + 1) / double(filenames.size());
		if (int(mymap["auto"]) == 2) {
			res = findPeak_longevent(data, mymap, mymap["startpoint"], mymap["endpoint"]);
		}
		else {
			res = findPeak(data, mymap, mymap["startpoint"], mymap["endpoint"]);
		}
		std::string csvname = filenames[i].toStdString().substr(0, filenames[i].size() - 3) + "csv";
		std::ofstream ofn(csvname, std::ofstream::out | std::ofstream::trunc);
		ofn << "start,end,start(ms),end(ms),I0(pA),I1(pA)\n";
		for (auto it : res) {
			ofn << std::to_string(it.s) << ","
				<< std::to_string(it.e) << ","
				<< std::to_string(it.start) << ","
				<< std::to_string(it.end) << ","
				<< std::to_string(it.baseline) << ","
				<< std::to_string(it.currentpeak) << "\n";
		}
		ofn.close();
		
		emit setprogress(per * 100);
	}
	emit finish();
}