#include <iostream>

int main() {
	int year;
	std::cin >> year;

	if (year % 4 != 0) {
		year += 4 - (year % 4);
	}

	if (year % 100 == 0 && year % 400 != 0) year += 4;

	std::cout << year << std::endl;
	return 0;
}
