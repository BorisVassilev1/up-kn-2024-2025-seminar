#include <iostream>

int f(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return f(n-1) + f(n-2);
}

long long f2(long long n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	long long a = 0, b = 1;
	for(int i = 0; i < n-1; ++i) {
		long long c =  a + b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << f2(n) << std::endl;
}