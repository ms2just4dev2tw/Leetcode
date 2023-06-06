
#include <iostream>
#include <vector>
#include <unordered_map>


/**
 * 2610. 转换二维数组
 *
 * https://leetcode.cn/contest/weekly-contest-339/
 * https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/
 */
class Solution
{
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> &nums)
    {
        std::unordered_map<int, int> countMap = {};
        for (auto num : nums)
        {
            countMap[num]++;
        }

        bool stopFlag = false;
        int itIndex = 0;
        std::vector<std::vector<int>> array2d;
        while (!stopFlag)
        {
            stopFlag = true;
            array2d.push_back(std::vector<int>{});
            // 加上引用或指针
            for (auto &it : countMap)
            {
                if (it.second > 0)
                {
                    array2d[itIndex].push_back(it.first);
                    stopFlag = false;
                    it.second--;
                }
            }

            itIndex++;
        }

        return array2d;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = std::vector<int>{1, 3, 4, 1, 2, 3, 1};
    std::vector<std::vector<int>> array2d = solution.findMatrix(nums);
    for (auto row : array2d)
    {
        for (auto num : row)
        {
            std::cout << num;
        }
        std::cout << std::endl;
    }

    nums = std::vector<int>{1, 2, 3, 4};
    nums = std::vector<int>{1, 2, 3, 4};
    array2d = solution.findMatrix(nums);
    for (auto row : array2d)
    {
        for (auto num : row)
        {
            std::cout << num;
        }
        std::cout << std::endl;
    }
}