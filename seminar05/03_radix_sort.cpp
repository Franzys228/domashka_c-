#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

void radixSort(std::vector<int>& values) {
    std::vector<int> buffer(values.size());
    for (int pass = 0; pass < 4; ++pass) {
        std::array<std::size_t, 256> count{};
        int shift = pass * 8;
        for (int value : values) {
            std::uint32_t key =
                static_cast<std::uint32_t>(value) ^ 0x80000000u;
            ++count[(key >> shift) & 255u];
        }
        std::size_t sum = 0;
        for (std::size_t& item : count) {
            std::size_t current = item;
            item = sum;
            sum += current;
        }
        for (int value : values) {
            std::uint32_t key =
                static_cast<std::uint32_t>(value) ^ 0x80000000u;
            buffer[count[(key >> shift) & 255u]++] = value;
        }
        values.swap(buffer);
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
    radixSort(values);
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
