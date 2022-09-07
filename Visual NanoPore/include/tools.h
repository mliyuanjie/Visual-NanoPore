#ifndef TOOLS_H
#define TOOLS_H 
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <string>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_filter.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_fft_complex.h>
#include <unordered_map>
#include <fstream>


struct Peak {
	double start;
	double end;
	double currentpeak;
	double baseline;
};

class Baseline {
public:
	Baseline(std::vector<float>& data, bool autob, int order, int resolution, int start, int end);
	float at(int);
	void clear();
	std::vector<double> coeff;
	float* b = NULL;

private:
	int s;
	int e;
};

std::unordered_map<std::string, double> readconfig(std::string);
std::list<Peak> findPeak(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak_manual(std::vector<float>&, std::unordered_map<std::string, double>&, double, double, float, float);
#endif // !TOOLS_H