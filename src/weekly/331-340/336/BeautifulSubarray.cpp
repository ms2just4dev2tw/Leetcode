
#include <iostream>
#include <vector>

/**
 * 2588. 统计美丽子数组数目
 * 
 * https://leetcode.cn/contest/weekly-contest-336/
 * https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/
 */
class Solution {
public:
    long long beautifulSubarrays(std::vector<int>& nums) {
        long long beautifulSubarrayCount = 0;
        for (int subLength = 2; subLength <= ((int)nums.size()); subLength++) {
            for (int startIndex = 0; startIndex <= ((int)nums.size()-subLength); startIndex++) {
                if (isBeautifulSubarray(nums, startIndex, startIndex+subLength)) {
                    beautifulSubarrayCount++;
                }
            }
        }
        return beautifulSubarrayCount;
    }

    bool isBeautifulSubarray(std::vector<int>& nums, int start, int end) {
        int ret = 0;
        for (int index = start; index < end; index++) {
            ret ^= nums[index];
        }
        return ret == 0;
    }
};

int main(void)
{
    Solution solution;

    int arr[5] = {4,3,1,2,4};
    std::vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));

    std::cout << solution.beautifulSubarrays(nums) << std::endl;
}
