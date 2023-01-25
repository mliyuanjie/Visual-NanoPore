#include <iostream>
#include "tools2.h" 


double meancurrent(std::vector<double>& data) {
	double mean = 0;
	if (data.size() == 0)
		return 0;
	for (size_t i = 0; i < data.size(); i++) {
		mean += (data[i] - mean) / (i + 1);
	}
	return mean;
}

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
				result.back().currentpeak = meancurrent(peakcurrent);
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
				result.back().currentpeak = meancurrent(peakcurrent);
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