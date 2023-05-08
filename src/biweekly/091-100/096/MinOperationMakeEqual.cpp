
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        long long sum1 = 0, sum2 = 0;
        long long count1 = 0, count2 = 0;
        for (size_t i = 0, j = 0; i<nums1.size() || j<nums2.size();) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j++];
            } else {
                sum1 += nums1[i++];
                sum2 += nums2[j++];
            }
        }

        return sum1 == sum2 ? count1/2 : -1;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {4,3,1,4};
    std::vector<int> nums2 = {1,3,7,1};
    int ret = solution.minOperations(nums1, nums2, 3);
    std::cout << ret << std::endl;

    nums1 = {3,8,5,2};
    nums2 = {2,4,1,6};
    ret = solution.minOperations(nums1, nums2, 1);
    std::cout << ret << std::endl;
}
