#include <iostream>

bool isDecimalPalindrome(int value) {
    int original = value;
    int reversed = 0;
    while (value > 0) {
        reversed = reversed * 10 + value % 10;
        value /= 10;
    }
    return original == reversed;
}

bool isBinaryPalindrome(int value) {
    int left = 31;
    while (left > 0 && ((value >> left) & 1) == 0) {
        --left;
    }
    int right = 0;
    while (left > right) {
        if (((value >> left) & 1) != ((value >> right) & 1)) {
            return false;
        }
        --left;
        ++right;
    }
    return true;
}

int main() {
    const int value = 585;
    if (!isDecimalPalindrome(value) || !isBinaryPalindrome(value)) {
        return 1;
    }
    std::cout << value << '\n';
}
