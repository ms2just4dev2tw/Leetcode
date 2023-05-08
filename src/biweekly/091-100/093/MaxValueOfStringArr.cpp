
#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) {
        int max = -1;
        for (auto& str : strs) {
            bool includeChar = false;
            for (auto ch : str) {
                if (!std::isdigit(ch)) {
                    includeChar = true;
                    break;
                }
            }
            int value = includeChar ? (int)str.size() : std::stoi(str);
            max = value > max ? value : max;
        }
        return max;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::string> strs = {"alic3","bob","3","4","00000"};
    int ret = solution.maximumValue(strs);
    std::cout << ret << std::endl;

    strs = {"1","01","001","0001"};
    ret = solution.maximumValue(strs);
    std::cout << ret << std::endl;
}