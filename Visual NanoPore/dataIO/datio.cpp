#include <algorithm>
#include <fstream>
#include "datio.h" 



void DATIO::open(std::string fn, int num) {
	close();
	if (fn.substr(fn.length() - 3, 3) != "dat")
		return;
	file.open(fn);
	currentfilename = fn;
	size_t length = file.size();
	if (length == 0)
		return;
	n = length / sizeof(float);
	pos = (float*)file.data();
	id = num;
	buildpyramid();
	//filepyramid.open("datapyramid" + std::to_string(id) + ".dat");
	//pospyramid = (float*)filepyramid.data();
	return;
}

float* DATIO::cdata() {
	return pos;
}

void DATIO::buildpyramid() {
	layer.clear();
	bool flag = false;
	float min = FLT_MAX;
	float max = -FLT_MAX;

	int e = 0;
	int ntmp = ceil(double(n) / 2);
	while (ntmp > 3000) {
		e += ntmp;
		ntmp = ceil(double(ntmp) / 2);
	}
	

	std::ofstream wf;
	wf.open("_history_can_delete_" + std::to_string(id) + ".dat", std::ios::out | std::ios::trunc);
	wf.seekp(e * sizeof(float)-1);
	wf.write("0", 1);
	wf.close();

	filepyramid.open("_history_can_delete_" + std::to_string(id) + ".dat");
	pospyramid = (float*)filepyramid.data();

	e = 0;
	ntmp = ceil(double(n) / 2);
	layer.push_back(0);
	while (ntmp > 3000) {
		if (e == 0) {
			for (int i = 0; i < ntmp; i += 2) {
				min = FLT_MAX;
				max = -FLT_MAX;
				for (int j = 0; j < 4 && 2 * i + j < n; j++) {
					if (pos[2 * i + j] < min) {
						min = pos[2 * i + j];
						flag = false;
					}
					if (pos[2 * i + j] > max) {
						max = pos[2 * i + j];
						flag = true;
					}
				}
				if (i + 1 == ntmp) {
					pospyramid[i] = min;
					break;
				}
				if (flag) {
					pospyramid[i] = min;
					pospyramid[i + 1] = max;
				}
				else {
					pospyramid[i] = max;
					pospyramid[i + 1] = min;
				}
			}
		}
		else {
			int epre = layer[layer.size() - 2];
			for (int i = e; i < ntmp + e; i += 2) {
				min = FLT_MAX;
				max = -FLT_MAX;
				for (int j = 0; j < 4 && 2 * (i - e) + j + epre < e; j++) {
					if (pospyramid[2 * i + j - 2 * e + epre] < min) {
						min = pospyramid[2 * i + j - 2 * e + epre];
						flag = false;
					}
					if (pospyramid[2 * i + j - 2 * e + epre] > max) {
						max = pospyramid[2 * i + j - 2 * e + epre];
						flag = true;
					}
				}
				if (i + 1 == ntmp + e) {
					pospyramid[i] = min;
					break;
				}
				if (flag) {
					pospyramid[i] = min;
					pospyramid[i + 1] = max;
				}
				else {
					pospyramid[i] = max;
					pospyramid[i + 1] = min;
				}
			}
		}
		e += ntmp;
		layer.push_back(e);
		ntmp = ceil(double(ntmp) / 2);
	}
	

	return;
}

void DATIO::close() {
	if (file.is_open())
		file.close();
	if (filepyramid.is_open())
		filepyramid.close();
	pos = nullptr;
	pospyramid = nullptr;
	n = size_t(0);
	return;
}


std::vector<float> DATIO::data(size_t start, size_t end, size_t skip) {
	if (!file.is_open())
		return std::vector<float>();
	end = (end == 0 || end > n) ? n : end;
	skip = (skip == 0) ? 1 : skip;
	std::vector<float> res((end - start) / skip);
	size_t j = 0;
	for (size_t i = start; i < end; i += skip) {
		res[j] = pos[i];
		j++;
	}
	return res;
}

std::vector<float> DATIO::datafig(size_t start, size_t end) {
	int s = start;
	int e = end;
	int ntotal = e - s;
	int numlayer = 0;
	while (ntotal > 6000) {
		s = floor(double(s) / 2);
		e = ceil(double(e) / 2);
		numlayer++;
		ntotal = e - s;
	}
	if (numlayer == 0) {
		return data(s, e, 1);
	}
	s += layer[numlayer-1];
	e += layer[numlayer-1];
	if (e > layer[numlayer]) 
		e = layer[numlayer];	
	std::vector<float> res(e - s);
	int j = 0;
	for (int i = s; i < e; i++) {
		res[j] = pospyramid[i];
		j++;
	}
	return res;
}

float DATIO::valmax(size_t start, size_t end) {
	if (!file.is_open())
		return 0;
	end = (end == 0 || end > n) ? n : end;
	float res = pos[start];
	float tmp;
	for (size_t i = start + 1; i < end; i++) {
		tmp = pos[i];
		res = (tmp > res) ? tmp : res;
	}
	return res;
}

float DATIO::valmin(size_t start, size_t end) {
	if (!file.is_open())
		return 0;
	end = (end == 0 || end > n) ? n : end;
	float res = pos[start];
	float tmp;
	for (size_t i = start + 1; i < end; i++) {
		tmp = pos[i];
		res = (tmp < res) ? tmp : res;
	}
	return res;
}

std::pair<float, float> DATIO::valminmax(size_t start, size_t end) {
	if (!file.is_open())
		return std::pair<float, float>(0,0);
	end = (end == 0 || end > n) ? n : end;
	float xmin = pos[start];
	float xmax = xmin;
	float tmp;
	bool direction = false;
	for (int i = start + 1; i < end; i++) {
		tmp = pos[i];
		if (tmp < xmin) {
			xmin = tmp;
			direction = false;
		}
		if (tmp > xmax) {
			xmax = tmp;
			direction = true;
		}
	}
	if(direction)
		return std::pair<float, float>(xmin, xmax);
	return std::pair<float, float>(xmax, xmin);
}

float DATIO::at(size_t i) {
	if (i >= n)
		return 0;
	return pos[i];
}

float DATIO::baseline(size_t start, size_t end) {
	float sum = 0;
	int num = 0;
	for (size_t i = start; (i > 0) && (i > (start - 2000)); i--) {
		sum += pos[i];
		num++;
	}
		
	for (size_t i = end; (i < n) && (i < (end + 2000)); i++) {
		sum += pos[i];
		num++;
	}
	return sum / num;
}

std::pair<float, float> DATIO::meansd(size_t start, size_t end) {
	if (!file.is_open())
		return std::pair<float, float>(0, 0);
	end = (end == 0 || end > n) ? n : end;
	double mean = 0;
	double sd = 0;
	for (size_t i = start; i < end; i++) {
		mean += pos[i];
	}
	mean = mean / (end - start);
	for (size_t i = start; i < end; i++) {
		sd += pow(pos[i] - mean, 2);
	}
	sd = sqrt(sd / (end - start));
	return std::pair<float, float>(mean, sd);
}
