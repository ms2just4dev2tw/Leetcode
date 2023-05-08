
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/**
 * 
 * 
 * 滑动窗口-2求最小值
 */
class Solution {
public:
    int minimizeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        // n-2
        size_t length = nums.size();
        int ret1 = nums[length-1] - nums[2];
        int ret2 = nums[length-2] - nums[1];
        int ret3 = nums[length-3] - nums[0];

        return std::min({ret1,ret2,ret3});
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,4,3};
    int ret = solution.minimizeSum(nums);
    std::cout << ret << std::endl;

    nums = {1,4,7,8,5};
    ret = solution.minimizeSum(nums);
    std::cout << ret << std::endl;
}
