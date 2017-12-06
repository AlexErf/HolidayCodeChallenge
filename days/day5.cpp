
#include "days.h"

#include <fstream>

int day5p1() {
	std::ifstream fin("input/day5.txt");
	int int_list[1500];
	int next;
	int loc = 0;
	int steps = 0;
	int total_elems = 0;

	while (fin >> next) {
		int_list[total_elems++] = next;
	}

	while (loc >= 0 && loc < total_elems) {
		int_list[loc] += 1;
		loc += (int_list[loc] - 1);
		++steps;
	}

	return steps;
}


int day5p2() {
	std::ifstream fin("input/day5.txt");
	int int_list[1500];
	int next;
	int loc = 0;
	int steps = 0;
	int total_elems = 0;

	while (fin >> next) {
		int_list[total_elems++] = next;
	}

	while (loc >= 0 && loc < total_elems) {
		int old_loc = loc;
		loc += int_list[loc];
		if (int_list[old_loc] >= 3) {
			int_list[old_loc]--;
		}
		else {
			int_list[old_loc]++;
		}
		++steps;
	}

	return steps;
}

