#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printFirstRowOfChessboard(int a) {
	cout << '+';
	for (int i = 0; i < a; ++i)
		cout << '-';
	cout << '+' << endl;
}

void printChessboard(int a) {
	printFirstRowOfChessboard(a);
	for (int i = 0; i < a; ++i) {
		
		cout << '|';
		for (int j = 0; j < a; ++j) {
			if ((i + j) % 2 == 0) {
				cout << '#';
			} else {
				cout << ' ';
			}
		}
		cout << '|' << endl;

	}
	printFirstRowOfChessboard(a);
}

int main() {
	int a;
	cin >> a;

	printChessboard(a);

	return 0;
}
