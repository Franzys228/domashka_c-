#include <iostream>
#include <string>

namespace seminar10 {

int strcmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    unsigned char left = static_cast<unsigned char>(*s1);
    unsigned char right = static_cast<unsigned char>(*s2);
    if (left < right) {
        return -1;
    }
    if (left > right) {
        return 1;
    }
    return 0;
}

}

int main() {
    std::string first, second;
    if (!std::getline(std::cin, first) || !std::getline(std::cin, second)) {
        return 1;
    }
    std::cout << seminar10::strcmp(first.c_str(), second.c_str()) << '\n';
}
