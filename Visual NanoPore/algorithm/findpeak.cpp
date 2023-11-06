#include <iostream>
#include <omp.h>
#include <random>
#include "findpeak.h" 



FindPeakRealTime::FindPeakRealTime(double samplerate, double sigmas, int resolutions, int windows, int ks, int offsets, bool ismedian) {
	fs = samplerate;
	sigma = sigmas;
	windowsizestart = resolutions;
	windowsizeend = windows;
	k = ks;
	interval = 1 / samplerate;
	offset = offsets;
	if (ismedian)
		_append = &FindPeakRealTime::append_median;
	else 
		_append = &FindPeakRealTime::append_average;
}

void FindPeakRealTime::append_average(std::vector<float>& x) {
	if (i == 0) {
		data = x[0];
		datasuf = x[1];
		i = 2;
	}

	while (i < x.size() + s) {
		datapre = data;
		data = datasuf;
		datasuf = x[i - s];

		//cal culate min max
		while (!quemin.empty() && quemin.back().first >= k * data)
			quemin.pop_back();
		quemin.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemin.front().second + windowsizeend + 1 <= i)
			quemin.pop_front();
		min = quemin.front().first;
		while (!quemax.empty() && quemax.back().first <= k * data)
			quemax.pop_back();
		quemax.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemax.front().second + windowsizeend + 1 <= i)
			quemax.pop_front();
		max = quemax.front().first;

		//calculate mean and std for checking the end of event
		if ((int)windowend.size() < windowsizeend) {
			windowend.push_back(data);
			meanold = mean;
			mean += (data - mean) / windowend.size();
			d2 += (data - meanold) * (data - mean);
		}
		else {
			meanold = mean;
			mean += (data - windowend.front()) / windowsizeend;
			d2 += (data - windowend.front()) * (data + windowend.front() - mean - meanold);
			d = sqrt(d2 / windowsizeend);
			windowend.pop_front();
			windowend.push_back(data);
		}

		//calculate mean and std for checking the start of event
		if (!flag) {
			if ((int)windowstart.size() < windowsizestart) {
				medianold = median;
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				median += (data - median) / windowstart.size();
				sd += (data - medianold) * (data - median);
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
			}
			else {
				medianold = median;
				median += (data - windowstart.front().first) / windowsizestart;
				sd += (data - windowstart.front().first) * (data + windowstart.front().first - median - medianold);
				windowstart.pop_front();
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
			}
			if ((int)windowstart.size() < windowsizestart / 2) {
				i += 1;
				continue;
			}
		}

		// find peak part
		if (!flag) {
			if (k * data < k * median - th) {
				if (localmaxindex < windowstart.front().second || windowstart.size() == 0) {
					windowstart.clear();
					median = 0;
					sd = 0;
					localmaxindex = 0;
					i += 1;
					continue;
				}

				while (windowstart.size() > 0 && windowstart.back().second != localmaxindex) {
					medianold = median;
					median += (median - windowstart.back().first) / ((int)windowstart.size() - 1);
					sd += (median - windowstart.back().first) * (windowstart.back().first - medianold);
					windowstart.pop_back();
					stddev = sqrt(sd / (int)windowstart.size());
					th = stddev * sigma;
				}
				
				Peak peak = { 0,0,0,0,0 };
				result.push_back(peak);
				result.back().s = localmaxindex + offset;
				result.back().baseline = median;
				result.back().start = (localmaxindex + offset) * interval;
				flag = true;
				s0flag = true;
				localmaxindex = 0;
			}
			else if (k * data >= k * datapre && k * data >= k * datasuf ) {
				localmaxindex = i - 1;
			}
		}
		else {
			z = abs((result.back().baseline - mean) / (sqrt(d * d / windowsizeend + stddev * stddev / windowsizeend)));
			peakcurrent.push_back(data);
			if (z < 1.96 && min > k * result.back().baseline - 0.8 * th && max > k * result.back().baseline + stddev) {
				if (localminindex == 0 || s0flag) {
					flag = false;
					s0flag = false;
					result.pop_back();
					peakcurrent.clear();
					localminindex = 0;
					i += 1;
					continue;
				}
				for (size_t j = i - 1; j > localminindex; j--)
					peakcurrent.pop_back();
				result.back().e = localminindex + offset;
				result.back().end = (localminindex + offset) * interval;
				result.back().currentpeak = meancurrent(peakcurrent, 0, peakcurrent.size());
				localminindex = 0;
				flag = false;
				peakcurrent.clear();
				if (k * result.back().baseline - k * result.back().currentpeak < th) {
					result.pop_back();
				}
			}
			else if (k * data <= k * datapre && k * data <= k * datasuf && k * data < k * result.back().baseline - th) {
				localminindex = i - 1;
				if (s0flag) {
					result.back().s0 = localminindex + offset;
					s0flag = false;
				}
			}
			else if (k * mean > k * result.back().baseline + 3 * stddev) {
				flag = false;
				s0flag = false;
				result.pop_back();
				windowstart.clear();
				median = 0;
				sd = 0;
				peakcurrent.clear();
				localminindex = 0;
				i += 1;
				continue;
			}
		}
		i += 1;
	}
	s += x.size();
	return ;
}

void FindPeakRealTime::append_median(std::vector<float>& x) {
	if (i == 0) {
		data = x[0];
		datasuf = x[1];
		i = 2;
	}
	while (i < x.size() + s) {
		datapre = data;
		data = datasuf;
		datasuf = x[i - s];

		//cal culate min max
		while (!quemin.empty() && quemin.back().first >= k * data)
			quemin.pop_back();
		quemin.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemin.front().second + windowsizeend + 1 <= i)
			quemin.pop_front();
		min = quemin.front().first;
		while (!quemax.empty() && quemax.back().first <= k * data)
			quemax.pop_back();
		quemax.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemax.front().second + windowsizeend + 1 <= i)
			quemax.pop_front();
		max = quemax.front().first;

		//calculate mean and std for checking the end of event
		if ((int)windowend.size() < windowsizeend) {
			windowend.push_back(data);
			meanold = mean;
			mean += (data - mean) / windowend.size();
			d2 += (data - meanold) * (data - mean);
		}
		else {
			meanold = mean;
			mean += (data - windowend.front()) / windowsizeend;
			d2 += (data - windowend.front()) * (data + windowend.front() - mean - meanold);
			d = sqrt(d2 / windowsizeend);
			windowend.pop_front();
			windowend.push_back(data);
		}

		//calculate mean and std for checking the start of event
		if (!flag) {
			if ((int)windowstart.size() < windowsizestart) {
				medianold = median;
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				median += (data - median) / windowstart.size();
				sd += (data - medianold) * (data - median);
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
				medianset.insert(data);
				median_value = *next(medianset.begin(), medianset.size() / 2);
			}
			else {
				medianset.insert(data);
				medianset.erase(medianset.find(windowstart.front().first));
				median_value = *next(medianset.begin(), medianset.size() / 2);
				medianold = median;
				median += (data - windowstart.front().first) / windowsizestart;
				sd += (data - windowstart.front().first) * (data + windowstart.front().first - median - medianold);
				windowstart.pop_front();
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
			}
			if ((int)windowstart.size() < windowsizestart / 2) {
				i += 1;
				continue;
			}
		}

		// find peak part
		if (!flag) {
			if (k * data < k * median_value - th) {
				if (localmaxindex < windowstart.front().second || windowstart.size() == 0) {
					windowstart.clear();
					medianset.clear();
					median_value = 0;
					median = 0;
					sd = 0;
					localmaxindex = 0;
					i += 1;
					continue;
				}

				while (windowstart.size() > 0 && windowstart.back().second != localmaxindex) {
					medianset.erase(medianset.find(windowstart.back().first));
					median_value = *next(medianset.begin(), medianset.size() / 2);
					medianold = median;
					median += (median - windowstart.back().first) / ((int)windowstart.size() - 1);
					sd += (median - windowstart.back().first) * (windowstart.back().first - medianold);
					windowstart.pop_back();
					stddev = sqrt(sd / (int)windowstart.size());
					th = stddev * sigma;
				}

				Peak peak = { 0,0,0,0,0 };
				result.push_back(peak);
				result.back().s = localmaxindex + offset;
				result.back().baseline = median_value;
				result.back().start = (localmaxindex + offset) * interval;
				flag = true;
				s0flag = true;
				localmaxindex = 0;
			}
			else if (k * data >= k * datapre && k * data >= k * datasuf) {
				localmaxindex = i - 1;
			}
		}
		else {
			z = abs((result.back().baseline - mean) / (sqrt(d * d / windowsizeend + stddev * stddev / windowsizeend)));
			peakcurrent.push_back(data);
			if (z < 1.96 && min > k * result.back().baseline - 0.8 * th && max > k * result.back().baseline + stddev) {
				if (localminindex == 0 || s0flag) {
					flag = false;
					s0flag = false;
					result.pop_back();
					peakcurrent.clear();
					localminindex = 0;
					i += 1;
					continue;
				}
				for (size_t j = i - 1; j > localminindex; j--)
					peakcurrent.pop_back();
				result.back().e = localminindex + offset;
				result.back().end = (localminindex + offset) * interval;
				result.back().currentpeak = meancurrent(peakcurrent, 0, peakcurrent.size());
				localminindex = 0;
				flag = false;
				peakcurrent.clear();
				if (k * result.back().baseline - k * result.back().currentpeak < th) {
					result.pop_back();
				}
			}
			else if (k * data <= k * datapre && k * data <= k * datasuf && k * data < k * result.back().baseline - th) {
				localminindex = i - 1;
				if (s0flag) {
					result.back().s0 = localminindex + offset;
					s0flag = false;
				}
			}
			else if (k * mean > k * result.back().baseline + 3 * stddev) {
				flag = false;
				s0flag = false;
				result.pop_back();
				windowstart.clear();
				medianset.clear();
				median_value = 0;
				median = 0;
				sd = 0;
				peakcurrent.clear();
				localminindex = 0;
				i += 1;
				continue;
			}
		}
		i += 1;
	}
	s += x.size();
	return;
}

FindPeakRealTimeShort::FindPeakRealTimeShort(double samplerate, double sigmas, int resolutions, int windows, int ks, int offsets, int ismedian) {
	fs = samplerate;
	sigma = sigmas;
	windowsizestart = resolutions;
	windowsizeend = windows;
	k = ks;
	interval = 1 / samplerate;
	offset = offsets;
	_append = &FindPeakRealTimeShort::append_average;
	maxtimestep = ismedian;
}

void FindPeakRealTimeShort::append_average(std::vector<float>& x) {
	if (i == 0) {
		data = x[0];
		datasuf = x[1];
		i = 2;
	}

	while (i < x.size() + s) {
		datapre = data;
		data = datasuf;
		datasuf = x[i - s];

		//cal culate min max
		while (!quemin.empty() && quemin.back().first >= k * data)
			quemin.pop_back();
		quemin.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemin.front().second + windowsizeend + 1 <= i)
			quemin.pop_front();
		min = quemin.front().first;
		while (!quemax.empty() && quemax.back().first <= k * data)
			quemax.pop_back();
		quemax.push_back(std::pair<double, size_t>(k * data, i - 1));
		while (quemax.front().second + windowsizeend + 1 <= i)
			quemax.pop_front();
		max = quemax.front().first;

		//calculate mean and std for checking the end of event
		if ((int)windowend.size() < windowsizeend) {
			windowend.push_back(data);
			meanold = mean;
			mean += (data - mean) / windowend.size();
			d2 += (data - meanold) * (data - mean);
		}
		else {
			meanold = mean;
			mean += (data - windowend.front()) / windowsizeend;
			d2 += (data - windowend.front()) * (data + windowend.front() - mean - meanold);
			d = sqrt(d2 / windowsizeend);
			windowend.pop_front();
			windowend.push_back(data);
		}

		//calculate mean and std for checking the start of event
		if (!flag) {
			if ((int)windowstart.size() < windowsizestart) {
				medianold = median;
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				median += (data - median) / windowstart.size();
				sd += (data - medianold) * (data - median);
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
			}
			else {
				medianold = median;
				median += (data - windowstart.front().first) / windowsizestart;
				sd += (data - windowstart.front().first) * (data + windowstart.front().first - median - medianold);
				windowstart.pop_front();
				windowstart.push_back(std::pair<double, size_t>(data, i - 1));
				stddev = sqrt(sd / windowstart.size());
				th = stddev * sigma;
			}
			if ((int)windowstart.size() < windowsizestart / 2) {
				i += 1;
				continue;
			}
		}

		// find peak part
		if (!flag) {
			if (k * data < k * median - th) {
				if (localmaxindex < windowstart.front().second || windowstart.size() == 0) {
					windowstart.clear();
					median = 0;
					sd = 0;
					localmaxindex = 0;
					i += 1;
					continue;
				}

				while (windowstart.size() > 0 && windowstart.back().second != localmaxindex) {
					medianold = median;
					median += (median - windowstart.back().first) / ((int)windowstart.size() - 1);
					sd += (median - windowstart.back().first) * (windowstart.back().first - medianold);
					windowstart.pop_back();
					stddev = sqrt(sd / (int)windowstart.size());
					th = stddev * sigma;
				}

				Peak peak = { 0,0,0,0,0 };
				result.push_back(peak);
				result.back().s = localmaxindex + offset;
				result.back().baseline = median;
				result.back().start = (localmaxindex + offset) * interval;
				flag = true;
				s0flag = true;
				localmaxindex = 0;
			}
			else if (k * data >= k * datapre && k * data >= k * datasuf) {
				localmaxindex = i - 1;
			}
		}
		else {
			maxtime += 1;
			z = abs((result.back().baseline - mean) / (sqrt(d * d / windowsizeend + stddev * stddev / windowsizeend)));
			peakcurrent.push_back(data);
			if (z < 1.96 && min > k * result.back().baseline - 0.8 * th && max > k * result.back().baseline + stddev) {
				if (localminindex == 0 || s0flag) {
					flag = false;
					s0flag = false;
					result.pop_back();
					peakcurrent.clear();
					localminindex = 0;
					i += 1;
					continue;
				}
				for (size_t j = i - 1; j > localminindex; j--)
					peakcurrent.pop_back();
				result.back().e = localminindex + offset;
				result.back().end = (localminindex + offset) * interval;
				result.back().currentpeak = meancurrent(peakcurrent, 0, peakcurrent.size());
				localminindex = 0;
				flag = false;
				peakcurrent.clear();
				maxtime = 0;
				if (k * result.back().baseline - k * result.back().currentpeak < th) {
					result.pop_back();
				}
			}
			else if (k * data <= k * datapre && k * data <= k * datasuf && k * data < k * result.back().baseline - th) {
				localminindex = i - 1;
				if (s0flag) {
					result.back().s0 = localminindex + offset;
					s0flag = false;
				}
			}
			else if (k * mean > k * result.back().baseline + 3 * stddev || maxtime> windowsizestart) {
				flag = false;
				s0flag = false;
				result.pop_back();
				windowstart.clear();
				median = 0;
				sd = 0;
				peakcurrent.clear();
				localminindex = 0;
				i += 1;
				maxtime = 0;
				continue;
			}
		}
		i += 1;
	}
	s += x.size();
	return;
}



std::list<Peak> findPeak(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
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
	float stdev = calsd(data, s, e);
	float th = thres * stdev;

	std::list<Peak> res;
	int localmin = 0;
	bool flag = false;
	std::deque<std::pair<float, int>> quemin;
	std::deque<std::pair<float, int>> quemax;
	std::deque<int> medianwindow;
	float median = 0;
	float mean = 0;
	float meanold = 0;
	float d2 = 0;
	float d = 0;
	float z = 0;
	int ps = s;
	int pe = s;
	float min = 0;
	float max = 0;


	for (int i = s; i < e; i++) {
		//cal moving mean for find start of peak
		if (!flag) {
			if (medianwindow.size() < resolution) {
				medianwindow.push_back(i);
				median += (data[i] - median) / medianwindow.size();

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
		min = quemin.front().first;
		while (!quemax.empty() && quemax.back().first <= k * data[i])
			quemax.pop_back();
		quemax.push_back(std::pair<float, int>(k * data[i], i));
		while (quemax.front().second <= i - window)
			quemax.pop_front();
		max = quemax.front().first;

		//maintain sliding std and mean, mean, d, d2
		if (i - s <= window - 1) {
			meanold = mean;
			mean += (data[i] - mean) / (i - s + 1);
			d2 += (data[i] - meanold) * (data[i] - mean);
			continue;
		}
		else {
			meanold = mean;
			mean += (data[i] - data[i - window]) / window;
			d2 += (data[i] - data[i - window]) * (data[i] + data[i - window] - mean - meanold);
			d = sqrt(d2 / window);
		}

		//float z = 0;

		if (!flag) {
			if (i - pe > resolution / 100 && k * data[i] < k * median - th) {
				for (int j = i; j > pe && j == medianwindow.back(); j--) {
					if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * median - stdev) {
						Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
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
					medianwindow.pop_back();
					median += (median - data[j]) / medianwindow.size();
				}
			}
		}
		else {
			z = abs((res.back().baseline - mean) / (sqrt(d * d / window + stdev * stdev / window)));
			//k * mean > k * res.back().baseline - 0.5 * d && d < 1.2 * stdev && min > k * res.back().baseline - 3 * d && max > res.back().baseline + d
			if (z < 1.96 && min > k * res.back().baseline - 0.8 * th && max > k * res.back().baseline + stdev) {
				if (localmin == 0) {
					flag = false;
					res.pop_back();
					pe = i;
					continue;
				}
				res.back().end = float(localmin) * interval / 1000;
				res.back().e = localmin;
				std::vector<int> l = extreminval(data, ps, localmin, k);
				if (l.size() == 1)
					res.back().currentpeak = data[l[0]];
				else if (l.size() > 1)
					res.back().currentpeak = meancurrent(data, ps, localmin);
				if (abs(res.back().currentpeak - res.back().baseline) < th)
					res.pop_back();
				flag = false;
				pe = i;
				localmin = 0;
			}
			else if (k * data[i] <= k * data[i - 1] && k * data[i] <= k * data[i + 1] && k * data[i] < k * res.back().baseline - th) {
				localmin = i;
			}
		}
	}
	if (flag)
		res.pop_back();

	return res;
}

std::list<Peak> findPeak_parallel(std::vector<float>& data, std::unordered_map<std::string, double>& params, double sdouble, double edouble) {
	int parallel = params["parallel"];
	if (parallel == 1) {
		return findPeak(data, params, sdouble, edouble);
	}
	double intervaltotal = params["interval"];
	int resolutiontotal = int(params["resolution"]);
	int ktotal = (params["direction"] >= 0) ? 1 : -1;
	int windowtotal = int(params["window"]);
	double thres = params["threshold"];

	int stotal = (sdouble * 1000 / intervaltotal >= 0) ? sdouble * 1000 / intervaltotal : 0;
	int etotal = (edouble * 1000 / intervaltotal > data.size()) ? data.size() : edouble * 1000 / intervaltotal;
	//stddev calculate
	float stdevtotal = calsd(data, stotal, etotal);
	float thtotal = thres * stdevtotal;

	std::list<Peak> restotal;

#pragma omp parallel for 
	for (int iparallel = 0; iparallel < parallel; iparallel++) {
		int resolution = resolutiontotal;
		int k = ktotal;
		int window = windowtotal;
		float stdev = stdevtotal;
		float th = thtotal;
		double interval = intervaltotal;

		std::list<Peak> res;
		int s = stotal + (etotal - stotal) * double(iparallel) / double(parallel);
		int e = stotal + (etotal - stotal) * double(iparallel + 1) / double(parallel);

		bool flag = false;
		std::deque<std::pair<float, int>> quemin;
		std::deque<std::pair<float, int>> quemax;
		int localmin = 0;
		std::deque<int> medianwindow;
		float median = 0;
		float mean = 0;
		float meanold = 0;
		float d2 = 0;
		float d = 0;
		float z = 0;
		float min = 0;
		float max = 0;
		int ps = 0;
		int pe = 0;
		//float meanpre = 0;
		//float dpre = 0;


		//pre mean value
		//std::vector<float> data = { dat+ s, dat + e };

		for (int i = s; i < e; i++) {
			//cal moving mean for find start of peak
			if (!flag) {
				if (medianwindow.size() < resolution) {
					medianwindow.push_back(i);
					median += (data[i] - median) / medianwindow.size();

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
			min = quemin.front().first;
			while (!quemax.empty() && quemax.back().first <= k * data[i])
				quemax.pop_back();
			quemax.push_back(std::pair<float, int>(k * data[i], i));
			while (quemax.front().second <= i - window)
				quemax.pop_front();
			max = quemax.front().first;

			//maintain sliding std and mean, mean, d, d2
			if (i - s <= window - 1) {
				meanold = mean;
				mean += (data[i] - mean) / (i - s + 1);
				d2 += (data[i] - meanold) * (data[i] - mean);
				continue;
			}
			else {
				meanold = mean;
				mean += (data[i] - data[i - window]) / window;
				d2 += (data[i] - data[i - window]) * (data[i] + data[i - window] - mean - meanold);
				d = sqrt(d2 / window);
			}

			//float z = 0;

			if (!flag) {
				if (i - pe > resolution / 100 && k * data[i] < k * median - th) {
					for (int j = i; j > pe && j == medianwindow.back(); j--) {
						if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * median - stdev) {
							Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
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
						medianwindow.pop_back();
						median += (median - data[j]) / medianwindow.size();
					}
				}
			}
			else {
				z = abs((res.back().baseline - mean) / (sqrt(d * d / window + stdev * stdev / window)));
				//k * mean > k * res.back().baseline - 0.5 * d && d < 1.2 * stdev && min > k * res.back().baseline - 3 * d && max > res.back().baseline + d
				if (z < 1.96 && min > k * res.back().baseline - 0.8 * th && max > k * res.back().baseline + stdev) {
					if (localmin == 0) {
						flag = false;
						res.pop_back();
						pe = i;
						continue;
					}
					res.back().end = float(localmin) * interval / 1000;
					res.back().e = localmin;
					std::vector<int> l = extreminval(data, ps, localmin, k);
					if (l.size() == 1)
						res.back().currentpeak = data[l[0]];
					else if (l.size() > 1)
						res.back().currentpeak = meancurrent(data, ps, localmin);
					if (abs(res.back().currentpeak - res.back().baseline) < th)
						res.pop_back();
					flag = false;
					pe = i;
					localmin = 0;;
				}
				else if (k * data[i] <= k * data[i - 1] && k * data[i] <= k * data[i + 1] && k * data[i] < k * res.back().baseline - th) {
					localmin = i;
				}
			}
		}

		if (flag)
			res.pop_back();
#pragma omp critical
		restotal.insert(restotal.end(), res.begin(), res.end());
	}


	restotal.sort();


	return restotal;
}

std::list<Peak> findPeak_manual(std::vector<float>& data, std::unordered_map<std::string, double>& params, double startpoint, double endpoint, double bb, double thnoise) {
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
	float stdev = calsd(data, s, e);
	double th = thres * stdev;

	//calculate baseline
	std::vector<double> b;
	for (int i = s; i < e; i++) {
		if (abs(data[i] - bb) > thnoise)
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
					Peak peak = { 0, 0, 0, 0, 0, 0, 0 };
					res.push_back(peak);
					res.back().start = float(j) * interval / 1000;
					res.back().s = j;
					res.back().s0 = i;
					flag = true;
					ps = i;
					break;
				}
				if (k * data[j] >= k * data[j - 1] && k * data[j] >= k * data[j + 1] && k * data[j] > k * b[j - s] - stdev) {
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
		else if (flag && min > k * b[i - s] - stdev) {
			for (int j = i; j > int(res.back().start * 1000 / interval); j--) {
				if (k * data[j] <= k * data[j - 1] && k * data[j] <= k * data[j + 1] && k * data[j] < k * b[j - s] - th) {
					res.back().end = float(j) * interval / 1000;
					res.back().e = j;
					if (res.size() == 1)
						res.back().baseline = meancurrent(data, s, res.back().s);
					else
						res.back().baseline = meancurrent(data, std::prev(res.end(), 2)->e, res.back().s);
					std::vector<int> l = extreminval(data, ps, j, k);
					if (l.size() == 1) {
						res.back().currentpeak = data[l[0]];
						if (abs(res.back().currentpeak - res.back().baseline) < th)
							res.pop_back();
						flag = false;
					}
					else if (l.size() > 1) {
						res.back().currentpeak = meancurrent(data, l[0], l.back());
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