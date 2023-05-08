
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    long long findScore(std::vector<int>& nums) {
        long long score = 0;
        for (size_t index = 0; index < nums.size();)
        {
            int local = std::min_element(nums.begin(), nums.end()) - nums.begin();
            if (nums[local] == 1e6 + 1) {
                break;
            } else {
                score += nums[local];
                nums[local] = 1e6 + 1;
                if (local-1 > -1) {
                    nums[local-1] = 1e6 + 1;
                }
                if (local+1 < (int)nums.size()) {
                    nums[local+1] = 1e6 + 1;
                }
            }
        }
        return score;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {2,1,3,4,5,2};
    int ret = solution.findScore(nums);
    std::cout << ret << std::endl;

    nums = {2,3,5,1,3,2};
    ret = solution.findScore(nums);
    std::cout << ret << std::endl;
}
