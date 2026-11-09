#ifndef SEARCH_STRATEGIES_HPP
#define SEARCH_STRATEGIES_HPP

#include <vector>

struct SearchItem {
    int value;
    unsigned long long count;
};

enum class SearchStrategy {
    linear,
    moveToFront,
    transpose,
    frequency
};

inline int search(std::vector<SearchItem>& items, int target,
                  SearchStrategy strategy,
                  unsigned long long& comparisons) {
    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        ++comparisons;
        if (items[i].value != target) {
            continue;
        }

        if (strategy == SearchStrategy::moveToFront && i > 0) {
            SearchItem item = items[i];
            for (int j = i; j > 0; --j) {
                items[j] = items[j - 1];
            }
            items[0] = item;
        } else if (strategy == SearchStrategy::transpose && i > 0) {
            SearchItem item = items[i];
            items[i] = items[i - 1];
            items[i - 1] = item;
        } else if (strategy == SearchStrategy::frequency) {
            ++items[i].count;
            if (i > 0 && items[i].count > items[i - 1].count) {
                SearchItem item = items[i];
                items[i] = items[i - 1];
                items[i - 1] = item;
            }
        }
        return i;
    }
    return -1;
}

#endif
