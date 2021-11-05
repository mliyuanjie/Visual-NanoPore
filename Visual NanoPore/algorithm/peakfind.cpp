#include "peakfind.h"
#include "tools.h"


std::list<Peak> findPeak(float* x, int n, std::unordered_map<std::string, double> params) {
    double t = params["threshold"];
    double stepsize = params["stepsize"];
    double h = params["h"];
    double sd = 0;
    double min_gap = params["min_gap"];
    double min_cumsum = params["mint_cumsum"];
    double window = params["window"];
    int size = n; 

    sd = gsl_stats_sd(x, 1, 100000);
    std::vector<Peak> res;
    double th = sd * t;
    bool flag = false;
    std::deque<std::pair<double, int>> quemin;
    std::deque<std::pair<double, int>> quemax;

    for (int i = 0; i < size; i++) {

        while (!quemin.empty() && quemin.back().first >= x[i])
            quemin.pop_back();
        quemin.push_back(std::pair<double, int>(x[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        while (!quemax.empty() && quemax.back().first <= x[i])
            quemax.pop_back();
        quemax.push_back(std::pair<double, int>(x[i], i));
        while (quemax.front().second <= i - window)
            quemax.pop_front();
        double min = quemin.front().first;
        double max = quemax.front().first;

        double b = gsl_poly_eval(b_coeff, size_coeff, i);
        if (x[i] < b - th && !flag) {
//            if (res.size() > 0 && i <= res.back().finish + int(min_gap)) {
//                flag = true;
//                continue;
//            }
            for (int j = i; j >= 1; j--) {
                if (x[j] >= x[j - 1] && x[j] >= x[j + 1] && x[j] > b - sd) {
                    Peak peak = { 0, 0, 0, 0, 0, 0, std::vector<int>(), std::vector<double>() };
                    res.push_back(peak);
                    res.back().start = j;
                    flag = true;
                    break;
                }
            }
        }
        if (flag && min > b - sd) {
            for (int j = i; j > res.back().start; j--) {
                if (x[j] <= x[j - 1] && x[j] <= x[j + 1] && x[j] < b - 0.8 * th) {
                    res.back().end = j;
                    int length = 200;
                    res.back().begin = (res.back().start - length >= 0) ? res.back().start - length : 0;
                    res.back().finish = (res.back().end + length < size) ? res.back().end + length : size - 1;
                    int ps = res.back().end;
                    for (int j = res.back().start; j <= res.back().end; j++) {
                        if (x[j] <= x[j - 1] && x[j] <= x[j + 1] && x[j] < b - th) {
                            ps = j;
                            break;
                        }
                    }
                    res.back().currentbase = b;
                    auto l = extreminval(x, ps, res.back().end);
                    if (l.size() <= 2) {
                        int k = argmin(x, ps, res.back().end);
                        res.back().currentmax = res.back().currentbase - x[k];
                    }
                    else {
                        res.back().currentmax = res.back().currentbase - meancurrent(x, size, ps, res.back().end);
                    }

                    if (res.back().end - res.back().start > int(min_cumsum))
                        cumSum(x, size, ps, res.back().end, stepsize, h, sd, res.back().index, res.back().level);
                    flag = false;
                    break;
                }
            }
            if (res.back().end == 0) {
                flag = false;
                res.pop_back();
            }
        }
    }
    if (res.back().end == 0)
        res.pop_back();

    //convert to python object
    p::dict y;
    p::list p1, p2, p3, p4, p5, p6, p7, p8, p9;

    for (int i = 0; i < res.size(); i++) {
        p::list index;
        p::list level;
        p1.append(res[i].start);
        p2.append(res[i].end);
        p3.append(res[i].begin);
        p4.append(res[i].finish);
        p5.append(res[i].currentbase);
        p6.append(res[i].currentmax);
        if (res[i].index.size() > 0)
            index.append(res[i].index[0]);
        for (int j = 1; j < res[i].index.size(); j++) {
            index.append(res[i].index[j]);
            level.append(res[i].level[j - 1]);
        }
        p7.append(index);
        p8.append(level);
        p9.append(res[i].index.size());
    }
    y["start"] = p1;
    y["end"] = p2;
    y["i"] = p3;
    y["j"] = p4;
    y["I0"] = p5;
    y["DI"] = p6;
    y["jump"] = p7;
    y["level"] = p8;
    y["states"] = p9;
    delete[] x;
    delete[] b_coeff;
    return y;
}
