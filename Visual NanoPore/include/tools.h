#ifndef TOOLS_H
#define TOOLS_H 
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>



struct Peak {
	double start;
	double end;
	double currentpeak;
	double baseline;
	int s;
	int e;
	int s0;
	bool operator<(const Peak& val) const {
		return s < val.s;
	}
};

class Baseline {
public:
	Baseline(std::vector<float>& data, int autob, int order, int resolution, int start, int end);
	float operator[](int);
	void set(int, float);
	void clear();
	std::vector<double> coeff;
	float* b = NULL;

private:
	int s;
	int e;
};

std::unordered_map<std::string, double> readconfig(std::string);
std::list<Peak> readcsv(std::string&);
std::list<Peak> findPeak(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak_longevent(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak_median(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak_manual(std::vector<float>&, std::unordered_map<std::string, double>&, double, double, float, float);
std::list<Peak> findPeak_cumsum(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak_parallel(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);

#endif // !TOOLS_H