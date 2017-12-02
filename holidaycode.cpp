
#include <iostream>
#include <string>
#include <fstream>

int day1p1();
int day1p2();

int main(int argc, char ** argv) {

	std::cout << "Day 1 Part 1: " << day1p1() << std::endl;
	std::cout << "Day 1 Part 2: " << day1p2() << std::endl;
	return 0;

}

int day1p1() {
	std::ifstream fin("day1input.txt");
	std::string input;
	int sum = 0;

	fin >> input;
	const char * s = input.c_str();
	while (*(s + 1)) {
		if (*s == *(s + 1)) {
			sum += (*s - '0');
		}
		++s;
	}
	if (*s == *input.begin()) {
		sum += (*s - '0');
	}
	return sum;
}

int day1p2() {
	std::ifstream fin("day1input.txt");
	std::string input;
	int sum = 0;

	fin >> input;
	int jump = input.length() / 2;

	for (int i = 0; i < input.length() / 2; ++i) {
		if (input[i] == input[i + jump]) {
			sum += (input[i] - '0');
		}
	}
	for (int i = input.length() / 2; i < input.length(); ++i) {
		if (input[i] == input[i - jump]) {
			sum += (input[i] - '0');
		}
	}

	return sum;
}


