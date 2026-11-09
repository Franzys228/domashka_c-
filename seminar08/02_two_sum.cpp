#include "01_hash_table.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main(int argc, char** argv) {
    std::string mode = argc > 1 ? argv[1] : "custom";
    if (argc > 2 || (mode != "custom" && mode != "set" && mode != "map")) {
        return 1;
    }

    long long target;
    if (!(std::cin >> target)) {
        return 1;
    }

    IntHashSet custom;
    std::unordered_set<int> values;
    std::unordered_map<int, int> indices;
    int value;
    int position = 0;
    bool found = false;
    int first = 0;
    int second = 0;
    int firstIndex = -1;
    int secondIndex = -1;

    while (std::cin >> value) {
        long long lower =
            static_cast<long long>(std::numeric_limits<int>::min()) + value;
        long long upper =
            static_cast<long long>(std::numeric_limits<int>::max()) + value;
        if (target >= lower && target <= upper) {
            int other = static_cast<int>(target - value);
            if (mode == "custom" && custom.contains(other)) {
                first = other;
                second = value;
                found = true;
            } else if (mode == "set" && values.find(other) != values.end()) {
                first = other;
                second = value;
                found = true;
            } else if (mode == "map") {
                auto it = indices.find(other);
                if (it != indices.end()) {
                    first = other;
                    second = value;
                    firstIndex = it->second;
                    secondIndex = position;
                    found = true;
                }
            }
        }
        if (found) {
            break;
        }
        if (mode == "custom") {
            custom.insert(value);
        } else if (mode == "set") {
            values.insert(value);
        } else {
            indices.emplace(value, position);
        }
        ++position;
    }

    if (!found) {
        std::cout << "not found\n";
    } else if (mode == "map") {
        std::cout << first << ' ' << second << " indices "
                  << firstIndex << ' ' << secondIndex << '\n';
    } else {
        std::cout << first << ' ' << second << '\n';
    }
}
