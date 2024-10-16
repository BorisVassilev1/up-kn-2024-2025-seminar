#include <ios>
#include <iostream>

int main() {

	int num;
	std::cin >> num;
	std::cout << std::boolalpha << !(num & (num-1)) << std::endl;

	return 0;
}
