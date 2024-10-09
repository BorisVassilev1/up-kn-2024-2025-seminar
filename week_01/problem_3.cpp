#include <iostream>
#include <cmath>

int main() {
    unsigned int a,b;

    std::cout << "Molq vavedi dve chisla:";
    std::cin >> a >> b;

    float result = std::sqrt(a * a + b * b) * (1./2) * 2;

    std::cout << result << std::endl;
}
