
#include "days.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

int day2p1() {
	std::ifstream fin("input/day2.txt");
	std::string nextline;
	int nextVal;
	int maxVal;
	int minVal;
	int runningTotal = 0;

	while(std::getline(fin, nextline)) {
		std::istringstream input(nextline);

		input >> nextVal;
		maxVal = minVal = nextVal;

		while (input >> nextVal) {
			if (nextVal > maxVal) { maxVal = nextVal; }
			if (nextVal < minVal) { minVal = nextVal; }
		}

		runningTotal += (maxVal - minVal);
	}
	return runningTotal;
}

int day2p2() {
	std::ifstream fin("input/day2.txt");
	std::string nextline;
	int nextVal;
	int runningTotal = 0;

	while(std::getline(fin, nextline)) {
		std::istringstream input(nextline);
		std::vector<int> vec;

		while (input >> nextVal) {
			vec.push_back(nextVal);
		}

		std::sort(vec.begin(), vec.end(), [](const int &i1, const int&i2) { return i1 > i2; });
		for (auto i = vec.begin(); i != vec.end(); ++i) {
			for (auto j = i + 1; j != vec.end(); ++j) {
				if (*i % *j == 0) {
					runningTotal += (*i / *j);
					goto finish;
				}
			}
		}
		finish:;
	}
	return runningTotal;
}

