
#include <iostream>
#include <string>


/**
 * 2609. 最长平衡子字符串
 *
 * https://leetcode.cn/contest/weekly-contest-339/
 * https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/
 */
class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int ret = 0;

        int zeroCount = 0, oneCount = 0;
        for (char ch : s) {
            // 
            if (zeroCount == 0) {
                if (ch == '0') {
                    zeroCount++;
                }
            } else {
                if (ch == '1') {
                    oneCount++;
                    int count = zeroCount>oneCount ? oneCount : zeroCount;
                    ret = count*2>ret ? count*2 : ret;
                } else if (oneCount == 0) {
                    zeroCount++;
                } else {
                    zeroCount = 1;
                    oneCount = 0;
                }
            }
        }

        return ret;
    }
};


int main(void)
{
    Solution solution;

    std::cout << solution.findTheLongestBalancedSubstring("01000111") << std::endl;
    std::cout << solution.findTheLongestBalancedSubstring("00111") << std::endl;
    std::cout << solution.findTheLongestBalancedSubstring("111") << std::endl;
    std::cout << solution.findTheLongestBalancedSubstring("111000") << std::endl;
}