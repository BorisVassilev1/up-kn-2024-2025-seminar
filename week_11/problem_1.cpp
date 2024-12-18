#include <cstring>
#include <iostream>

bool isPrefix(const char* str1, const char* str2) {
	while (*str2 != '\0') {
		if (*str2 != *str1) { return false; }
		++str1, ++str2;
		if (*str1 == '\0') { return false; }
	}
	return true;
}

// problem 1
bool isSubstring(const char* str1, const char* str2) {
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (isPrefix(&str1[i], str2)) { return true; }
	}
	return false;
}

// problem 3
void findWordLocations(const char* str1, const char* word, int* arr, int& size) {
	int arr_size = 0;
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (isPrefix(&str1[i], word)) {
			arr[arr_size] = i;
			++arr_size;

			if (arr_size == size) { break; }
		}
	}
	size = arr_size;
}

// problem 4
void replaceWord(char* str1, const char* word, const char* replace) {
	int location;
	int size = 1;
	findWordLocations(str1, word, &location, size);
	if (size == 0) return;
	int word_len	= std::strlen(word);
	int replace_len = std::strlen(replace);
	int str1_len	= std::strlen(str1);
	int diff		= replace_len - word_len;

	if (diff > 0) {
		for (int i = str1_len; i >= location + word_len; --i) {
			str1[i + diff] = str1[i];
		}
	} else if (diff < 0) {
		for (int i = location + word_len; str1[i] != '\0'; ++i) {
			str1[i + diff] = str1[i];
		}
	}
	str1[str1_len + diff] = '\0';
	for (int i = 0; i < replace_len; ++i) {
		str1[location + i] = replace[i];
	}
}

int main() {
	char str1[1000] = "abcdefhg", str2[1000] = "cdef";
	std::cout << isSubstring(str1, str2) << std::endl;

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

	{
		char book[100] = "Mary had little lamb little lamb little lamb";
		replaceWord(book, "little", "a big");
		replaceWord(book, "little", "scaryyy");
		std::cout << book << std::endl;
	}
	return 0;
}
