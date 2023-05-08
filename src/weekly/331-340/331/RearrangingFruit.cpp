
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
public:
    long long minCost(std::vector<int> &basket1, std::vector<int> &basket2)
    {
        if (basket1.size() == basket2.size())
        {

            std::sort(basket1.begin(), basket1.end(), std::less<int>());
            std::sort(basket2.begin(), basket2.end(), std::less<int>());

            std::vector<int> diffs{};
            for (size_t index = 0; index <= basket1.size(); index++)
            {
                if (basket1[index] != basket2[index])
                {
                    diffs.push_back(basket1[index]);
                    diffs.push_back(basket2[index]);
                }
            }

            if (diffs.size()%4 != 0) {
                return -1;
            }

            // 全集-交集，从小到大排序
            std::sort(diffs.begin(), diffs.end(), std::less<int>());
            // 检测双倍值
            int ret = 0;
            for (size_t index = 0; index < diffs.size(); index += 4) {
                if (diffs[index] != diffs[index+1] || diffs[index+2] != diffs[index+3]) {
                    return -1;
                }
                ret += diffs[index+3] - diffs[index];
            }

            return ret;
        }

        return -1;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> basket1 = {4,2,2,2};
    std::vector<int> basket2 = {1,4,1,2};
    int ret = solution.minCost(basket1, basket2);
    std::cout << ret << std::endl;

    basket1 = {4,2,2,2};
    basket2 = {1,5,1,1};
    ret = solution.minCost(basket1, basket2);
    std::cout << ret << std::endl;
}
