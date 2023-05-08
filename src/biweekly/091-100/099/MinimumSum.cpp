
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

/**
 * 2578. 最小和分割
 * 
 * https://leetcode.cn/contest/biweekly-contest-99/
 * https://leetcode.cn/problems/split-with-minimum-sum/
 */
class Solution {
public:
    int splitNum(int num) {
        std::string str = std::to_string(num);
        std::sort(str.begin(), str.end(), std::less<char>());

        int ret[2]{};
        for (int i = 0; i < (int)str.length(); i++) {
            ret[i%2] = ret[i%2] * 10 + (str[i] - '0');
        }

        return ret[0] + ret[1];
    }
};

int main(void)
{
    Solution solution;
    std::cout << solution.splitNum(4325) << std::endl
              << solution.splitNum(687) << std::endl;
}