#include <iostream>
#include <vector>

int binarySearchRecursive(const std::vector<int>& values, int target,
                          int left, int right) {
    if (left > right) {
        return -1;
    }
    int middle = left + (right - left) / 2;
    if (values[middle] == target) {
        return middle;
    }
    if (values[middle] < target) {
        return binarySearchRecursive(values, target, middle + 1, right);
    }
    return binarySearchRecursive(values, target, left, middle - 1);
}

int binarySearchIterative(const std::vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (values[middle] == target) {
            return middle;
        }
        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    if (!(std::cin >> n >> target) || n < 0) {
        return 1;
    }
    std::vector<int> values(n);
    for (int& value : values) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }

    int recursive = binarySearchRecursive(
        values, target, 0, static_cast<int>(values.size()) - 1);
    int iterative = binarySearchIterative(values, target);
    std::cout << recursive << ' ' << iterative << '\n';
}
