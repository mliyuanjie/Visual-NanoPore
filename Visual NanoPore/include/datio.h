#ifndef DATIO_H
#define DATIO_H

#include <string>
#include <vector>
#include <cmath>
#include <boost/iostreams/device/mapped_file.hpp>

class DATIO {
public:
	std::vector<float> data(size_t start = 0, size_t end = 0, size_t skip = 1);
	void close();
	void open(std::string, int);
	float interval() { return interv; };
	int size() { return int(n); };
	float valmin(size_t start = 0, size_t end = 0);
	float valmax(size_t start = 0, size_t end = 0);
	float at(size_t);
	float baseline(size_t start, size_t end);
	std::pair<float, float> valminmax(size_t start = 0, size_t end = 0);
	std::pair<float, float> meansd(size_t start = 0, size_t end = 0);
	void buildpyramid();
	std::vector<float> datafig(size_t start, size_t end);
	float* cdata();
	std::string getfilename() { return currentfilename; };
private:
	float interv;
	size_t n = size_t(0);
	boost::iostreams::mapped_file_source file;
	boost::iostreams::mapped_file filepyramid;
	float* pospyramid;
	std::vector<int> layer;
	int id;
	float* pos;
	std::string currentfilename;
};
#endif //DATIO_H