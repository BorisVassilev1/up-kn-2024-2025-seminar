#include <iostream>
#include "bench.hpp"

const int MAX_N = 10000;

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

void mergeSort(int arr[], int aux[], int begin, int end) {
	int size = end - begin;
	if (size == 1) return;

	int mid = (begin + end) / 2;
	mergeSort(arr, aux, begin, mid);
	mergeSort(arr, aux, mid, end);

	merge(arr, begin, mid, end, aux);

	for (int i = begin; i < end; ++i) {
		arr[i] = aux[i];
	}
}

void mergeSort_2(int arr[], int aux[], int begin, int end, int depth = 0) {
	int size = end - begin;
	if (size == 1) return;

	int mid = (begin + end) / 2;
	mergeSort(arr, aux, begin, mid);
	mergeSort(arr, aux, mid, end);

	if(depth % 2 == 0)
		merge(arr, begin, mid, end, aux);
	else
		merge(aux, begin, mid, end, arr);
}


int main() {
	int arr[MAX_N];
	int B[MAX_N];
	srand(time(0));

	std::cout << "Bubble sort: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 1000;
			}
			bubbleSort(arr, MAX_N);
		},
		10, std::chrono::microseconds);
	std::cout << std::endl;

	std::cout << "Merge sort: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			mergeSort(arr, B, 0, MAX_N);
		},
		10, std::chrono::microseconds);
	std::cout << std::endl;

	std::cout << "Merge sort 2: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			mergeSort_2(arr, B, 0, MAX_N);
		},
		10, std::chrono::microseconds);
	std::cout << std::endl;

	std::cout << "std::sort: ";
	BENCH(
		{
			for (int i = 0; i < MAX_N; ++i) {
				arr[i] = rand() % 10000;
			}
			std::sort(arr, arr + MAX_N);
		},
		10, std::chrono::microseconds);
	std::cout << std::endl;

	// print finally
	//for (int i = 0; i < MAX_N; ++i) {
	//	std::cout << arr[i] << " ";
	//}
}
