#include <cstddef>
#include <iostream>

struct DynamicArray {
    int* data;
    std::size_t size;
    std::size_t capacity;
};

DynamicArray create_array() {
    return {nullptr, 0, 0};
}

void push_back(DynamicArray& array, int value) {
    if (array.size == array.capacity) {
        std::size_t newCapacity = array.capacity == 0 ? 1 : array.capacity * 2;
        int* data = new int[newCapacity];
        for (std::size_t i = 0; i < array.size; ++i) {
            data[i] = array.data[i];
        }
        data[array.size] = value;
        delete[] array.data;
        array.data = data;
        array.capacity = newCapacity;
    } else {
        array.data[array.size] = value;
    }
    ++array.size;
}

bool pop_back(DynamicArray& array) {
    if (array.size == 0) {
        return false;
    }
    --array.size;
    return true;
}

void erase(DynamicArray& array) {
    delete[] array.data;
    array.data = nullptr;
    array.size = 0;
    array.capacity = 0;
}

int main() {
    int n;
    if (!(std::cin >> n) || n < 0) {
        return 1;
    }
    DynamicArray array = create_array();
    for (int i = 0; i < n; ++i) {
        int value;
        if (!(std::cin >> value)) {
            erase(array);
            return 1;
        }
        push_back(array, value);
    }

    for (std::size_t i = 0; i < array.size; ++i) {
        std::cout << array.data[i] << ' ';
    }
    std::cout << '\n';
    pop_back(array);
    std::cout << array.size << ' ' << array.capacity << '\n';
    erase(array);
}
