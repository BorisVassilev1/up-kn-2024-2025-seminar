#include <atomic>
#include <cassert>
#include <climits>
#include <iostream>
#include <cassert>

// 2
int helper_maxDigit(int n, int k) {
	if (n == 0) return k;
	return helper_maxDigit(n / 10, std::max(k, n % 10));
}

int maxDigit(int n) { return helper_maxDigit(n, 0); }

// 3
int tenToThePowerLengthOfMinusOne(int n) {
	if (n < 10) return 1;
	return 10 * tenToThePowerLengthOfMinusOne(n / 10);
}

int rev_helper(int n, int k) {
	if (n == 0) return 0;
	return (n % 10) * k + rev_helper(n / 10, k / 10);
}

int rev(int n) { return rev_helper(n, tenToThePowerLengthOfMinusOne(n)); }

// 4

int fib_helper(int n, int a, int b) {
	if (n == 0) return a;
	return fib_helper(n - 1, b, a + b);
}

int fib(int n) { return fib_helper(n, 0, 1); }

// 5

int minElement_h(int arr[], int n, int i, int minInd) {
	if(i == n) return minInd;
	if(arr[minInd] > arr[i]) minInd = i;
	return minElement_h(arr, n, i+1, minInd);
}

int minElement(int arr[], int n) { return minElement_h(arr, n, 0, 0); };

// 6
void sort(int arr[], int n) {
	if(n == 1)
		return;
	int minInd = minElement(arr, n);
	if(minInd != 0) std::swap(arr[minInd], arr[0]);
	sort(arr+1, n-1);
}


int main() {
	{
		int n = 1234321;
		std::cout << "maxDigit: " << maxDigit(n) << std::endl;
	}

	{
		int n = 1234;
		std::cout << "rev: " << rev(n) << std::endl;
		std::cout << tenToThePowerLengthOfMinusOne(n) << std::endl;
	}

	{
		assert(fib(0) == 0);
		assert(fib(1) == 1);
		assert(fib(2) == 1);
		assert(fib(3) == 2);

		std::cout << fib(10000) << std::endl;
	}

	{
		int arr[] = {5,4,3,2,1};
		sort(arr, 5);
		for(int i = 0; i < 5; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}
