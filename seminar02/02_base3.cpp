#include <iostream>

void printBase3(int value) {
    long long number = value;
    if (number < 0) {
        std::cout << '-';
        number = -number;
    }

    char digits[32];
    int size = 0;
    do {
        digits[size++] = static_cast<char>('0' + number % 3);
        number /= 3;
    } while (number > 0);

    while (size > 0) {
        std::cout << digits[--size];
    }
    std::cout << '\n';
}

int main() {
    int value;
    if (!(std::cin >> value)) {
        return 1;
    }
    printBase3(value);
}
