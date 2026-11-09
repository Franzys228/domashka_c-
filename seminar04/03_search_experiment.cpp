#include "search_strategies.hpp"

#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

struct Result {
    unsigned long long comparisons;
    double microseconds;
};

Result measure(const std::vector<int>& initial,
               const std::vector<int>& queries,
               SearchStrategy strategy) {
    std::vector<SearchItem> items(initial.size());
    for (int i = 0; i < static_cast<int>(initial.size()); ++i) {
        items[i] = {initial[i], 0};
    }

    unsigned long long comparisons = 0;
    auto start = std::chrono::steady_clock::now();
    for (int target : queries) {
        search(items, target, strategy, comparisons);
    }
    auto stop = std::chrono::steady_clock::now();
    double total = std::chrono::duration<double, std::micro>(stop - start).count();
    return {comparisons, total / queries.size()};
}

int main() {
    const std::array<int, 4> sizes = {100, 500, 2000, 8000};
    const std::array<SearchStrategy, 4> strategies = {
        SearchStrategy::linear, SearchStrategy::moveToFront,
        SearchStrategy::transpose, SearchStrategy::frequency
    };
    const std::array<const char*, 4> names = {
        "linear", "front", "transpose", "frequency"
    };
    constexpr int queryCount = 4000;

    std::cout << "n,distribution,strategy,avg_comparisons,avg_microseconds\n";
    for (int n : sizes) {
        std::vector<int> initial(n);
        for (int i = 0; i < n; ++i) {
            initial[i] = i;
        }

        for (int distribution = 0; distribution < 2; ++distribution) {
            std::mt19937 generator(2026 + n + distribution);
            std::uniform_int_distribution<int> pick(0, n - 1);
            std::vector<int> queries(queryCount);
            for (int& target : queries) {
                if (distribution == 1 && generator() % 100 < 80) {
                    target = n - 1;
                } else {
                    target = pick(generator);
                }
            }

            const char* distributionName =
                distribution == 0 ? "uniform" : "skewed";
            for (int i = 0; i < 4; ++i) {
                Result result = measure(initial, queries, strategies[i]);
                std::cout << n << ',' << distributionName << ',' << names[i]
                          << ',' << static_cast<double>(result.comparisons) /
                                        queryCount
                          << ',' << result.microseconds << '\n';
            }
        }
    }
}
