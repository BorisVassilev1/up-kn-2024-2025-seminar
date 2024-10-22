#include <iostream>
#include <ostream>

int max(int a, int b) { return a > b ? a : b; }

int myabs(int a) { return a >= 0 ? a : -a; }

int main() {
	std::cout << myabs(-10) << " " << myabs(10) << std::endl;
	int maxDiff = 0;
	int prev;
	int curr;

	std::cin >> prev;
	do {
		std::cin >> curr;
		maxDiff = max(maxDiff, myabs(curr - prev));
		prev	= curr;
	} while (curr != 0);

	std::cout << maxDiff << std::endl;
	return 0;
}
