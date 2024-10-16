#include <iostream>

int digitsCount(int n) {
    if(n == 0) return 1;
    
    int result = 0;

    while(n != 0) {
        n /= 10;
        ++result;
    }

    return result;
}

void printReversedDigits(int n) {
    while(n != 0) {
        std::cout << n % 10;
        n /= 10;
    }
    std::cout << std::endl;
}

int main() {

    int n;
    std::cin >> n;
    std::cout << digitsCount(n) << std::endl;
    printReversedDigits(n);

}