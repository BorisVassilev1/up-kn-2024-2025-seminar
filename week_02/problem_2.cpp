#include <iostream>

int main() {
	int num;	 // abcd
	std::cin >> num;
	int num_copy = num;
	
    int a, b, c, d;
    // ---------------------------
	d = num_copy % 10;
	num_copy /= 10;
	c = num_copy % 10;
	num_copy /= 10;
	b = num_copy % 10;
	num_copy /= 10;
	a = num_copy % 10;
	// std::cout << a << " " << b  << " " << c << " " << d << std::endl;
    // ---------------------------

	if (a <= b && b <= c && c <= d) {
		std::cout << d << c << b << a << std::endl;
	} else {
		std::cout << num * 2 << std::endl;
	}
}