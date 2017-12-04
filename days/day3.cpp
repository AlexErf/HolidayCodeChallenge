
#include "days.h"

#include <cmath>
#include <fstream>
#include <cassert>

int day3p1() {

	std::ifstream fin("input/day3.txt");
	int number;

	fin >> number;

	int largest_square_below = (int)sqrt(number);
	int distanceToTravel = number - largest_square_below * largest_square_below;

	int n_square = largest_square_below + 1;

	while (distanceToTravel >= n_square) {
		distanceToTravel -= n_square;
	}

	int distFromMiddle = abs(n_square / 2 - distanceToTravel);
	int distFromCenter = n_square / 2;

	return distFromMiddle + distFromCenter;
}


int sum_surroundings(int arr[][50], int x, int y);

int day3p2() {

	std::ifstream fin("input/day3.txt");
	int number;

	fin >> number;

	int arr[50][50];

	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			arr[i][j] = 0;
		}
	}

	arr[25][25] = 1;
	int x = 25;
	int y = 25;

	for (int ring = 3; true; ring += 2) {
		x++;
		arr[x][y] = sum_surroundings(arr, x, y);
		if (arr[x][y] > number) { return arr[x][y]; }
		for (int i = 0; i < ring - 2; ++i) {
			y++;
			arr[x][y] = sum_surroundings(arr, x, y);
			if (arr[x][y] > number) { return arr[x][y]; }
		}
		for (int i = 0; i < ring - 1; ++i) {
			x--;
			arr[x][y] = sum_surroundings(arr, x, y);
			if (arr[x][y] > number) { return arr[x][y]; }
		}
		for (int i = 0; i < ring - 1; ++i) {
			y--;
			arr[x][y] = sum_surroundings(arr, x, y);
			if (arr[x][y] > number) { return arr[x][y]; }
		}
		for (int i = 0; i < ring - 1; ++i) {
			x++;
			arr[x][y] = sum_surroundings(arr, x, y);
			if (arr[x][y] > number) { return arr[x][y]; }
		}
	}

	assert(false);

}

int sum_surroundings(int arr[][50], int x, int y) {
	return arr[x + 1][y] + arr[x + 1][y + 1] + arr[x][y + 1] +
			arr[x - 1][y + 1] + arr[x - 1][y] + arr[x - 1][y - 1] +
			arr[x][y - 1] + arr[x + 1][y - 1];
}

