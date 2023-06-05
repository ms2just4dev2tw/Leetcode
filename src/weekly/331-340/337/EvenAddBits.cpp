
#include <iostream>
#include <vector>

/**
 * 2595. 奇偶位数
 * 
 * https://leetcode.cn/contest/weekly-contest-337/
 * https://leetcode.cn/problems/number-of-even-and-odd-bits/
 */
class Solution {
public:
    std::vector<int> evenOddBit(int n) {
        std::vector<int> ret;

        int evenMask = 0b0101010101;
        int oddMask = 0b1010101010;

        ret.push_back(__builtin_popcount(n&evenMask));
        ret.push_back(__builtin_popcount(n&oddMask));

        return ret;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> answer = solution.evenOddBit(17);
    std::cout << answer[0] << "," << answer[1] << std::endl;

    answer = solution.evenOddBit(2);
    std::cout << answer[0] << "," << answer[1] << std::endl;
}
