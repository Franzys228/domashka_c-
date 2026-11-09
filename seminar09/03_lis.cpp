#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n) || n < 0) {
        return 1;
    }
    std::vector<int> values(n);
    for (int& value : values) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }
    if (n == 0) {
        std::cout << "0\n\n";
        return 0;
    }

    std::vector<int> tails;
    std::vector<int> tailIndex;
    std::vector<int> previous(n, -1);
    for (int i = 0; i < n; ++i) {
        int pos = static_cast<int>(
            std::lower_bound(tails.begin(), tails.end(), values[i]) -
            tails.begin());
        if (pos > 0) {
            previous[i] = tailIndex[pos - 1];
        }
        if (pos == static_cast<int>(tails.size())) {
            tails.push_back(values[i]);
            tailIndex.push_back(i);
        } else {
            tails[pos] = values[i];
            tailIndex[pos] = i;
        }
    }

    std::vector<int> sequence;
    for (int i = tailIndex.back(); i != -1; i = previous[i]) {
        sequence.push_back(values[i]);
    }
    std::reverse(sequence.begin(), sequence.end());

    std::cout << sequence.size() << '\n';
    for (int value : sequence) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
