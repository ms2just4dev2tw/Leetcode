
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
    int minCost(std::vector<int> &nums, int k)
    {
        std::map<int, int> timesMap{};
        for (const auto &num : nums)
        {
            ++timesMap[num];
        }

        int maxTimes = 0;
        for (const auto &pair : timesMap)
        {
            maxTimes = pair.second > maxTimes ? pair.second : maxTimes;
        }

        std::vector<int> retArr{};
        for (int times = 1; times < maxTimes; times++)
        {
            int cost = k * times;
            for (const auto &pair : timesMap)
            {
                if (pair.second > times)
                {
                    cost += pair.first * (pair.second - times + 1);
                }
            }
            retArr.push_back(cost);
        }

        return *std::min_element(retArr.begin(), retArr.end());
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {1, 2, 1, 2, 1, 3, 3};
    int ret = solution.minCost(nums, 2);
    std::cout << ret << std::endl;

    nums = {1, 2, 1, 2, 1};
    ret = solution.minCost(nums, 2);
    std::cout << ret << std::endl;

    nums = {1, 2, 1, 2, 1};
    ret = solution.minCost(nums, 5);
    std::cout << ret << std::endl;
}
