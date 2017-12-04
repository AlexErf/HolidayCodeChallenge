
#include "days.h"

#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <map>


int day4p1() {

	int total = 0;
	std::ifstream fin("input/day4.txt");
	std::string nextline;

	while(std::getline(fin, nextline)) {
		std::istringstream stream(nextline);
		std::set<std::string> words;
		std::string next_word;

		while(stream >> next_word) {
			if (!words.insert(next_word).second) {
				total--;
				break;
			}
		}
		total++;
	}

	return total;

}


int day4p2() {

	int total = 0;
	std::ifstream fin("input/day4.txt");
	std::string nextline;

	while(std::getline(fin, nextline)) {
		std::istringstream stream(nextline);
		std::set<std::map<char, int>> words;
		std::string next_word;

		while(stream >> next_word) {
			std::map<char, int> this_bag;
			for (int i = 0; i < next_word.length(); ++i) {
				this_bag[next_word[i]] += 1;
			}

			if (!words.insert(this_bag).second) {
				total--;
				break;
			}
		}
		total++;
	}

	return total;

}


