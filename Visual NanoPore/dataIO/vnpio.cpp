#include <sstream>
#include <unordered_map>
#include "vnpio.h" 

herr_t op_func(hid_t loc_id, const char* name, const H5O_info_t* info, void* opdata) {
	auto vec = static_cast<std::vector<std::string>*>(opdata);
	if (info->type == H5O_TYPE_GROUP) {
		vec->push_back(std::string(name));
	}
	return 0;
}

std::vector<std::string> split(const std::string& s, char delim) {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
		// elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
	}
	return elems;
}

void VNPIO::open(std::string fn) {
	filename = fn;
	file = H5Fopen(fn.c_str(), H5F_ACC_RDWR, H5P_DEFAULT);

}

void VNPIO::create(std::string fn) {
	filename = fn;
	file = H5Fcreate(fn.c_str(), H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
}

std::vector<std::string> VNPIO::getfilelist() {
	std::vector<std::string> vec;
	status = H5Ovisit(file, H5_INDEX_NAME, H5_ITER_NATIVE, op_func, static_cast<void*>(&vec), H5O_INFO_BASIC);
	return vec;
}

std::list<Peak> VNPIO::geteventlist(std::string fn) {
	std::list<Peak> res;
	hsize_t dims[2] = { 1,1 };
	double* rdata;
	hid_t dset = H5Dopen(file, fn.c_str(), H5P_DEFAULT);
	hid_t space = H5Dget_space(dset);
	hid_t ndims = H5Sget_simple_extent_dims(space, dims, NULL);
	rdata = new double[dims[0]*4];
	status = H5Dread(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, rdata);
	for (int i = 0; i < dims[0]; i++) {
		Peak event = { int(rdata[i * 4]), int(rdata[i * 4 + 1]), rdata[i * 4 + 2], rdata[i * 4 + 3] };
		res.push_back(event);
	}
	delete[] rdata;
	status = H5Dclose(dset);
	status = H5Sclose(space);
	return res;
}

std::list<std::pair<double, double>> VNPIO::getdatadone(std::string fn) {
	std::list<std::pair<double, double>> res;
	hsize_t dims[2] = { 1,1 };
	double* rdata;
	hid_t dset = H5Dopen(file, fn.c_str(), H5P_DEFAULT);
	hid_t space = H5Dget_space(dset);
	hid_t ndims = H5Sget_simple_extent_dims(space, dims, NULL);
	rdata = new double[dims[0] * 2];
	status = H5Dread(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, rdata);
	for (int i = 0; i < dims[0]; i++) {
		res.push_back(std::pair<int, int>(rdata[i * 2], rdata[i * 2 + 1]));
	}
	delete[] rdata;
	status = H5Dclose(dset);
	status = H5Sclose(space);
	return res;
}

 void VNPIO::seteventlist(std::string fn, std::list<Peak>& eventlist) {
	hsize_t dims[2] = { eventlist.size(), 4 };
	double* wdata;
	wdata = new double[dims[0] * 4];
	std::list<Peak>::iterator it = eventlist.begin();
	for (int i = 0; i < dims[0]; i++) {
		wdata[i*4] = (*it).start;
		wdata[i*4+1] = (*it).end;
		wdata[i*4+2] = (*it).currentpeak;
		wdata[i*4+3] = (*it).baseline;
		++it;
	}

	status = H5Ldelete(file, fn.c_str(), H5P_DEFAULT);
	hid_t space = H5Screate_simple(2, dims, NULL);
	hid_t dset = H5Dcreate(file, fn.c_str(), H5T_NATIVE_DOUBLE, space, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
	status = H5Dwrite(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, wdata);
	status = H5Dclose(dset);
	H5Sclose(space);
	delete[] wdata;
	return;
}

void VNPIO::setdatadone(std::string fn, std::list<std::pair<double, double>>& datalist) {
	hsize_t dims[2] = { datalist.size(), 2 };
	double* wdata;
	wdata = new double[dims[0]*2];
	std::list<std::pair<double, double>>::iterator it = datalist.begin();
	for (int i = 0; i < dims[0]; i++) {
		wdata[i*2+0] = (*it).first;
		wdata[i*2+1] = (*it).second;
		++it;
	}
	status = H5Ldelete(file, fn.c_str(), H5P_DEFAULT);
	hid_t space = H5Screate_simple(2, dims, NULL);
	hid_t dset = H5Dcreate(file, fn.c_str(), H5T_NATIVE_DOUBLE, space, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
	status = H5Dwrite(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, wdata);
	status = H5Dclose(dset);
	H5Sclose(space);
	delete[] wdata;
	return;
}

void VNPIO::creategroup(std::string fn) {
	hid_t group = H5Gcreate(file, ("/"+fn.substr(0, fn.length() - 4)).c_str(), H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
	H5Gclose(group);
}

void VNPIO::createattri(std::string fn, std::unordered_map<std::string, double> map) {
	hid_t group = H5Gopen(file, ("/" + fn.substr(0, fn.length() - 4)).c_str(), H5P_DEFAULT);
	for (std::pair<std::string, double> i : map) {
		hid_t dspace = H5Screate(H5S_SCALAR);
		hid_t attr = H5Acreate(group, i.first.c_str(), H5T_NATIVE_DOUBLE, dspace, H5P_DEFAULT, H5P_DEFAULT);
		H5Awrite(attr, H5T_NATIVE_DOUBLE, &i.second);
		H5Sclose(dspace);
		H5Aclose(attr);
	}
	H5Gclose(group);
}

void VNPIO::removegroup(std::string fn) {
	H5Ldelete(file, fn.c_str(), H5P_DEFAULT);
}

double VNPIO::getinterval(std::string fn) {
	hid_t group = H5Gopen(file, fn.c_str(), H5P_DEFAULT);
	hid_t attr = H5Aopen(group, "interval", H5P_DEFAULT);
	double res;
	H5Aread(attr, H5T_NATIVE_DOUBLE, &res);
	H5Aclose(attr);
	H5Gclose(group);
	return res;
}

void VNPIO::close() {
	H5Fclose(file);
}


