#include <iomanip>
#include <iostream>
#include <vector>

struct Item {
    long double weight;
    long double profit;
};

int main() {
    int n;
    long double limit;
    if (!(std::cin >> n >> limit) || n < 0 || n >= 30 || limit < 0) {
        return 1;
    }

    std::vector<Item> items(n);
    for (Item& item : items) {
        if (!(std::cin >> item.weight >> item.profit) ||
            item.weight <= 0 || item.profit <= 0) {
            return 1;
        }
    }

    long double bestProfit = 0;
    unsigned int bestMask = 0;
    const unsigned int masks = 1u << n;
    for (unsigned int mask = 0; mask < masks; ++mask) {
        long double weight = 0;
        long double profit = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1u) {
                weight += items[i].weight;
                profit += items[i].profit;
            }
        }
        if (weight < limit && profit > bestProfit) {
            bestProfit = profit;
            bestMask = mask;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << bestProfit << '\n';
    for (int i = 0; i < n; ++i) {
        if ((bestMask >> i) & 1u) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
}
