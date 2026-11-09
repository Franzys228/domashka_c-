#include <iostream>

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }

    unsigned long long prev = 1;
    unsigned long long cur = 1;
    for (int i = 2; i <= n; ++i) {
        unsigned long long next = prev + cur;
        prev = cur;
        cur = next;
    }
    return cur;
}

int main() {
    int n;
    if (!(std::cin >> n) || n < 0 || n > 92) {
        return 1;
    }
    std::cout << fibonacci(n) << '\n';
}
