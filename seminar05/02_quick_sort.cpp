#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int>& values, int left, int right) {
    int pivot = values[left + (right - left) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        do {
            ++i;
        } while (values[i] < pivot);
        do {
            --j;
        } while (values[j] > pivot);
        if (i >= j) {
            return j;
        }
        std::swap(values[i], values[j]);
    }
}

void quickSort(std::vector<int>& values, int left, int right) {
    while (left < right) {
        int middle = partition(values, left, right);
        if (middle - left < right - middle) {
            quickSort(values, left, middle);
            left = middle + 1;
        } else {
            quickSort(values, middle + 1, right);
            right = middle;
        }
    }
}

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
    quickSort(values, 0, static_cast<int>(values.size()) - 1);
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
