#include <array>
#include <iostream>
#include <limits>

int main() {
    int n, start;
    if (!(std::cin >> n >> start) || n < 1 || start < 0 || start > 9) {
        return 1;
    }

    const std::array<std::array<int, 3>, 10> moves = {{
        {{4, 6, -1}}, {{6, 8, -1}}, {{7, 9, -1}}, {{4, 8, -1}},
        {{0, 3, 9}}, {{-1, -1, -1}}, {{0, 1, 7}}, {{2, 6, -1}},
        {{1, 3, -1}}, {{2, 4, -1}}
    }};
    std::array<unsigned long long, 10> counts{};
    counts[start] = 1;
    const auto max = std::numeric_limits<unsigned long long>::max();

    for (int length = 1; length < n; ++length) {
        std::array<unsigned long long, 10> next{};
        for (int digit = 0; digit < 10; ++digit) {
            for (int to : moves[digit]) {
                if (to == -1) {
                    continue;
                }
                if (next[to] > max - counts[digit]) {
                    std::cerr << "Count does not fit in unsigned long long\n";
                    return 1;
                }
                next[to] += counts[digit];
            }
        }
        counts = next;
    }

    unsigned long long total = 0;
    for (unsigned long long count : counts) {
        if (total > max - count) {
            std::cerr << "Count does not fit in unsigned long long\n";
            return 1;
        }
        total += count;
    }
    std::cout << total << '\n';
}
