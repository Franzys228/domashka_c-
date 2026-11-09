#include <iostream>

int main() {
    constexpr int n = 100;
    bool composite[n + 1]{};

    for (int i = 2; i <= n / i; ++i) {
        if (!composite[i]) {
            for (int j = i * i; j <= n; j += i) {
                composite[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!composite[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
}
