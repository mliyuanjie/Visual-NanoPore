#include <numeric>
#include <algorithm>
#include <deque>
#include <set>
#include <time.h>
#include <cmath>
#include <vector>
#include <omp.h>
#include "tools.h"

std::unordered_map<std::string, double> readconfig(std::string fn) {
    std::ifstream myfile(fn);
    std::unordered_map <std::string, double> params;
    std::string key;
    double value;
    while (myfile >> key) {
        if (key[0] == '*' || key[0] == '#')
            myfile.ignore(100000, '\n');
        else {
            myfile >> value;
            params[key] = value;
        }
    }
    myfile.close();
    return params;
}

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector < std::string > tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

std::list<Peak> readcsv(std::string& filename) {
    std::ifstream file(filename);
    std::list<Peak> res;
    std::string line;
    std::getline(file, line);
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int i9 = 0, i10 = 0, i11 = 0, i12 = 0;
    std::vector<std::string> r = split(line, ",");
    for (int i = 0; i < r.size(); i++) {
        if (r[i].compare("start(ms)") == 0)
            i0 = i;
        else if (r[i].compare("end(ms)") == 0)
            i1 = i;
        else if (r[i].compare("I0(pA)") == 0)
            i2 = i;
        else if (r[i].compare("I1(pA)") == 0)
            i3 = i;
        else if (r[i].compare("start") == 0)
            i4 = i;
        else if (r[i].compare("end") == 0)
            i5 = i;
        else if (r[i].compare("begin") == 0)
            i6 = i;
        else if (r[i].compare("Imin") == 0)
            i7 = i;
        else if (r[i].compare("Imax") == 0)
            i8 = i;
        else if (r[i].compare("shape_o_m") == 0)
            i9 = i;
        else if (r[i].compare("volume_o_m") == 0)
            i10 = i;
        else if (r[i].compare("shape_p_m") == 0)
            i11 = i;
        else if (r[i].compare("volume_p_m") == 0)
            i12 = i;
    }
    
    while (std::getline(file, line)) {
        r = split(line, ",");
        if (!isNumber(r[i5]))
            continue;
        Peak vs = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vs.start = std::stod(r[i0]);
        vs.end = std::stod(r[i1]);
        vs.baseline = std::stod(r[i2]);
        vs.currentpeak = std::stod(r[i3]);
        vs.s = std::stoi(r[i4]);
        vs.e = std::stoi(r[i5]);
        if (i7 != 0) {
            vs.Imax = std::stod(r[i8]);
            vs.Imin = std::stod(r[i7]);
            vs.shape_o = std::stod(r[i9]);
            vs.volume_o = std::stod(r[i10]);
            vs.shape_p = std::stod(r[i11]);
            vs.volume_p = std::stod(r[i12]);
        }
        if (i6 != 0)
            vs.s0 = std::stoi(r[i6]);
        res.push_back(vs);
    }
    file.close();
    return res;
}

float Efield(Physical& p) {
    float e;
    e = p.vol * (p.er * p.lp / (M_PI * p.rp * p.rp)) / (p.er * p.lp / (M_PI * p.rp * p.rp) + p.er / (2 * p.rp)) / p.lp;
    return e;
}

float gvalue(Physical& p) {
    float g;
    g = 1 / (M_PI * p.rp * p.rp * (p.lp + 1.6 * p.rp));
    return g;
}

void oblate(std::vector<float>& m, std::vector<float>& y) {
    float t;
    float k;
    for (int i = 0; i < 999; i++) {
        k = 0.001 * (i + 1);
        m[998 - i] = k;
        y[998 - i] = 1 / (k * std::acos(k) / pow((1 - k * k), 1.5) - k * k / (1 - k * k));
    }
    return;
}

void prolate(std::vector<float>& m, std::vector<float>& y) {
    float t;
    float k;
    for (int i = 0; i < 999; i++) {
        k = (0.1 * (i + 1)) / 2 + 1;
        m[998 - i] = k;
        y[998 - i] = 1 / (k * k / (k * k - 1) - k * acosh(k) / pow((k * k - 1), 1.5));
    }
    return;
}

void volum_shape(std::vector<float>& data, Peak& peak, float imin0, float imax0, float g, std::vector<float>& m_o, std::vector<float>& y_o, std::vector<float>& m_p, std::vector<float>& y_p) {
    int Imin_number = int(imin0 / 100 * data.size()); 
    int Imax_number = int(imax0 / 100 * data.size());
    if (Imax_number <= Imin_number) return;
    if (Imin_number < 0 || Imin_number >= data.size()) return;
    if (Imax_number < 0 || Imax_number >= data.size()) return;
    std::sort(data.begin(), data.end()); // please try the tree kth algorithm for faster 
    float Imin = data[Imin_number];
    float Imax = data[Imax_number];
    float F_max_o = Imax / Imin + 0.5;
    float F_min_p = Imin / Imax + 0.5;
    auto index = std::lower_bound(y_o.begin(), y_o.end(), F_max_o) - y_o.begin(); 
    if (index < 0) index = 0;
    if (index >= 999) index = 998;
    peak.shape_o = m_o[index];
    index = std::lower_bound(y_p.begin(), y_p.end(), F_min_p) - y_p.begin();
    if (index < 0) index = 0;
    if (index >= 999) index = 998;
    peak.shape_p = m_p[index];
    peak.volume_o = Imax / (g * F_max_o * 1e-27);
    peak.volume_p = Imin / (g * F_min_p * 1e-27);
    peak.Imin = Imin;
    peak.Imax = Imax;
    return;
}
