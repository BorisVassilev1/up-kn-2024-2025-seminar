#include <iostream>
#include <ostream>

const int MAT_SIZE = 30;

void readMatrix(int mat[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cin >> mat[i][j];
		}
	}
}

void printMatrix(int mat[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cout << mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

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

void transpose(int A[][MAT_SIZE], int x, int y) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < i; ++j) {
			std::swap(A[i][j], A[j][i]);
		}
	}
}

int dotProduct(int a[], int b[], int n) {
	int sum = 0;
	for(int i = 0; i < n; ++i) {
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

int main() {
	int A[MAT_SIZE][MAT_SIZE]{
		{0, 0, 1}, 
		{1, 0, 0}, 
		{0, 1, 0}};
	int B[MAT_SIZE][MAT_SIZE]{{1, 2, 3}, {40, 5, 60}, {7, 80, 9}};
	int C[MAT_SIZE][MAT_SIZE];

	std::cout << "local maximums : " << findLocalMax(B, 3, 3) << std::endl;

	int n = 3;
	//std::cin >> n;
	//if (n > MAT_SIZE) {
	//	std::cout << "ERROR" << std::endl;
	//	return 1;
	//}

	//readMatrix(A, n, n);
	printMatrix(A, n, n);
	
	transpose(A, n, n);
	std::cout << std::endl;
	printMatrix(A, n, n);


	if (multiplyMatrix(A, n, n, B, 3, 3, C)) {
		std::cout << "WRONG DIMENSIONS" << std::endl;
		return 1;
	}

	printMatrix(C, n, 3);
}
