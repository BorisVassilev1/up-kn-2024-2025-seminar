#include <iostream>

int strlen(char str[]) {
	int size = 0;
	while (str[size] != '\0') {
		++size;
	}
	return size;
}

void strcpy(char dest[], char src[]) {
	int len = strlen(src);
	for (int i = 0; i < len; ++i) {
		dest[i] = src[i];
	}
	dest[len] = '\0';
}

//void strcat(char dest[], char src[]) {
//	int len_dest = strlen(dest);
//	int len_src	 = strlen(src);
//
//	for (int i = 0; i < len_src; ++i) {
//		dest[len_dest + i] = src[i];
//	}
//	dest[len_dest + len_src] = '\0';
//}


void strcat(char dest[], char src[]) {
	strcpy( dest + strlen(dest) , src);
}

int strcmp(char a[], char b[]) {
	int la = strlen(a);
	int lb = strlen(b);
	if(la != lb) {
		return la - lb;
	}

	for(int i = 0; i < la; ++i) {
		if(a[i] != b[i]) return a[i] - b[i];
	}
	
	/*while(*a != '\0') {
		if(*a != *b) return *a - *b;
		++a;
		++b;
	}*/

	return 0;
}


char* strchr(char *str, char c) {
	
	int len = strlen(str);
	for(int i =0; i < len; ++i) {
		if(str[i] == c) {
			return str + i;
		}
	}
	
	return nullptr;
}

void printRange(char *begin, char *end) {
	
	/*int len = end - begin;
	for(int i =0; i < len; ++i) {
		std::cout << begin[i];
	}*/
	
	while(begin != end) {
		std::cout << *begin;
		++begin;
	}
}

int main() {
	{
		char a[100] = "Hello my dear";
		char b[100] = "World";

		std::cout << a << " " << b << std::endl;

		strcpy(a, b);

		std::cout << a << " " << b << std::endl;
	}


	{
		
		char a[100] = "hello ";
		char b[100] = "world";

		strcat(a, b);
		std::cout << a << std::endl;

	}

	{
	
		char a[100] = "hallo";
		char b[100] = "hallo";

		std::cout << (a == b) << std::endl; // NEEE

		std::cout << (strcmp(a, b) == 0) << std::endl;

	}

	{
		
		char str[100] = "Hello, beautiful world!!!";
		
		printRange(strchr(str, 'b'), strchr(str, 'w'));


	}


}
