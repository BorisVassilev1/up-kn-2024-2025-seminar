#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if (a != b && b != c && a != c) {
	} else {
		std::cout << "error: The numbers are not different!!!" << std::endl;
		return 1;
	}

	if (a > b && a > c) {
		std::cout << "a" << std::endl;
	} else if (b > a && b > c) {
		std::cout << "b" << std::endl;
	} else if (c > a && c > b) {
		std::cout << "c" << std::endl;
	}
	
	return 0;
}