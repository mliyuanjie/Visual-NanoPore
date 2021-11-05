#include <numeric>
#include <algorithm>
#include <deque>
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

std::vector<int> extreminval(std::vector<float>& x, int s, int e) {
    std::vector<int> l;
    for (int i = s; i < e; i++) {
        if (x[i] <= x[i - 1] && x[i] <= x[i + 1])
            l.push_back(i);
    }
    return l;
}

float meancurrent(std::vector<float> &data, int s, int e) {
    float b = 0;
    for (int i = s; i <= e; i++) {
        b += data[i];
    }
    return b / (e - s + 1);
}

std::list<Peak> findPeak(std::vector<float>& data, std::unordered_map<std::string, double> params) {
    double t = params["threshold"];
    double min_gap = params["min_gap"];
    double window = params["window"];
    double interval = params["interval"];

    auto iter = data.begin();
    double sum = std::accumulate(iter, std::next(iter, 100000), 0.0);
    double m = sum / 100000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 100000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    double stdev = sqrt(accum / (100000 - 1));


    std::list<Peak> res;
    double th = stdev * t;
    bool flag = false;
    std::deque<std::pair<double, int>> quemin;
    std::deque<std::pair<double, int>> quemax;

    for (int i = 0; i < data.size(); i++) {

        while (!quemin.empty() && quemin.back().first >= data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<double, int>(data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        while (!quemax.empty() && quemax.back().first <= data[i])
            quemax.pop_back();
        quemax.push_back(std::pair<double, int>(data[i], i));
        while (quemax.front().second <= i - window)
            quemax.pop_front();
        double min = quemin.front().first;
        double max = quemax.front().first;
        int ps = 0;
        float b = getbaseline(data, i, params["resolution"]);
        if (data[i] < b - th && !flag) {
            for (int j = i; j >= 1; j--) {
                if (data[j] >= data[j - 1] && data[j] >= data[j + 1] && data[j] > b - stdev) {
                    Peak peak = { 0, 0, 0, 0 };
                    res.push_back(peak);
                    res.back().start = double(j) * interval / 1000;
                    flag = true;
                    ps = i;
                    break;
                }
            }
        }
        else if (flag && min > b - stdev) {
            for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
                if (data[j] <= data[j - 1] && data[j] <= data[j + 1] && data[j] < b - th) {
                    res.back().end = double(j) * interval / 1000;
                    res.back().baseline = b;
                    auto l = extreminval(data, ps, j);
                    if (l.size() == 1)
                        res.back().currentpeak = data[l[0]];
                    else if (l.size() > 1)
                        res.back().currentpeak = meancurrent(data, ps, int(res.back().end * 1000 / interval));
                    flag = false;
                    break;
                }
            }
            if (res.back().currentpeak == 0) {
                flag = false;
                res.pop_back();
            }
        }
    }
    if (res.back().end == 0)
        res.pop_back();
    return res;
}

float getbaseline(std::vector<float>& data, int index, int window) {
    int s = ((index - window / 2) >= 0) ? index - window / 2 : 0;
    int e = ((index + window / 2) <= data.size()) ? index + window / 2 : data.size();
    float cum = 0;
    for (int i = s; i < e; i++)
        cum += data[i];
    return cum / (e - s);
}