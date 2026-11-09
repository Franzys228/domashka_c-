#include "01_hash_table.hpp"

#include <iostream>

int main() {
    IntHashSet table;
    char operation;
    int value;
    while (std::cin >> operation) {
        if (operation == 'p') {
            table.print();
            continue;
        }
        if (operation == 'c') {
            table.clear();
            continue;
        }
        if (!(std::cin >> value)) {
            return 1;
        }
        if (operation == 'a') {
            table.insert(value);
        } else if (operation == 'd') {
            table.erase(value);
        } else if (operation == 's') {
            std::cout << (table.contains(value) ? "true" : "false") << '\n';
        } else {
            return 1;
        }
    }
    table.print();
}
