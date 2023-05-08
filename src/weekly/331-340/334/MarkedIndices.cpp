
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



class Solution {
public:
    int maxNumOfMarkedIndices(std::vector<int>& nums) {
        // 
        std::sort(nums.begin(), nums.end(), std::less<int>());

        int tagCount = 0;
        int indexI = 0;
        for (unsigned int index = 1; index < nums.size(); index++) {
            if (nums[index] > nums[indexI] * 2) {
                indexI++;
                tagCount += 2;
            }
        }

        return tagCount;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {3,5,2,4};
    std::vector<int> nums2 = {9,2,5,4};
    std::vector<int> nums3 = {7,6,8};

    std::cout << solution.maxNumOfMarkedIndices(nums1) << std::endl
              << solution.maxNumOfMarkedIndices(nums2) << std::endl
              << solution.maxNumOfMarkedIndices(nums3) << std::endl;
}
