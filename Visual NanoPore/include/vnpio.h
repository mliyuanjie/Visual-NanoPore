#ifndef VNPIO_H
#define VNPIO_H

#include <hdf5.h>
#include <hdf5_hl.h>
#include <vector>
#include <list>
#include <fstream>
#include "tools.h"


class VNPIO {
public:
	void open(std::string);
	void create(std::string);
	void close();
	void creategroup(std::string);
	std::string getdatapath(std::string);
	void createattri(std::string fn, std::unordered_map<std::string, double> map);
	void removegroup(std::string);
	std::vector<std::string> getfilelist();
	std::list<Peak> geteventlist(std::string);
	std::list<std::pair<double, double>> getdatadone(std::string);
	double getinterval(std::string);
	void seteventlist(std::string, std::list<Peak>&);
	void setdatadone(std::string, std::list<std::pair<double, double>>&);
	inline bool is_file_exist(std::string fileName) {
		return std::ifstream(fileName).good();
	}
private:
	std::string filename;
	hid_t file;
	herr_t status;
};
#endif //VNPIO_H
