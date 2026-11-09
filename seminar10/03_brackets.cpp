#include <iostream>
#include <string>

bool isCorrect(const std::string& line) {
    std::string stack;
    for (char ch : line) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push_back(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) {
                return false;
            }
            char open = stack.back();
            stack.pop_back();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        return 1;
    }
    std::cout << (isCorrect(line) ? "true" : "false") << '\n';
}
