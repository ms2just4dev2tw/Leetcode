
#include <iostream>
#include <vector>


class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        for (size_t i = 0, j = 0; i<nums1.size() && j<nums2.size();) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                return nums1[i];
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4};
    int ret = solution.getCommon(nums1, nums2);
    std::cout << ret << std::endl;

    nums1 = {1,2,3,6};
    nums2 = {2,3,4,5};
    ret = solution.getCommon(nums1, nums2);
    std::cout << ret << std::endl;
}
