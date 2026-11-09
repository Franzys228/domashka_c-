#include <iostream>

long long gcd(long long a, long long b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int a, b;
    if (!(std::cin >> a >> b)) {
        return 1;
    }
    std::cout << gcd(a, b) << '\n';
}
