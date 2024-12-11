#include <climits>
#include <cstdlib>
#include <iostream>
#include "bench.hpp"

const int MAP_SIZE		   = 10;
int		  paths_found_slow = 0;
int		  paths_found_fast = 0;

void printMap(bool map[MAP_SIZE][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE + 2; i++) {
		for (int j = 0; j < MAP_SIZE + 2; j++) {
			if (i == 0 || i == MAP_SIZE + 1 || j == 0 || j == MAP_SIZE + 1) std::cout << "##";
			else if (map[i - 1][j - 1]) std::cout << "XX";
			else std::cout << "  ";
		}
		std::cout << std::endl;
	}
}

bool canMoveTo(unsigned int x, unsigned int y, bool map[MAP_SIZE][MAP_SIZE]) {
	if (x >= MAP_SIZE || y >= MAP_SIZE) return false;
	return map[y][x] == false;
}

int findPathLength_Slow(unsigned int x, unsigned int y, unsigned int destX, unsigned int destY,
						bool map[MAP_SIZE][MAP_SIZE], unsigned int length) {
	if (!canMoveTo(x, y, map)) return INT_MAX;
	if (x == destX && y == destY) {
		++paths_found_slow;
		return length;
	}

	map[y][x]	   = true;
	int pathLength = INT_MAX;
	pathLength	   = std::min(findPathLength_Slow(x + 1, y, destX, destY, map, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Slow(x - 1, y, destX, destY, map, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Slow(x, y + 1, destX, destY, map, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Slow(x, y - 1, destX, destY, map, length + 1), pathLength);
	map[y][x]	   = false;

	return pathLength;
}

int findPathLength_Slow(unsigned int x, unsigned int y, unsigned int destX, unsigned int destY, bool map[MAP_SIZE][MAP_SIZE]) {
	return findPathLength_Slow(x, y, destX, destY, map, 0);
}

int findPathLength_Fast(unsigned int x, unsigned int y, unsigned int destX, unsigned int destY,
						bool map[MAP_SIZE][MAP_SIZE], int distance[MAP_SIZE][MAP_SIZE], int length) {
	if (!canMoveTo(x, y, map)) return INT_MAX;
	if (distance[y][x] != 0 && distance[y][x] <= length) return INT_MAX;
	if (x == destX && y == destY) {
		++paths_found_fast;
		return length;
	}

	map[y][x]	   = true;
	distance[y][x] = length;
	int pathLength = INT_MAX;
	pathLength	   = std::min(findPathLength_Fast(x + 1, y, destX, destY, map, distance, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Fast(x - 1, y, destX, destY, map, distance, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Fast(x, y + 1, destX, destY, map, distance, length + 1), pathLength);
	pathLength	   = std::min(findPathLength_Fast(x, y - 1, destX, destY, map, distance, length + 1), pathLength);
	map[y][x]	   = false;

	return pathLength;
}

int findPathLength_Fast(unsigned int x, unsigned int y, unsigned int destX, unsigned int destY,
						bool map[MAP_SIZE][MAP_SIZE]) {
	int distance[MAP_SIZE][MAP_SIZE] = {0};
	return findPathLength_Fast(x, y, destX, destY, map, distance, 0);
}

int main() {
	using namespace std::chrono;

	// clang-format off
	bool map[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	// clang-format on

	printMap(map);
	std::cout << "Distance slow: " << findPathLength_Slow(0, 0, 9, 9, map) << std::endl;
	std::cout << "Distance fast: " << findPathLength_Fast(0, 0, 9, 9, map) << std::endl;

	std::cout << "Paths found slow: " << paths_found_slow << std::endl;
	std::cout << "Time slow: ";
	BENCH(findPathLength_Slow(0, 0, 9, 9, map), 100, microseconds);
	std::cout << std::endl;

	std::cout << "Paths found fast: " << paths_found_fast << std::endl;
	std::cout << "Time fast: ";
	BENCH(findPathLength_Fast(0, 0, 9, 9, map), 100, microseconds);
	std::cout << std::endl;

	return 0;
}
