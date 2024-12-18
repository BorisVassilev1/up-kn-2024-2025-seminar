#include <iostream>

bool isdigit(char c) {
	if (c >= '0' && c <= '9') { return true; }
	return false;
}

void extractNumbers(char *str1, int arr[], int &size) {
	int j = 0;
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (isdigit(str1[i])) {
			int num = 0;
			while (isdigit(str1[i])) {
				num = num * 10 + str1[i] - '0';
				++i;
			}
			arr[j] = num;
			++j;
			if (j == size) { break; }
		}
	}
	size = j;
}

int main() {
	char str[] = "12ab 12cd 34588b13_";
	int	 arr[17];
	int	 size = 3;

	extractNumbers(str, arr, size);

	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}
