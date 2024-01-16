#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    static std::unordered_map<int, std::vector<std::string>> map;

    static void initializeMap() {
        map[2] = {"a", "b", "c"};
        map[3] = {"d", "e", "f"};
        map[4] = {"g", "h", "i"};
        map[5] = {"j", "k", "l"};
        map[6] = {"m", "n", "o"};
        map[7] = {"p", "q", "r", "s"};
        map[8] = {"t", "u", "v"};
        map[9] = {"w", "x", "y", "z"};
    }

    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) {
            return std::vector<std::string>();
        }

        std::vector<std::string> res;
        solution(res, "", digits, 0);
        return res;
    }

private:
    void solution(std::vector<std::string>& res, std::string tempString, const std::string& digits, int i) {
        if (tempString.length() == digits.length()) {
            res.push_back(tempString);
        }

        if (i > digits.length() - 1) {
            return;
        }

        std::vector<std::string>& digitChars = map[digits[i] - '0'];

        for (const std::string& s : digitChars) {
            solution(res, tempString + s, digits, i + 1);
        }
    }
};

std::unordered_map<int, std::vector<std::string>> Solution::map;

int main() {
    // Initialize the static map before using the Solution class.
    Solution::initializeMap();

    Solution solution;
    std::string digits = "23";
    std::vector<std::string> combinations = solution.letterCombinations(digits);

    for (const std::string& combination : combinations) {
        std::cout << combination << std::endl;
    }

    return 0;
}