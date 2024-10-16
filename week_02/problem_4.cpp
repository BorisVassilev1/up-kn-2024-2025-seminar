#include <iostream>

int main() {

	char a;
	std::cin >> a;
	//a = std::cin.get();

	if( a >= 'a' && a <= 'z') {
		std::cout << (int)(a - 'a') << std::endl;
	}
	else if( a >= 'A' && a <= 'Z') {
		std::cout << (int)(a - 'A') << std::endl;
	} else {
		std::cout << "your symbol is not a letter!!!!" << std::endl;
	}

	return 0;
}
