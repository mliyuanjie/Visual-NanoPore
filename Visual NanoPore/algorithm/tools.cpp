#include <numeric>
#include <algorithm>
#include <deque>
#include <set>
#include <time.h>
#include <Eigen/Dense>
#include <unsupported/Eigen/Polynomials>
#include <cmath>
#include <vector>
#include <Eigen/QR>
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

