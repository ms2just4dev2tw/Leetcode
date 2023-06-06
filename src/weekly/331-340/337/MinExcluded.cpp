
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 2598. 执行操作后的最大 MEX
 * 
 * https://leetcode.cn/contest/weekly-contest-337/
 * https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/
 */
class Solution
{
public:
    int findSmallestInteger(std::vector<int> &nums, int value)
    {
        std::vector<int> valueCount;
        for (int i = 0; i < value; i++)
        {
            valueCount.push_back(0);
        }

        for (size_t index = 0; index < nums.size(); index++)
        {
            int num = nums[index];
            // 负数变为正数   正数局限于 value 的模
            if (num < 0)
                valueCount[(num % value + value) % value] += 1;
            else
                valueCount[num % value] += 1;
        }

        // 找出 0 值缺失
        for (int i = 0; i < value; i++)
        {
            if (valueCount[i] == 0)
            {
                return i;
            }
        }

        // 递增到 nums 的长度为止
        for (int increase = 0; increase < (int)nums.size() - value; increase++)
        {
            if (valueCount[increase%value] <= 1)
            {
                return value + increase;
            }
            valueCount[increase%value]--;
        }

        return (int)nums.size();
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = std::vector<int>{1, -10, 7, 13, 6, 8};
    std::cout << solution.findSmallestInteger(nums, 5) << std::endl;

    nums = std::vector<int>{1,-10,7,13,6,8};
    std::cout << solution.findSmallestInteger(nums, 7) << std::endl;

    nums = std::vector<int>{1,2,7,3,5,4,6};
    std::cout << solution.findSmallestInteger(nums, 5) << std::endl;

    nums = std::vector<int>{1,2,7,3,5,4,6,0,8,9,14};
    std::cout << solution.findSmallestInteger(nums, 5) << std::endl;
}
