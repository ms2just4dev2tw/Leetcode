
#include <iostream>
#include <vector>


/**
 * 2601. 质数减法运算
 *
 * https://leetcode.cn/contest/weekly-contest-338/
 * https://leetcode.cn/problems/prime-subtraction-operation/
 */
class Solution {
public:
    bool primeSubOperation(std::vector<int>& nums) {
        nums[0] = findMaxPrime(nums[0]);
        for (size_t pre = 0, i = 1; i < nums.size(); pre++, i++) {
            int num = findMaxPrime(nums[i] - nums[pre] - 1);
            if (num < 0)
                return false;
            else 
                nums[i] = num;
        }
        return true;
    }

    int findMaxPrime(int limit) {

    }
};



int main(void)
{
    Solution solution;

    std::vector<int> nums = std::vector<int>{6,8,11,12};
    std::cout << solution.primeSubOperation(nums) << std::endl;

    nums = std::vector<int>{5,8,3};
    std::cout << solution.primeSubOperation(nums) << std::endl;
}
