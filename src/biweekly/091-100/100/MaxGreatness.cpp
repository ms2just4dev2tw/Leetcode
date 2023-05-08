
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maximizeGreatness(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int count = 1;
        int min = nums[0];
        for (size_t index = 1; index < nums.size(); index++) {
            if (min == nums[index]) {
                count++;
            }
        }

        return nums.size() - count;
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,3,5,2,1,3,1};
    int ret = solution.maximizeGreatness(nums);
    std::cout << ret << std::endl;

    nums = {1,2,3,4};
    ret = solution.maximizeGreatness(nums);
    std::cout << ret << std::endl;
}