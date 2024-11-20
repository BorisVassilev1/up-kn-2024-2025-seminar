#include <iostream>

int strlen(char str[]) {
	int size = 0;
	while (str[size] != '\0') {
		++size;
	}
	return size;
}

// 1
void strcpy(char dest[], char src[]) {
	int len = strlen(src);
	for (int i = 0; i < len; ++i) {
		dest[i] = src[i];
	}
	dest[len] = '\0';
}


// 2 
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


// 3
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

// 4
char* strchr(char *str, char c) {
	
	int len = strlen(str);
	for(int i =0; i < len; ++i) {
		if(str[i] == c) {
			return str + i;
		}
	}
	
	return nullptr;
}

// 5
char* strrchr(char* str, char c) {
	
	int len = strlen(str);
	for(int i = len - 1; i >= 0; --i) {
		if(str[i] == c) {
			return str + i;
		}
	}
	
	return nullptr;
}

// 6
void printRange(char *begin, char *end) {
	
	/*int len = end - begin;
	for(int i =0; i < len; ++i) {
		std::cout << begin[i];
	}*/
	if(begin >= end) return;
	while(begin != end) {
		std::cout << *begin;
		++begin;
	}
}

// 7
void printFileNameAndExtension(char str[]) {
	
	char* slash = std::max(strrchr(str, '/'), strrchr(str, '\\'));
	if(slash == nullptr) slash = str;

	char *dot = strrchr(str, '.');
	if(dot == nullptr) {
		dot = str + strlen(str);
	}

	std::cout << "File name: ";
	printRange(slash + 1, dot);
	std::cout << std::endl << "Extension: ";
	printRange(dot + 1, str + strlen(str));
	std::cout << std::endl;
	
}

// 8
void printSuffixesBeginningWith(char str[], char c) {

	char* begin = str;
	while((begin = strchr(begin, c)) != nullptr) {
		printRange(begin, str + strlen(str));
		std::cout << std::endl;
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
		std::cout << std::endl;

	}

	{

		char str[100] = "D:\\Downloads\\windows_file.txt";
		char str2[100] = "/home/boby/Downloads/linux_file";
		printFileNameAndExtension(str);
		printFileNameAndExtension(str2);

	}

	{
		char str[100] = "Try not. Do, or do not. There is no try.";
		printSuffixesBeginningWith(str, 'T');
	}


}
