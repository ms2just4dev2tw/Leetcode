
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    int distinctAverages(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::unordered_set<float> averageSet = {};
        for (size_t left=0, right=nums.size()-1; left < nums.size()/2; left++, right--) {
            float average = (nums[left]+nums[right]) / 2;
            averageSet.insert(average);
        }

        return (int)averageSet.size();
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {4,1,4,0,3,5};
    int ret = solution.distinctAverages(nums);
    std::cout << ret << std::endl;

    nums = {1,100};
    ret = solution.distinctAverages(nums);
    std::cout << ret << std::endl;
}
