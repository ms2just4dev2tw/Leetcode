

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    long long findTheArrayConcVal(std::vector<int>& nums) {
        long long ret = 0;
        for (size_t start = 0, end = nums.size()-1;start<=end;start++,end--) {
            if (start < end) {
                std::string conc = std::to_string(nums[start]) + std::to_string(nums[end]);
                ret += std::stoi(conc);
            } else {
                ret += nums[start];
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {7,52,2,4};
    int ret = solution.findTheArrayConcVal(nums1);
    std::cout << ret << std::endl;

    std::vector<int> nums2 = {5,14,13,8,12};
    ret = solution.findTheArrayConcVal(nums2);
    std::cout << ret << std::endl;
}
