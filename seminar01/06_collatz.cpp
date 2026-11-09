#include <iostream>

int main() {
    int start;
    if (!(std::cin >> start) || start <= 0) {
        return 1;
    }

    long long value = start;
    int index = 0;
    while (value != 1) {
        if (value % 2 == 0) {
            value /= 2;
        } else {
            value = 3 * value + 1;
        }
        ++index;
    }
    std::cout << index << '\n';
}
