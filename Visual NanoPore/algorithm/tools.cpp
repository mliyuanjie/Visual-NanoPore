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

float mediancurrent(std::vector<float> data) {
    auto mid = data.begin() + data.size() / 2;
    std::nth_element(data.begin(), mid, data.end());
    return *mid;
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
    double res = 0;
    for (int i = s; i <= e; i++) {
        res = (res * (i - s) + data[i]) / (i - s + 1);
    }
    return res;
}

void moveBaseline(std::vector<float>& x, float* b, int window, int s, int e) {
    double sum = 0;
    for (int i = s; i < s + window / 2; i++) {
        sum += double(x[i]);
    }
    b[0] = sum / window * 2;
    int pos = s;
    int poe = s + window / 2;
    for (int i = s+1; i < e; i++) {
        if (poe < window) {
            b[i - s] = (b[i - 1 - s] * (poe - pos) + x[poe]) / (poe - pos + 1);
            poe++;
        }
        else if (poe >= window && poe < e) {
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

Baseline::Baseline(std::vector<float>& data, int autob, int order, int resolution, int start, int end) {
    s = start;
    e = end;
    if (autob == 1) {
        std::vector<double> t;
        std::vector<double> y;
        int skip = (e - s) / resolution;
        for (int i = s; i < e; i += skip) {
            t.push_back(double(i));
            int j = ((i + skip) < e) ? (i + skip) : e - 1;
            auto mid = data.begin() + (j - i + 1) / 2;
            float median = mediancurrent(std::vector<float>(data.begin() + i, data.begin() + j));
            y.push_back(median);
        }
        polyfit(t, y, coeff, order);
    }
    else if(autob==0) {
        b = new float[e - s];
        moveBaseline(data, b, resolution, s, e);
    }
    else {
        b = new float[e - s];
        for (int i = 0; i < e - s; i++) {
            b[i] = 0;
        }
    }
}

float Baseline::operator[](int index) {
    if (b != NULL)
        return b[index - s];
    else {
        return Eigen::poly_eval(coeff, double(index));
    }
}

void Baseline::set(int index, float val) {
    if (b != NULL) {
        b[index - s] = val;
    }
}

void Baseline::clear() {
    if (b != NULL)
        delete[] b;
}

double calbaseline(std::vector<float>& data, int pos, int pree, int s) {
    double res = 0;
    int count = 0;
    while (count < 3000) {
        res += data[pos];
        count++;
        pos--;
        if (pos <= s || pos <= pree) {
            return res / count;
        }
    }
    return res / 3000;
}

void calsd(std::vector<float>& data, int s, int e, float& sd) {
    int n = 0;
    int i = s;
    while (i < e - 5000 && n < 20) {
        auto iter = data.begin() + s;
        double sum = std::accumulate(iter, std::next(iter, 5000), 0.0);
        double m = sum / 5000;
        double accum = 0.0;
        std::for_each(iter, std::next(iter, 5000), [&](const double d) {
            accum += (d - m) * (d - m);
        });
        float stdev = sqrt(accum / (5000 - 1));
        if (n == 0) {
            sd = stdev;
        }
        else {
            sd = (stdev < sd) ? stdev : sd;
        }
        n++;
        i += 5000;
    }
    return;
}

void adaptmoverage(std::vector<float>& data, Baseline& b, int pos, int s, int resolution) {
    int min_resolution = resolution / 100;
    if (pos == s) {
        double baseline = 0;
        for (int i = 0; i < min_resolution; i++) {
            baseline += data[pos + i];
            b.set(pos, baseline / min_resolution);
        }
    }
    else if (pos - s < min_resolution)
        b.set(pos, b[pos - 1]);
    else if (pos - s < resolution)
        b.set(pos, (double(b[pos - 1]) * (pos - s) + data[pos]) / double(pos - s + 1));
    else
        b.set(pos, (double(b[pos - 1]) * resolution - data[pos-resolution] + data[pos]) / double(resolution));
}

double getmoverage(std::vector<float>& data, Baseline& b, int pos, int min_resolution) {
    double baseline = 0;
    for (int i = 0; i < min_resolution; i++) {
        baseline += data[pos - i];
    }
    return  baseline / min_resolution;

}

std::list<Peak> findPeak_cumsum(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
    if (data.size() == 0)
        return std::list<Peak>();
    double interval = params["interval"];
    int resolution = int(params["resolution"]);
    int k = (params["direction"] >= 0) ? 1 : -1;
    int window = int(params["window"]);
    double thres = params["threshold"];
    std::list<Peak> res;

    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    int s = (sdouble * 1000 / interval >= 0) ? sdouble * 1000 / interval : 0;
    int e = (edouble * 1000 / interval > data.size()) ? data.size() : edouble * 1000 / interval;
    //stddev calculate
    auto iter = data.begin() + s;
    double sum = std::accumulate(iter, std::next(iter, 20000), 0.0);
    double m = sum / 20000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 20000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (20000 - 1));
    double th = thres * stdev;
}

std::list<Peak> findPeak_longevent(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
    if (data.size() == 0)
        return std::list<Peak>();
    double interval = params["interval"];
    int resolution = int(params["resolution"]);
    int k = (params["direction"] >= 0) ? 1 : -1;
    int window = int(params["window"]);
    double thres = params["threshold"];
    std::list<Peak> res;

    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    std::deque<std::pair<float, int>> quemax;
    int s = (sdouble * 1000 / interval >= 0) ? sdouble * 1000 / interval : 0;
    int e = (edouble * 1000 / interval > data.size()) ? data.size() : edouble * 1000 / interval;
    //stddev calculate
    auto iter = data.begin() + s;
    double sum = std::accumulate(iter, std::next(iter, 20000), 0.0);
    double m = sum / 20000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 20000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (20000 - 1));
    double th = thres * stdev;

    //calculate baseline
    Baseline b(data, 2, 0, resolution, s, e);
    int level = 0;
    int ps = s;
    int pe = s;

    flag = false;

    for (int i = s; i < e; i++) {
        
        //clock_t times = clock();
        while (!quemin.empty() && quemin.back().first >= k * data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<float, int>(k * data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        //time1 += double(clock() - times)/ CLOCKS_PER_SEC;
        float min = quemin.front().first;
        while (!quemax.empty() && quemax.back().first <= k * data[i])
            quemax.pop_back();
        quemax.push_back(std::pair<float, int>(k * data[i], i));
        while (quemax.front().second <= i - window)
            quemax.pop_front();
        float max = quemax.front().first;
        adaptmoverage(data, b, i, pe, resolution);
        if (!flag) {
            if (i-pe > resolution/100 && k * data[i] < k * b[i] - th) {
                for (int j = i; j > pe; j--) {
                    if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * b[j] - stdev) {
                        Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
                        res.push_back(peak);
                        res.back().start = float(j) * interval / 1000;
                        res.back().s = j;
                        res.back().s0 = i;
                        res.back().baseline = b[i];
                        flag = true;
                        ps = i;
                        break;
                    }
                }
            }
                
        }
        else if (flag) {
            if (min> k * res.back().baseline - 2 * stdev && max - min < th) {

                for (int j = i; j > ps; j--) {
                    if (k * data[j] <= k * data[j - 1] && k * data[j] <= k * data[j + 1] && k * data[j] < k * res.back().baseline - th) {
                        res.back().end = float(j) * interval / 1000;
                        res.back().e = j;
                        std::vector<int> l = extreminval(data, ps, j, k);
                        if (l.size() == 1) {
                            res.back().currentpeak = data[l[0]];
                        }
                        else if (l.size() > 1) {
                            res.back().currentpeak = meancurrent(data, ps, j);
                        }
                        if (abs(res.back().currentpeak - res.back().baseline) < 3*stdev)
                            res.pop_back();
                        flag = false;
                        pe = i;
                        adaptmoverage(data, b, i, i, resolution);
                        break;
                    }
                }
            }
        }
    }

    if (flag)
        res.pop_back();
    b.clear();
    return res;
}

std::list<Peak> findPeak_median(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
    if (data.size() == 0)
        return std::list<Peak>();
    double interval = params["interval"];
    int resolution = int(params["resolution"]);
    int k = (params["direction"] >= 0) ? 1 : -1;
    int window = int(params["window"]);
    double thres = params["threshold"];

    int s = (sdouble * 1000 / interval >= 0) ? sdouble * 1000 / interval : 0;
    int e = (edouble * 1000 / interval > data.size()) ? data.size() : edouble * 1000 / interval;
    //stddev calculate
    float stdev = 0;
    calsd(data, s, e, stdev);
    float th = thres * stdev;

    std::list<Peak> res;
    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    std::deque<std::pair<float, int>> quemax;
   
    std::deque<int> medianwindow;
    double median = 0;
    float mean = 0;
    float meanold = 0;
    float d2 = 0;
    float d = 0;
    float z = 0;
    //float meanpre = 0;
    //float dpre = 0;

    
    //pre mean value
    int prelength = std::max(resolution, window);
    for (int i = s; i < s + prelength; i++) {
        if (medianwindow.size() < resolution) {
            median = (median * medianwindow.size() + data[i]) / (medianwindow.size() + 1);
            medianwindow.push_back(i);
        }
        else {
            median += (data[i] - data[i - resolution]) / resolution;
            medianwindow.pop_front();
            medianwindow.push_back(i);
        }
        if (i >= s + prelength - window) {
            while (!quemin.empty() && quemin.back().first >= k * data[i])
                quemin.pop_back();
            quemin.push_back(std::pair<float, int>(k * data[i], i));
            while (!quemax.empty() && quemax.back().first <= k * data[i])
                quemax.pop_back();
            quemax.push_back(std::pair<float, int>(k * data[i], i));
        }
    }
    //pre window min max mean sd build
    auto iter = data.begin() + s + prelength - window;
    double sum = std::accumulate(iter, iter+window, 0.0);
    double m = sum / window;
    double accum = 0.0;
    std::for_each(iter, iter+window, [&](const double d) {
        accum += d * d - m * m;
        });

    mean = float(m);
    d2 = accum;
    d = sqrt(d2 / window);

    int ps = s + prelength;
    int pe = s + prelength;


    for (int i = s + prelength; i < e; i++) {
        //cal moving mean for find start of peak
        if (!flag) {
            if (medianwindow.size() < resolution) {
                median = (medianwindow.size() * median + data[i]) / (medianwindow.size() + 1);
                medianwindow.push_back(i);
            }
            else {
                median += (data[i] - data[medianwindow.front()]) / resolution;
                medianwindow.pop_front();
                medianwindow.push_back(i);
            }        
        }
              

        //maintain min by dequene
        while (!quemin.empty() && quemin.back().first >= k * data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<float, int>(k * data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        //time1 += double(clock() - times)/ CLOCKS_PER_SEC;
        float min = quemin.front().first;
        while (!quemax.empty() && quemax.back().first <= k * data[i])
            quemax.pop_back();
        quemax.push_back(std::pair<float, int>(k * data[i], i));
        while (quemax.front().second <= i - window)
            quemax.pop_front();
        float max = quemax.front().first;
        
        //maintain sliding std and mean, mean, d, d2
        meanold = mean;
        mean += (data[i] - data[i - window]) / window;
        d2 += (data[i] - data[i - window]) * (data[i] + data[i - window] - mean - meanold);
        d = sqrt(d2 / window);
        //float z = 0;

        if (!flag) {
            if (i - pe > resolution / 100 && k * data[i] < k * median - th) {
                for (int j = i; j > pe && j==medianwindow.back(); j--) {
                    if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * median - stdev) {
                        Peak peak = { 0, 0, 0, 0, 0, 0, 0};
                        res.push_back(peak);
                        res.back().start = float(j) * interval / 1000;
                        res.back().s = j;
                        res.back().s0 = i;
                        res.back().baseline = median;
                        flag = true;
                        ps = i;
                        //meanpre = mean;
                        //dpre = d;
                        break;
                    }
                    median = (medianwindow.size() * median - data[j]) / (medianwindow.size() - 1);
                    medianwindow.pop_back();
                }
            }

        }
        else if (flag) {
            z = abs((res.back().baseline - mean) / (sqrt(d * d / window + stdev * stdev / window)));
            //k * mean > k * res.back().baseline - 0.5 * d && d < 1.2 * stdev && min > k * res.back().baseline - 3 * d && max > res.back().baseline + d
            if (z < 1.96 && min > k * res.back().baseline - 0.8 * th && max > res.back().baseline + stdev) {                
                for (int j = i; j >= ps; j--) {                   
                    if (k * data[j] <= k * data[j - 1] && k * data[j] <= k * data[j + 1] && k * data[j] < k * res.back().baseline - 0.8 * th) {
                        res.back().end = float(j) * interval / 1000;
                        res.back().e = j;
                        std::vector<int> l = extreminval(data, ps, j, k);
                        if (l.size() == 1) {
                            res.back().currentpeak = data[l[0]];
                        }
                        else if (l.size() > 1) {
                            res.back().currentpeak = meancurrent(data, ps, j);
                        }
                        if (abs(res.back().currentpeak - res.back().baseline) < 3 * stdev)
                            res.pop_back();
                        flag = false;
                        pe = i;
                        break;

                    }
                    if (j == ps) {
                        flag = false;
                        res.pop_back();
                        pe = i;
                    }
                }
            }
        }
    }

    if (flag)
        res.pop_back();
    
    return res;
}

std::list<Peak> findPeak(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
    if (data.size() == 0)
        return std::list<Peak>();

    int resolution = int(params["resolution"]);
    int autob = (params["auto"] > 0) ? 1 : 0;
    int order = int(params["order"]);
    double thres = params["threshold"];
    int window = int(params["window"]);
    double interval = params["interval"];
    int k = (params["direction"] >= 0) ? 1 : -1;
    int s = (sdouble * 1000 / interval >= 0) ? sdouble * 1000 / interval : 0;
    int e = (edouble * 1000 / interval > data.size()) ? data.size() : edouble * 1000 / interval;
    auto iter = data.begin() + s + 1000; 
    double sum = std::accumulate(iter, std::next(iter, 100000), 0.0);
    double m = sum / 100000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 100000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (100000 - 1));
    
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
        if (k*data[i] < k*b[i] - th && !flag) {
            for (int j = i; j >= 1; j--) {
                if (j == s) {
                    Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    res.back().s = j;
                    res.back().s0 = i;
                    flag = true;
                    ps = i;
                    break;
                }
                if (k*data[j] >= k*data[j - 1] && k*data[j] >= k*data[j + 1] && k*data[j] > k*b[j] - stdev) {
                    Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    res.back().s = j;
                    res.back().s0 = i;
                    flag = true;
                    ps = i;
                    break;
                }
            }
        }
        else if (flag && min > k*b[ps] - stdev) {
            for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
                if (k*data[j] <= k*data[j - 1] && k*data[j] <= k*data[j + 1] && k*data[j] < k*b[j] - 0.5 * th) {
                    res.back().end = float(j) * interval / 1000;
                    res.back().e = j;
                    if(res.size()==1)
                        res.back().baseline = calbaseline(data, res.back().s, s, s);
                    else
                        res.back().baseline = calbaseline(data, res.back().s, std::prev(res.end(), 2)->e, s);
                    std::vector<int> l = extreminval(data, ps, j, k);
                    if (l.size() == 1) {
                        res.back().currentpeak = data[l[0]];
                        if (abs(res.back().currentpeak - res.back().baseline) < 0.5 * th)
                            res.pop_back();
                        flag = false;
                    }
                    else if (l.size() > 1) {
                        res.back().currentpeak = meancurrent(data, l[0], l.back());
                        if (abs(res.back().currentpeak - res.back().baseline) < 0.5 * th)
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

std::list<Peak> findPeak_manual(std::vector<float>& data, std::unordered_map<std::string, double>& params, double startpoint, double endpoint, float bb, float thnoise) {
    if (data.size() == 0)
        return std::list<Peak>();
    double interval = params["interval"];
    int resolution = int(params["resolution"]);
    int k = (params["direction"] >= 0) ? 1 : -1;
    int window = int(params["window"]);
    double thres = params["threshold"];
    std::list<Peak> res;

    bool flag = false;
    std::deque<std::pair<float, int>> quemin;
    int ps = 0;
    int s = (startpoint * 1000 / interval >= 0) ? startpoint * 1000 / interval : 0;
    int e = (endpoint * 1000 / interval > data.size()) ? data.size() : endpoint * 1000 / interval;
    //stddev calculate
    auto iter = data.begin() + s;
    double sum = std::accumulate(iter, std::next(iter, 100000), 0.0);
    double m = sum / 100000;
    double accum = 0.0;
    std::for_each(iter, std::next(iter, 100000), [&](const double d) {
        accum += (d - m) * (d - m);
        });
    float stdev = sqrt(accum / (100000 - 1));
    double th = thres * stdev;

    //calculate baseline
    std::vector<double> b;
    for (int i = s; i < e; i++) {
        if (abs(data[i]-bb) > thnoise) 
            flag = true;
        else  
            flag = false;
      
        if (!flag) {
            if (i == s)
                b.push_back(bb);
            else if (i < s + resolution) {
                b.push_back((b.back() * (i - s) + data[i]) / (i - s + 1));
            }
            else
                b.push_back((b.back() * resolution + data[i]) / (resolution + 1));
        }   
        else {
            if (i == s)
                b.push_back(bb);
            else
                b.push_back(b.back());
        }
    }
    quemin.clear();
    flag = false;
    for (int i = s; i < e; i++) {
        //clock_t times = clock();
        while (!quemin.empty() && quemin.back().first >= k * data[i])
            quemin.pop_back();
        quemin.push_back(std::pair<float, int>(k * data[i], i));
        while (quemin.front().second <= i - window)
            quemin.pop_front();
        //time1 += double(clock() - times)/ CLOCKS_PER_SEC;
        float min = quemin.front().first;
        if (k * data[i] < k * b[i - s] - th && !flag) {
            for (int j = i; j >= s; j--) {
                if (j == s) {
                    Peak peak = { 0, 0, 0, 0, 0, 0, 0};
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    res.back().s = j;
                    res.back().s0 = i;
                    flag = true;
                    ps = i;
                    break;
                }
                if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * b[j - s] - stdev) {
                    Peak peak = { 0, 0, 0, 0, 0, 0, 0};
                    res.push_back(peak);
                    res.back().start = float(j) * interval / 1000;
                    res.back().s = j;
                    res.back().s0 = i;
                    flag = true;
                    ps = i;
                    break;
                }
            }
        }
        else if (flag && min > k * b[i - s] - stdev) {
            for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
                if (k * data[j] <= k * data[j - 1] && k * data[j] <= k * data[j + 1] && k * data[j] < k * b[j - s] - 0.5 * th) {
                    res.back().end = float(j) * interval / 1000;
                    res.back().e = j;
                    if (res.size() == 1)
                        res.back().baseline = calbaseline(data, res.back().s, s, s);
                    else
                        res.back().baseline = calbaseline(data, res.back().s, std::prev(res.end(), 2)->e, s);
                    std::vector<int> l = extreminval(data, ps, j, k);
                    if (l.size() == 1) {
                        res.back().currentpeak = data[l[0]];
                        if (abs(res.back().currentpeak - res.back().baseline) < 0.5 * th)
                            res.pop_back();
                        flag = false;
                    }
                    else if (l.size() > 1) {
                        res.back().currentpeak = meancurrent(data, l[0], l.back());
                        if (abs(res.back().currentpeak - res.back().baseline) < 0.5 * th)
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
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0;
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
    }
    
    while (std::getline(file, line)) {
        r = split(line, ",");
        if (!isNumber(r[i5]))
            continue;
        Peak vs = { 0, 0, 0, 0, 0, 0, 0};
        vs.start = std::stod(r[i0]);
        vs.end = std::stod(r[i1]);
        vs.baseline = std::stod(r[i2]);
        vs.currentpeak = std::stod(r[i3]);
        vs.s = std::stoi(r[i4]);
        vs.e = std::stoi(r[i5]);
        if (i6 != 0)
            vs.s0 = std::stoi(r[i6]);
        res.push_back(vs);
    }
    file.close();
    return res;
}

int argmin(double* x, int s, int e) {
    double minval = x[s];
    int k = s;
    for (int i = s + 1; i <= e; i++) {
        if (x[i] < minval) {
            minval = x[i];
            k = i;
        }
    }
    return k;
}

void cumSum(std::vector<float>& x, int s, int e, double stepsize, double h, double stdDev, std::vector<int>& v1, std::vector<double>& v2) {
    int size = e - s;
    double logp, logn = 0;
    double* cpos = new double[size];
    double* cneg = new double[size];
    double* gpos = new double[size];
    double* gneg = new double[size];
    for (int i = s; i < e; i++) {
        cpos[i - s] = 0;
        cneg[i - s] = 0;
        gpos[i - s] = 0;
        gneg[i - s] = 0;
    }
    double anchor = s;
    double mean = x[s];
    double variance = stdDev * stdDev;
    int nstates = 0;
    double varM = x[s];
    double varS = 0;
    int jump = s;
    v1.push_back(s);
    for (int i = s + 1; i < e; i++) {
        double varoldM = varM; //calculate move variance and mean.from mosaic. 
        varM = varM + (x[i] - varM) / (i - anchor + 1);
        varS = varS + (x[i] - varoldM) * (x[i] - varM);
        variance = varS / (i - anchor + 1);
        mean = ((i - anchor) * mean + x[i]) / (i - anchor + 1);
        variance = (variance == 0) ? stdDev * stdDev : variance;

        logp = stepsize * stdDev / variance * (x[i] - mean - stepsize * stdDev / 2);
        logn = -1 * stepsize * stdDev / variance * (x[i] - mean + stepsize * stdDev / 2);
        cpos[i - s] = cpos[i - s - 1] + logp;
        cneg[i - s] = cneg[i - s - 1] + logn;
        gpos[i - s] = std::max(gpos[i - s - 1] + logp, 0.);
        gneg[i - s] = std::max(gneg[i - s - 1] + logn, 0.);
        if (gpos[i - s] >= h) {
            jump = s + argmin(cpos, anchor - s, i - s);
            v2.push_back(meancurrent(x, v1.back(), jump));
            v1.push_back(jump);
            nstates++;
            anchor = i;
            cpos[i - s] = 0;
            cneg[i - s] = 0;
            gpos[i - s] = 0;
            gneg[i - s] = 0;
            mean = x[i];
            varM = x[i];
        }
        else if (gneg[i - s] >= h) {
            jump = s + argmin(cneg, anchor - s, i - s);
            v2.push_back(meancurrent(x, v1.back(), jump));
            v1.push_back(jump);
            nstates++;
            anchor = i;
            cpos[i - s] = 0;
            cneg[i - s] = 0;
            gpos[i - s] = 0;
            gneg[i - s] = 0;
            mean = x[i];
            varM = x[i];
        }
    }

    v2.push_back(meancurrent(x, v1.back(), e));
    v1.push_back(e);

    delete[] cpos;
    delete[] cneg;
    delete[] gpos;
    delete[] gneg;
    return;
}