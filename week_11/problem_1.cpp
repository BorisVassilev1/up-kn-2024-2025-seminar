#include <algorithm>
#include <atomic>
#include <iostream>

bool prefix(char* str1, char* str2) {
	while (*str2 != '\0') {
		if (*str2 != *str1) { return false; }
		++str1, ++str2;
		if (*str1 == '\0') { return false; }
	}
	return true;
}

bool podniz(char* str1, char* str2) {
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (prefix(&str1[i], str2)) { return true; }
	}
	return false;
}

// problem 3
void findWordLocations(char* str1, char* word, int* arr, int& size) {
	int arr_size = 0;
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (prefix(&str1[i], word)) {
			arr[arr_size] = i;
			++arr_size;

			if (arr_size == size) { break; }
		}
	}
	size = arr_size;
}

int main() {
	char str1[1000] = "abcdefhg", str2[1000] = "cdef";
	std::cout << podniz(str1, str2) << std::endl;

	{
		char book[] = "Mary had little lamb little lamb little lamb";
		char word[] = "little";
		int	 locations[2];
		int	 size = 2;
		findWordLocations(book, word, locations, size);

		for (int i = 0; i < size; ++i) {
			std::cout << locations[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
