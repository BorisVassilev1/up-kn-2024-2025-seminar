#include <iostream>

int main() {

	char str[101];
	std::cin.getline(str, 100);

	int count[256] = {0};

	for(int i = 0; str[i] != '\0'; ++i) {
		unsigned char c = str[i];
		count[c] = count[c] + 1;
	}

	char mostFrequent = 0;
	for(int i = 0; i < 256; ++i) {
		if(count[mostFrequent] < count[i]) 
			mostFrequent = i;
	}

	std::cout << mostFrequent << ' ' << count[mostFrequent] << std::endl;

	return 0;
}
