#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << "#";
		}
		cout << endl;
	}

	return 0;
}
