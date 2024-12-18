#include <iostream>
#include "bench.hpp"

const int MAX_N = 1000000;

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

void merge(int arr[], int l1, int l2, int l3, int result[]) {
	// arr :   ... [l1 ...][l2 ...]l3 ...
	// result: ... [l1 ...        ]l3 ...
	int i1 = l1, i2 = l2;
	int m = l1;

	while (i1 < l2 || i2 < l3) {
		if (i1 == l2) {
			result[m] = arr[i2];
			++i2;
		} else if (i2 == l3) {
			result[m] = arr[i1];
			++i1;
		} else if (arr[i1] < arr[i2]) {
			result[m] = arr[i1];
			++i1;
		} else {
			result[m] = arr[i2];
			++i2;
		}
		++m;
	}
}

void mergeSort(int A[], int B[], int begin, int end) {
	int size = end - begin;
	if (size == 1) return;

	int mid = (begin + end) / 2;
	mergeSort(A, B, begin, mid);
	mergeSort(A, B, mid, end);

	merge(A, begin, mid, end, B);

	for (int i = begin; i < end; ++i) {
		A[i] = B[i];
	}
}

void mergeSort_2(int A[], int B[], int begin, int end, int depth = 0) {
	int size = end - begin;
	if (size == 1) {
		if (depth % 2 == 1) B[begin] = A[begin];
		return;
	}

	int mid = (begin + end) / 2;

	mergeSort_2(A, B, begin, mid, depth + 1);
	mergeSort_2(A, B, mid, end, depth + 1);

	if (depth % 2 == 0) merge(B, begin, mid, end, A);
	else merge(A, begin, mid, end, B);
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[MAX_N];
	int B[MAX_N];
	srand(time(0));

	// std::cout << "Bubble sort: ";
	// BENCH(
	//	{
	//		for (int i = 0; i < MAX_N; ++i) {
	//			arr[i] = rand() % 1000;
	//		}
	//		bubbleSort(arr, MAX_N);
	//	},
	//	10, std::chrono::microseconds);
	// std::cout << std::endl;

	std::cout << "Merge sort: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			mergeSort(arr, B, 0, MAX_N);
		},
		10, std::chrono::milliseconds);
	std::cout << std::endl;

	std::cout << "Merge sort 2: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			mergeSort_2(arr, B, 0, MAX_N);
		},
		10, std::chrono::milliseconds);
	std::cout << std::endl;

	std::cout << "std::sort: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			std::sort(arr, arr + MAX_N);
		},
		10, std::chrono::milliseconds);
	std::cout << std::endl;

	{
		int arr[] = {4, 3, 2, 1, 8, 7, 6, 5, 10, 9, 16, 15, 14, 13, 12, 11};
		mergeSort_2(arr, B, 0, 16);
		printArray(arr, 16);
	}

	{
		int a[] = {1, 3, 5, 7, 9};
		mergeSort_2(a, B, 0, 5);
		printArray(a, 5);
	}

	{
		int a[] = {9, 7, 5, 3, 1, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
		mergeSort_2(a, B, 0, 20);
		printArray(a, 20);
	}
}
