#include <iostream>
#include <ostream>

const int MAT_SIZE = 30;

// 1
void readMatrix(int mat[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cin >> mat[i][j];
		}
	}
}

// 2
void printMatrix(int mat[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cout << mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

// 3
int findLocalMax(int mat[][MAT_SIZE], int x, int y) {
	int count = 0;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			int curr	   = mat[i][j];
			int less_count = 0;
			if (i == 0 || curr > mat[i - 1][j]) ++less_count;
			if (i == x - 1 || curr > mat[i + 1][j]) ++less_count;
			if (j == 0 || curr > mat[i][j - 1]) ++less_count;
			if (j == y - 1 || curr > mat[i][j + 1]) ++less_count;

			if (less_count == 4) ++count;
		}
	}

	return count;
}

// 4
void sumMatrix(int A[][MAT_SIZE], int B[][MAT_SIZE], int C[][MAT_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

// 5 + 7
void transpose(int A[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < i; ++j) {
			std::swap(A[i][j], A[j][i]);
		}
	}
}

int dotProduct(int a[], int b[], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[i];
	}
	return sum;
}

bool multiplyMatrix(int A[][MAT_SIZE], int n, int k1, int B[][MAT_SIZE], int k2, int m, int C[][MAT_SIZE]) {
	if (k1 != k2) { return 1; }
	int k = k1;

	transpose(B, k, m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			C[i][j] = dotProduct(A[i], B[j], k);
		}
	}

	transpose(B, m, k);

	return 0;
}

// 6
bool areEqual(int A[][MAT_SIZE], int B[][MAT_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] != B[i][j]) return 0;
		}
	}
	return 1;
}

// 8
void copyMatrix(int A[][MAT_SIZE], int B[][MAT_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			B[i][j] = A[i][j];
		}
	}
}

bool isSymmetric(int A[][MAT_SIZE], int n) {
	int B[MAT_SIZE][MAT_SIZE];
	copyMatrix(A, B, n, n);
	transpose(B, n, n);
	return areEqual(A, B, n, n);
}

// bool isSymmetric(int A[][MAT_SIZE], int n) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < i; ++j) {
//			if (A[i][j] != A[j][i]) return 0;
//		}
//	}
//	return 1;
// }

// 9
void bubbleSort(int arr[], int size) {
	for (int j = 0; j < size - 1; ++j)
		for (int i = 0; i < size - 1; ++i)
			if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
}

void sortMatrix(int A[][MAT_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i) {
		bubbleSort(A[i], m);
	}
}

/*
 * за задачи 10 и 11 питайте колегите на практикума
 */

int main() {
	int A[MAT_SIZE][MAT_SIZE]{{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
	int B[MAT_SIZE][MAT_SIZE]{{3, 2, 1}, {40, 5, 60}, {7, 80, 9}};
	int C[MAT_SIZE][MAT_SIZE];
	int Sym[MAT_SIZE][MAT_SIZE]{{1, 2, 3}, {2, 4, 5}, {3, 5, 6}};

	std::cout << "local maximums : " << findLocalMax(B, 3, 3) << std::endl;

	int n = 3;
	// std::cin >> n;
	// if (n > MAT_SIZE) {
	//	std::cout << "ERROR" << std::endl;
	//	return 1;
	// }

	// readMatrix(A, n, n);
	std::cout << "Matrix A:" << std::endl;
	printMatrix(A, n, n);
	std::cout << std::endl;
	std::cout << "Transposed matrix:" << std::endl;
	transpose(A, n, n);
	printMatrix(A, n, n);

	std::cout << std::endl;
	std::cout << "Matrix B:" << std::endl;
	printMatrix(B, n, n);

	if (multiplyMatrix(A, n, n, B, 3, 3, C)) {
		std::cout << "WRONG DIMENSIONS" << std::endl;
		return 1;
	}

	std::cout << std::endl;
	std::cout << "Matrix A * B:" << std::endl;
	printMatrix(C, n, 3);

	std::cout << std::endl;
	std::cout << "Matrix Sym" << std::endl;
	printMatrix(Sym, 3, 3);
	std::cout << "Is symmetric: " << std::boolalpha << isSymmetric(Sym, 3) << std::endl;

	std::cout << std::endl;
	std::cout << "Sorted matrix AxB:" << std::endl;
	sortMatrix(C, n, 3);
	printMatrix(C, n, 3);
}
