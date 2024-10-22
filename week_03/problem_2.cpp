#include <climits>
#include <iostream>

int max(const int a, const int b) {
	if(a > b) return a;
	else return b;
}

int main() {

	int n;
	int maximum = 0;
	do {
		std::cin >> n;
		maximum = max(n, maximum);
	} while(n != 0);

	std::cout << maximum << std::endl;
}