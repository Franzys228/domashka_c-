#include <iostream>
#include <string>
#include <vector>

namespace seminar10 {

char* strcat(char* dest, const char* src) {
    char* end = dest;
    while (*end != '\0') {
        ++end;
    }
    while (*src != '\0') {
        *end++ = *src++;
    }
    *end = '\0';
    return dest;
}

}

int main() {
    std::string first, second;
    if (!std::getline(std::cin, first) || !std::getline(std::cin, second)) {
        return 1;
    }
    std::vector<char> result(first.size() + second.size() + 1);
    for (std::size_t i = 0; i < first.size(); ++i) {
        result[i] = first[i];
    }
    result[first.size()] = '\0';
    seminar10::strcat(result.data(), second.c_str());
    std::cout << result.data() << '\n';
}
