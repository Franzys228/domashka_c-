#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> groupByName(
    const std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> groups;
    for (const std::string& name : strs) {
        std::string key = name;
        std::sort(key.begin(), key.end());
        groups[key].push_back(name);
    }

    std::vector<std::vector<std::string>> result;
    for (auto& group : groups) {
        std::sort(group.second.begin(), group.second.end());
        result.push_back(group.second);
    }
    return result;
}

int main() {
    int n;
    if (!(std::cin >> n) || n < 0) {
        return 1;
    }
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> names(n);
    for (std::string& name : names) {
        if (!std::getline(std::cin, name)) {
            return 1;
        }
    }

    for (const auto& group : groupByName(names)) {
        std::cout << '[';
        for (std::size_t i = 0; i < group.size(); ++i) {
            if (i > 0) {
                std::cout << ',';
            }
            std::cout << '"' << group[i] << '"';
        }
        std::cout << "]\n";
    }
}
