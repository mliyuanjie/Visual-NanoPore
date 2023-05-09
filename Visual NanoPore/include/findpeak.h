#pragma once

#include <cmath>
#include <vector>
#include <math.h> 
#include <string>
#include <unordered_map>
#include <fstream>
#include <deque>
#include <set>
#include "tools.h"



class FindPeakRealTime {
public:
    FindPeakRealTime(double fs, double sigma, int resolution, int window, int k, int offset, bool ismedian);
    void append(std::vector<float>& data) { return (this->*_append)(data); };
    std::list<Peak> result;
    void append_average(std::vector<float>& data);
    void append_median(std::vector<float>& data);
private:
    void(FindPeakRealTime::* _append)(std::vector<float>&);
    double data = 0;
    double datapre = 0;
    double datasuf = 0;
    double fs = 0;
    double th = 0;
    double sigma = 0;
    size_t localminindex = 0;
    size_t localmaxindex = 0;
    double median = 0;
    double medianold = 0;
    double sd = 0;
    double stddev = 0;
    double mean = 0;
    double meanold = 0;
    double d2 = 0;
    double d = 0;
    double z = 0;
    double min = 0;
    double max = 0;
    size_t s = 0;
    size_t e = 0;
    size_t i = 0;
    int k = -1;
    int windowsizestart = 0;
    int windowsizeend = 0;
    bool flag = false;
    bool s0flag = false;
    double interval = 0;
    size_t offset;
    std::deque<std::pair<double, size_t>> quemin;
    std::deque<std::pair<double, size_t>> quemax;
    std::vector<double> peakcurrent;
    std::deque<double> windowend;
    std::deque<std::pair<double, size_t>> windowstart;
    std::multiset<double> medianset;
    double median_value;
};

class FindPeakRealTimeShort {
public:
    FindPeakRealTimeShort(double fs, double sigma, int resolution, int window, int k, int offset, int ismedian);
    void append(std::vector<float>& data) { return (this->*_append)(data); };
    std::list<Peak> result;
    void append_average(std::vector<float>& data);
private:
    void(FindPeakRealTimeShort::* _append)(std::vector<float>&);
    double data = 0;
    double datapre = 0;
    double datasuf = 0;
    double fs = 0;
    double th = 0;
    double sigma = 0;
    size_t localminindex = 0;
    size_t localmaxindex = 0;
    double median = 0;
    double medianold = 0;
    double sd = 0;
    double stddev = 0;
    double mean = 0;
    double meanold = 0;
    double d2 = 0;
    double d = 0;
    double z = 0;
    double min = 0;
    double max = 0;
    size_t s = 0;
    size_t e = 0;
    size_t i = 0;
    int k = -1;
    int windowsizestart = 0;
    int windowsizeend = 0;
    int maxtime = 0;
    int maxtimestep = 0;
    bool flag = false;
    bool s0flag = false;
    double interval = 0;
    size_t offset;
    std::deque<std::pair<double, size_t>> quemin;
    std::deque<std::pair<double, size_t>> quemax;
    std::vector<double> peakcurrent;
    std::deque<double> windowend;
    std::deque<std::pair<double, size_t>> windowstart;
    std::multiset<double> medianset;
    double median_value;
};

std::list<Peak> findPeak_manual(std::vector<float>&, std::unordered_map<std::string, double>&, double, double, double, double);
std::list<Peak> findPeak_parallel(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);
std::list<Peak> findPeak(std::vector<float>&, std::unordered_map<std::string, double>&, double, double);


