#include <cmath>
#include <iostream>

template <typename T>
unsigned long long fibonacciBinet(int n) {
    const T root5 = std::sqrt(T(5));
    const T phi = (T(1) + root5) / T(2);
    const T value = std::pow(phi, n + 1) / root5 + T(0.5);
    return static_cast<unsigned long long>(value);
}

int main() {
    unsigned long long firstWrongFloat = 0;
    unsigned long long firstWrongDouble = 0;
    unsigned long long prev = 1;
    unsigned long long cur = 1;

    for (int n = 0; n <= 92; ++n) {
        unsigned long long exact = 1;
        if (n >= 2) {
            exact = prev + cur;
            prev = cur;
            cur = exact;
        }

        if (firstWrongFloat == 0 && fibonacciBinet<float>(n) != exact) {
            firstWrongFloat = n;
        }
        if (firstWrongDouble == 0 && fibonacciBinet<double>(n) != exact) {
            firstWrongDouble = n;
        }
    }

    if (firstWrongFloat == 0 || firstWrongDouble == 0) {
        return 1;
    }
    std::cout << "float: " << firstWrongFloat << '\n';
    std::cout << "double: " << firstWrongDouble << '\n';
}
