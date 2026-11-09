#include <iostream>
#include <utility>
#include <vector>

void siftDown(std::vector<int>& values, int size, int root) {
    while (root < size / 2) {
        int child = root * 2 + 1;
        if (child + 1 < size && values[child] < values[child + 1]) {
            ++child;
        }
        if (values[root] >= values[child]) {
            return;
        }
        std::swap(values[root], values[child]);
        root = child;
    }
}

void heapSort(std::vector<int>& values) {
    int n = static_cast<int>(values.size());
    for (int i = n / 2; i > 0; --i) {
        siftDown(values, n, i - 1);
    }
    for (int end = n - 1; end > 0; --end) {
        std::swap(values[0], values[end]);
        siftDown(values, end, 0);
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
    heapSort(values);
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
