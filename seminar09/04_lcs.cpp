#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    if (!(std::cin >> n >> m) || n < 0 || m < 0) {
        return 1;
    }
    std::vector<int> a(n), b(m);
    for (int& value : a) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }
    for (int& value : b) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> sequence;
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            sequence.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    std::reverse(sequence.begin(), sequence.end());

    std::cout << sequence.size() << '\n';
    for (int value : sequence) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
