#include <iostream>

int strlen(char str[]){
	int size = 0;
	while(str[size] != '\0') {
		++size;
	}
	return size;
}

void flipCase(char str[]) {
	for(int i = 0; str[i] != '\0'; ++i) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] += 'A' - 'a';
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}


int main() {
	char str[101];
	std::cin.getline(str, 100, '\n');

	int str_size = strlen(str);

	std::cout << "size of the string is: " << str_size << std::endl;
	
	flipCase(str);
	
	std::cout << str;
}
