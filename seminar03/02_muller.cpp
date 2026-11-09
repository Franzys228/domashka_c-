#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

template <typename T>
void run(const char* name) {
    T prev = 4;
    T cur = T(4.25);
    int steps = 0;

    for (; steps < 10000; ++steps) {
        T next = T(108) - (T(815) - T(1500) / prev) / cur;
        if (!std::isfinite(next) || next == cur) {
            break;
        }
        prev = cur;
        cur = next;
    }

    std::cout << name << ": "
              << std::setprecision(std::numeric_limits<T>::max_digits10)
              << cur << ", steps=" << steps << '\n';
}

int main() {
    run<float>("float");
    run<double>("double");
}
