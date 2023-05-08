
#include <iostream>
#include <vector>
#include <cstdlib>



class Solution {
public:
    std::vector<int> leftRigthDifference(std::vector<int>& nums) {
        unsigned int length = nums.size();
        std::vector<int> leftSums(length);
        for (unsigned int index = 0; index < length-1; index++) {
            leftSums[index+1] = nums[index] + leftSums[index];
        }

        int sum = leftSums[length-1] + nums[length-1];
        
        std::vector<int> diffs(length);
        for (unsigned int index = 0; index < length; index++) {
            diffs[index] = std::abs((sum - nums[index] - leftSums[index]) - leftSums[index]);
        }

        return diffs;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {10,4,8,3};
    std::vector<int> diffs = solution.leftRigthDifference(nums);
    for (size_t index = 0; index < diffs.size(); index++) {
        std::cout << diffs[index] << ',';
    }
    std::cout << std::endl;
}
