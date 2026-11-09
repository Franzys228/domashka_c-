#include <iostream>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        return 1;
    }
    std::cout << (isPrime(n) ? "true" : "false") << '\n';
}
