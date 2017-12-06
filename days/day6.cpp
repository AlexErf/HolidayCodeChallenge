
#include "days.h"

#include <fstream>
#include <array>
#include <set>
#include <iostream>

int max(std::array<int, 16>);
bool arr_equal(std::array<int, 16>, std::array<int, 16>);

int day6p1() {
	std::array<int, 16> list;
	std::set<std::array<int, 16>> set_lists;
	std::ifstream fin("input/day6.txt");

	int runs = 0;

	for (int i = 0; fin >> list[i]; ++i) {}

	while (set_lists.insert(list).second) {
		int max_loc = max(list);
		int to_distribute = list[max_loc];
		list[max_loc] = 0;
		while (to_distribute > 0) {
			for (int i = max_loc + 1; i < 16 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
			for (int i = 0; i < max_loc + 1 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
		}
		++runs;
	}
	return runs;
}

int day6p2() {
	std::array<int, 16> list;
	std::set<std::array<int, 16>> set_lists;
	std::ifstream fin("input/day6.txt");

	int runs = 0;

	for (int i = 0; fin >> list[i]; ++i) {}

	while (set_lists.insert(list).second) {
		int max_loc = max(list);
		int to_distribute = list[max_loc];
		list[max_loc] = 0;
		while (to_distribute > 0) {
			for (int i = max_loc + 1; i < 16 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
			for (int i = 0; i < max_loc + 1 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
		}
	}
	set_lists.clear();
	while (set_lists.insert(list).second) {
		int max_loc = max(list);
		int to_distribute = list[max_loc];
		list[max_loc] = 0;
		while (to_distribute > 0) {
			for (int i = max_loc + 1; i < 16 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
			for (int i = 0; i < max_loc + 1 && to_distribute > 0; ++i) {
				list[i]++;
				to_distribute--;
			}
		}
		++runs;
	}
	return runs;
}

int max(std::array<int, 16> list) {
	int loc = 0;

	for (int i = 1; i < 16; ++i) {
		if (list[i] > list[loc]) {
			loc = i;
		}
	}
	return loc;
}

bool arr_equal(std::array<int, 16> list1, std::array<int, 16> list2) {
	for (int i = 0; i < 16; ++i) {
		if (list1[i] != list2[i]) {
			return false;
		}
	}
	return true;
}

