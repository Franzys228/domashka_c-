#include <iostream>
#include <vector>

bool findPair(const std::vector<int>& values, long long target,
              int& left, int& right) {
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(values.size()); ++j) {
            if (static_cast<long long>(values[i]) + values[j] == target) {
                left = i;
                right = j;
                return true;
            }
        }
    }
    return false;
}

bool findPairSorted(const std::vector<int>& values, long long target,
                    int& left, int& right) {
    int i = 0;
    int j = static_cast<int>(values.size()) - 1;
    while (i < j) {
        long long sum = static_cast<long long>(values[i]) + values[j];
        if (sum == target) {
            left = i;
            right = j;
            return true;
        }
        if (sum < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}

int main() {
    int n;
    long long target;
    if (!(std::cin >> n >> target) || n < 0) {
        return 1;
    }
    std::vector<int> values(n);
    for (int& value : values) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }

    int left, right;
    if (findPair(values, target, left, right)) {
        std::cout << "quadratic: " << left << ' ' << right << '\n';
    } else {
        std::cout << "quadratic: not found\n";
    }

    bool sorted = true;
    for (int i = 1; i < n; ++i) {
        if (values[i - 1] > values[i]) {
            sorted = false;
        }
    }
    if (sorted) {
        if (findPairSorted(values, target, left, right)) {
            std::cout << "sorted: " << left << ' ' << right << '\n';
        } else {
            std::cout << "sorted: not found\n";
        }
    }
}
