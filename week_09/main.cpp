#include <iostream>

bool canBeSumOf(int sum, int arr[], int size) {
	if (size == 0) return sum == 0;
	if (sum == 0) return true;
	if (sum < 0) return false;

	return canBeSumOf(sum, arr + 1, size - 1) || canBeSumOf(sum - arr[0], arr + 1, size - 1);
}

int main() {

	int arr[] = {1, 10, 2, 5, 17};
	std::cout << canBeSumOf(8, arr, 5) << std::endl;
	std::cout << canBeSumOf(9, arr, 5) << std::endl;

}
