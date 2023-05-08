
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
public:
    long long countFairPairs(std::vector<int> &nums, int lower, int upper)
    {
        long long count = 0;
        std::sort(nums.begin(), nums.end(), std::less<int>());
        for (size_t gap = 1; gap < nums.size(); gap++)
        {
            for (size_t start = 0, end = start + gap; end < nums.size(); start++, end++)
            {
                int sum = nums[start] + nums[end];

                if (sum >= lower && sum <= upper)
                {
                    count++;
                }
                else if (sum > upper)
                {
                    break;
                }
            }
        }
        return count;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {0,1,7,4,4,5};
    int count = solution.countFairPairs(nums1,3,6);
    std::cout << count << std::endl;

    std::vector<int> nums2 = {1,7,9,2,5};
    count = solution.countFairPairs(nums2,11,11);
    std::cout << count << std::endl;
}
