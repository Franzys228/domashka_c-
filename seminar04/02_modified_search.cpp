#include "search_strategies.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string mode;
    int n, q;
    if (!(std::cin >> mode >> n >> q) || n < 0 || q < 0) {
        return 1;
    }

    SearchStrategy strategy;
    if (mode == "linear") {
        strategy = SearchStrategy::linear;
    } else if (mode == "front") {
        strategy = SearchStrategy::moveToFront;
    } else if (mode == "transpose") {
        strategy = SearchStrategy::transpose;
    } else if (mode == "frequency") {
        strategy = SearchStrategy::frequency;
    } else {
        return 1;
    }

    std::vector<SearchItem> items(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> items[i].value)) {
            return 1;
        }
        items[i].count = 0;
    }

    unsigned long long comparisons = 0;
    for (int i = 0; i < q; ++i) {
        int target;
        if (!(std::cin >> target)) {
            return 1;
        }
        std::cout << search(items, target, strategy, comparisons) << '\n';
    }
    std::cerr << "comparisons: " << comparisons << '\n';
}
