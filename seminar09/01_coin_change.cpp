#include <iostream>
#include <limits>
#include <vector>

int main() {
    int amount, n;
    if (!(std::cin >> amount >> n) || amount < 0 || n <= 0) {
        return 1;
    }

    std::vector<int> coins(n);
    bool hasOne = false;
    for (int& coin : coins) {
        if (!(std::cin >> coin) || coin <= 0) {
            return 1;
        }
        hasOne = hasOne || coin == 1;
    }
    if (!hasOne) {
        return 1;
    }

    const int inf = std::numeric_limits<int>::max();
    std::vector<int> best(amount + 1, inf);
    std::vector<int> previous(amount + 1, -1);
    best[0] = 0;
    for (int sum = 1; sum <= amount; ++sum) {
        for (int coin : coins) {
            if (coin <= sum && best[sum - coin] != inf &&
                best[sum - coin] + 1 < best[sum]) {
                best[sum] = best[sum - coin] + 1;
                previous[sum] = coin;
            }
        }
    }

    std::cout << best[amount] << '\n';
    for (int sum = amount; sum > 0; sum -= previous[sum]) {
        std::cout << previous[sum] << ' ';
    }
    std::cout << '\n';
}
