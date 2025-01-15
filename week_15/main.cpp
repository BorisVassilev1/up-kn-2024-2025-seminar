#include <algorithm>
#include <iostream>
#include <cstring>

char toLower(char c) {
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	return c;
}

bool mycmp(char *a, char *b) {
	int la = std::strlen(a);
	int lb = std::strlen(b);
	
	if(la != lb) return la < lb;
	
	for(int i = 0; i < la; ++i) {
		char ca = toLower(a[i]);
		char cb = toLower(b[i]);
		if(ca != cb) return ca < cb;
	}
	return false;
}


bool isSpace(char c) {
	return c == ' ' || c == '\n' || c == '\t';
}

char* inputString() {
	
	int size = 4;
	char* str = new char[size];
	int index = 0;
	char c;
	
	while(isSpace(std::cin.peek())) {
		std::cin.get();
	}

	while(!isSpace(c = std::cin.get())) {
		if(index == size-1) {
			size = size * 2;
			char* new_str = new char[size];
			for(int i = 0; i < index; ++i) {
				new_str[i] = str[i];
			}
			delete [] str;
			str = new_str;
		}

		str[index] = c;
		++index;
	}
	str[index] = '\0';

	return str;
}

int main() {

	int n;
	std::cin >> n;
	
	char ** strings = new char*[n];
	for(int i = 0; i < n; ++i) {
		strings[i] = inputString();
	}
	
	std::sort(strings, strings + n, mycmp);

	for(int i = 0; i < n; ++i) {
		std::cout << strings[i] << std::endl;
	}


	for(int i = 0; i < n; ++i) {
		delete [] strings[i];
	}
	delete [] strings;
	
}
