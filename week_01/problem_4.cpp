#include <iostream>

int main() {

    std::cout << "Моля въведете температурата на водата: " ;

    double temp;
    std::cin >> temp;

    std::cout << std::boolalpha << (temp >= 100) << std::endl;
}