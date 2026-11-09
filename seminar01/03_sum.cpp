#include <iostream>

int main() {
    long long value;
    long long sum = 0;
    while (std::cin >> value && value != 0) {
        sum += value;
    }
    std::cout << sum << '\n';
}
