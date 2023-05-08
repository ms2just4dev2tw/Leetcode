
#include <iostream>
#include <string>


class Solution {
public:
    int minMaxDifference(int num) {
        std::string str = std::to_string(num);
        char maxRepateChar = '0';
        for (size_t index = 0; index < str.size(); index++) {
            if (str[index] != '9') {
                maxRepateChar = str[index];
                break;
            }
        }
        // 
        std::string maxStr = str;
        for (size_t index = 0; index < maxStr.size(); index++) {
            if (maxStr[index] == maxRepateChar) {
                maxStr[index] = '9';
            }
        }

        char minRepateChar = str[0];
        std::string minStr = str;
        for (size_t index = 0; index < minStr.size(); index++) {
            if (minStr[index] == minRepateChar) {
                minStr[index] = '0';
            }
        }

        return std::stoi(maxStr) - std::stoi(minStr);
    }
};

int main(void)
{
    Solution solution;

    int ret = solution.minMaxDifference(11891);
    std::cout << ret << std::endl;

    ret = solution.minMaxDifference(90);
    std::cout << ret << std::endl;
}