#include <numeric>
#include <algorithm>
#include <deque>
#include <time.h>
#include <Eigen/Dense>
#include <unsupported/Eigen/Polynomials>
#include <cmath>
#include <vector>
#include <Eigen/QR>
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

void polyfit(const std::vector<double>& t,
    const std::vector<double>& v,
    std::vector<double>& coeff,
    int order

)
{
    // Create Matrix Placeholder of size n x k, n= number of datapoints, k = order of polynomial, for exame k = 3 for cubic polynomial
    Eigen::MatrixXd T(t.size(), order + 1);
    Eigen::VectorXd V = Eigen::VectorXd::Map(&v.front(), v.size());
    Eigen::VectorXd result;

    // check to make sure inputs are correct
    assert(t.size() == v.size());
    assert(t.size() >= order + 1);
    // Populate the matrix
    for (size_t i = 0; i < t.size(); ++i)
    {
        for (size_t j = 0; j < order + 1; ++j)
        {
            T(i, j) = pow(t.at(i), j);
        }
    }

    // Solve for linear least square fit
    result = T.householderQr().solve(V);
    coeff.resize(order + 1);
    for (int k = 0; k < order + 1; k++)
    {
        coeff[k] = result[k];
    }

}

std::vector<int> extreminval(std::vector<float>& x, int s, int e, int k) {
    std::vector<int> l;
    if (s == 0 || e == x.size())
        return l;

    for (int i = s; i <= e; i++) {
        if (k * x[i] <= k * x[i - 1] && k * x[i] <= k * x[i + 1])
            l.push_back(i);
    }
    return l;
}

float meancurrent(std::vector<float>& data, int s, int e) {
    float res = 0;
    for (int i = s; i <= e; i++) {
        res = (res * (i - s) + data[i]) / (i - s + 1);
    }
    return res;
}

void moveBaseline(std::vector<float>& x, float* b, int window, int s, int e) {
    float sum = 0;
    for (int i = s; i < s + window / 2; i++) {
        sum += x[i];
    }
    b[0] = sum / window * 2;
    int pos = s;
    int poe = window / 2;
    for (int i = s+1; i < e; i++) {
        if (poe < window) {
            b[i - s] = (b[i - 1 - s] * (poe - pos) + x[poe]) / (poe - pos + 1);
            poe++;
        }
        else if (poe >= window && poe < e) {
            x[pos] = x[pos];
            b[i - s] = (b[i - 1 - s] * (poe - pos) + x[poe] - x[pos]) / (poe - pos);
            poe++;
            pos++;
        }
        else {
            b[i - s] = (b[i - 1 - s] * (poe - pos) - x[pos]) / (poe - pos - 1);
            pos++;
        }
    }
    return;
}

Baseline::Baseline(std::vector<float>& data, bool autob, int order, int resolution, int start, int end) {
    s = start;
    e = end;
    if (autob) {
        std::vector<double> t;
        std::vector<double> y;
        int skip = (e - s) / resolution;
        for (int i = s; i < e; i += skip) {
            t.push_back(double(i));
            double mean = meancurrent(data, i, ((i + skip) < e) ? (i + skip) : e - 1);
            y.push_back(mean);
        }
        polyfit(t, y, coeff, order);
    }
    else {
        b = new float[e - s];
        moveBaseline(data, b, resolution, s, e);
    }
}

float Baseline::at(int index) {
    if (b != NULL)
        return b[index - s];
    else {
        return Eigen::poly_eval(coeff, double(index));
    }
}

void Baseline::clear() {
    if (b != NULL)
        delete[] b;
}





std::list<Peak> findPeak(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
    int resolution = int(params["resolution"]);
    bool autob = (params["auto"] > 0) ? true : false;
    int order = int(params["order"]);
    double thres = params["threshold"];
    int window = int(params["window"]);
    double interval = params["interval"];
    int k = (params["direction"] >= 0) ? 1 : -1;
    auto iter = data.begin();
    double sum = std::accumulate(iter, std::next(iter, 100000), 0.0);
    double m = sum / 100000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 100000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (100000 - 1));
    int s = (sdouble * 1000 / interval >= 0) ? sdouble * 1000 / interval : 0;
    int e = (edouble * 1000 / interval > data.size()) ? data.size() : edouble * 1000 / interval;
    Baseline b = Baseline(data, autob, order, resolution, s, e);   
    std::list<Peak> res;
    float th = stdev * thres;
    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    int ps = 0;
    //double time1;
    
    for (int i = s; i < e; i++) {
        //clock_t times = clock();
        while (!quemin.empty() && quemin.back().first >= k*data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<float, int>(k*data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        //time1 += double(clock() - times)/ CLOCKS_PER_SEC;
        float min = quemin.front().first;
        if (k*data[i] < k*b.at(i) - th && !flag) {
            for (int j = i; j >= 1; j--) {
                if (k*data[j] >= k*data[j - 1] && k*data[j] >= k*data[j + 1] && k*data[j] > k*b.at(j) - stdev) {
                    Peak peak = { 0, 0, 0, 0 };
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    flag = true;
                    ps = i;
                    break;
                }
            }
        }
        else if (flag && min > k*b.at(i) - stdev) {
            for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
                if (k*data[j] <= k*data[j - 1] && k*data[j] <= k*data[j + 1] && k*data[j] < k*b.at(j) - 0.5 * th) {
                    res.back().end = float(j) * interval / 1000;
                    res.back().baseline = b.at(j);
                    std::vector<int> l = extreminval(data, ps, j, k);
                    if (l.size() == 1) {
                        res.back().currentpeak = data[l[0]];
                        if (abs(res.back().currentpeak - res.back().baseline) < th)
                            res.pop_back();
                        flag = false;
                    }
                    else if (l.size() > 1) {
                        res.back().currentpeak = meancurrent(data, ps, j);
                        if (abs(res.back().currentpeak - res.back().baseline) < th)
                            res.pop_back();
                        flag = false;
                    }
                    break;
                }
            }
            if (flag) {
                res.pop_back();
                flag = false;
            }
        }
    }
    if (flag)
        res.pop_back();
    b.clear();
    return res;
}

std::list<Peak> findPeak_manual(std::vector<float>& data, std::unordered_map<std::string, double>& params, double startpoint, double endpoint, float b) {
    double thres = params["threshold"];
    double interval = params["interval"];
    int k = (params["direction"] >= 0) ? 1 : -1;
    int window = int(params["window"]);
    auto iter = data.begin();
    std::list<Peak> res;
    double sum = std::accumulate(iter, std::next(iter, 100000), 0.0);
    double m = sum / 100000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 100000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (100000 - 1));
    float th = stdev * thres;
    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    int ps = 0;
    int s = (startpoint * 1000 / interval >= 0) ? startpoint * 1000 / interval : 0;
    int e = (endpoint * 1000 / interval > data.size()) ? data.size() : endpoint * 1000 / interval;
    //double time1;

    for (int i = s; i < e; i++) {
        //clock_t times = clock();
        while (!quemin.empty() && quemin.back().first >= k * data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<float, int>(k * data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        //time1 += double(clock() - times)/ CLOCKS_PER_SEC;
        float min = quemin.front().first;
        if (k * data[i] < k * b - th && !flag) {
            for (int j = i; j >= 1; j--) {
                if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * b - stdev) {
                    Peak peak = { 0, 0, 0, 0 };
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    flag = true;
                    ps = i;
                    break;
                }
            }
        }
        else if (flag && min > k * b - stdev) {
            for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
                if (k * data[j] <= k * data[j - 1] && k * data[j] <= k * data[j + 1] && k * data[j] < k * b - 0.5 * th) {
                    res.back().end = float(j) * interval / 1000;
                    res.back().baseline = b;
                    std::vector<int> l = extreminval(data, ps, j, k);
                    if (l.size() == 1) {
                        res.back().currentpeak = data[l[0]];
                        if (abs(res.back().currentpeak - res.back().baseline) < th)
                            res.pop_back();
                        flag = false;
                    }
                    else if (l.size() > 1) {
                        res.back().currentpeak = meancurrent(data, ps, j);
                        if (abs(res.back().currentpeak - res.back().baseline) < th)
                            res.pop_back();
                        flag = false;
                    }
                    break;
                }
            }
            if (flag) {
                res.pop_back();
                flag = false;
            }
        }
    }
    if (flag)
        res.pop_back();
    return res;
}
