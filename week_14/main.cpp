#include <iostream>
#include <algorithm>

char *malloc(unsigned int size) { return new char[size]; }

template <class T>
T *sortCopy(const T *arr, unsigned int size) {
	T *result = new T[size];
	// T *result = (T*)malloc(size * sizeof(T)); NE!!!

	for (unsigned i = 0; i < size; ++i) {
		result[i] = arr[i];
	}
	std::sort(result, result + size);
	return result;
}

template <class T>
T **makeMatrix(unsigned x, unsigned y) {
	T **result = new T *[x];
	T  *data   = new T[x * y];

	for (unsigned i = 0; i < x; ++i) {
		result[i] = data + i * y;
	}
	return result;
}

template <class T>
void deleteMatrix(const T *const *const mat) {
	delete[] *mat;
	delete[] mat;
}

void printMatrix(int **mat, int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cout << mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	{
		int *arr = new int[]{5, 4, 3, 2, 1};

		int *result = sortCopy(arr, 5);
		for (int i = 0; i < 5; ++i) {
			std::cout << result[i] << " ";
		}
		std::cout << std::endl;

		delete[] arr;
		delete[] result;
	}

	{
		int **m = makeMatrix<int>(5, 5);
		printMatrix(m, 5, 5);

		deleteMatrix<int>(m);
	}
	return 0;
}
