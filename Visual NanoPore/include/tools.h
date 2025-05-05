#pragma once
#ifndef TOOLS_H
#define TOOLS_H 
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <random>

#define M_PI 3.141592653

struct Peak {
    double start;
    double end;
    double currentpeak;
    double baseline;
    int s;
    int e;
    int s0;
    double Imin;
    double Imax;
    double shape_o;
    double volume_o;
    double shape_p;
    double volume_p;
    bool operator<(const Peak& val) const {
        return s < val.s;
    }
};

struct Physical {
    double rp;
    double lp;
    double er;
    double vol;
};


template <typename T>
T meancurrent(std::vector<T>& data, size_t s, size_t e) {
    T mean = 0;
    if (e > data.size() || s >= data.size())
        return 0;
    for (size_t i = s; i < e; i++) {
        mean += (data[i] - mean) / (i + 1 - s);
    }
    return mean;
}

template <typename T>
T calsd(std::vector<T>& data, size_t s, size_t e) {
    if (e - s < 30000) {
        double m = meancurrent(data, s, e);
        double accum = 0.0;
        for (size_t i = s; i < e; i++)
            accum += (data[s] - m) * (data[e] - m);
        T sd = sqrt(accum / (e - s));
        return sd;
    }
    T sd = 0;
    std::random_device seed;
    std::mt19937 gen{ seed() };
    std::uniform_int_distribution<int> dist{ (int)s, (int)(e - 20000) };
    int n = 0;
    while (n < 20) {
        auto iter = dist(gen);
        double m = meancurrent(data, iter, iter + 20000);
        double accum = 0.0;
        for (int i = 0; i < 20000; i++)
            accum += (data[iter + i] - m) * (data[iter + i] - m);
        T stdev = sqrt(accum / (20000 - 1));
        if (n == 0) {
            sd = stdev;
        }
        else {
            sd = (stdev < sd) ? stdev : sd;
        }
        n++;
    }
    return sd;
}

template <typename T>
std::vector<int> extreminval(std::vector<T>& x, int s, int e, int k) {
    std::vector<int> l;
    if (s == 0 || e == x.size())
        return l;

    for (int i = s; i <= e; i++) {
        if (k * x[i] <= k * x[i - 1] && k * x[i] <= k * x[i + 1])
            l.push_back(i);
    }
    return l;
}

std::unordered_map<std::string, double> readconfig(std::string);
std::list<Peak> readcsv(std::string&);
float Efield(Physical& p);
float gvalue(Physical& p);
void oblate(std::vector<float>& m, std::vector<float>& y);
void prolate(std::vector<float>& m, std::vector<float>& y);
void volum_shape(std::vector<float>& data, Peak& peak, float imin, float imax, float g, std::vector<float>& m_o, std::vector<float>& y_o, std::vector<float>& m_p, std::vector<float>& y_p);



#endif // !TOOLS_H