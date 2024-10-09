#include <iostream>

int main() {

    char a;
    std::cin >> a;
    //a = std::cin.get();

    std::cout << (int)(a - 'a')<< std::endl;
    std::cout << "your symbol is: \'" << a << "\'" << std::endl;
}