#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        return 1;
    }

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        double value;
        if (!(std::cin >> value)) {
            return 1;
        }
        sum += value;
    }

    std::cout << sum / n << '\n';
}
