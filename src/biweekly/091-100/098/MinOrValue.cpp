
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
public:
    int minImpossibleOR(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int exp = 1;
        for (size_t index = 0; index < nums.size(); index++)
        {
            if (exp == nums[index])
            {
                exp = exp << 1;
            }
            else if (exp < nums[index])
            {
                return exp;
            }
        }
        return exp;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {2, 1};
    int ret = solution.minImpossibleOR(nums);
    std::cout << ret << std::endl;

    nums = {5, 3, 2};
    ret = solution.minImpossibleOR(nums);
    std::cout << ret << std::endl;
}
