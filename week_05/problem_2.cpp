#include <iostream>

void bubbleSort(int arr[], int size) {
	for (int j = 0; j < size - 1; ++j) {
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				int temp   = arr[i];
				arr[i]	   = arr[i + 1];
				arr[i + 1] = temp;
				// std::swap(arr[i], arr[i+1]);
			}
		}
	}
}

void inputArray(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	int arr[100];
	int n;
	std::cin >> n;

	inputArray(arr, n);
	bubbleSort(arr, n);
	printArray(arr, n);
	return 0;
}
