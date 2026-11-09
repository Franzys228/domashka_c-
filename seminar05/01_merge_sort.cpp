#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& values,
               std::vector<int>& buffer,
               int left,
               int right) {
    if (right - left <= 1) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(values, buffer, left, middle);
    mergeSort(values, buffer, middle, right);

    int i = left;
    int j = middle;
    int k = left;
    while (i < middle && j < right) {
        if (values[i] <= values[j]) {
            buffer[k++] = values[i++];
        } else {
            buffer[k++] = values[j++];
        }
    }
    while (i < middle) {
        buffer[k++] = values[i++];
    }
    while (j < right) {
        buffer[k++] = values[j++];
    }
    for (int p = left; p < right; ++p) {
        values[p] = buffer[p];
    }
}

void mergeSort(std::vector<int>& values) {
    std::vector<int> buffer(values.size());
    mergeSort(values, buffer, 0, static_cast<int>(values.size()));
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
    mergeSort(values);
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
