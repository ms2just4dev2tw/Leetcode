
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumTastiness(std::vector<int> &price, int k)
    {
        int n = price.size();
        std::sort(price.begin(), price.end());

        // 检查二分的答案 LIM 是否合法
        auto check = [&](int LIM)
        {
            // 记录一共取出几个数
            int cnt = 1;
            // j 指向上一次取得数，i 指向当前考虑的数
            for (int i = 1, j = 0; i < n; i++)
            {
                // price[i] 是大于等于 price[j] + LIM 的最小值，取出
                if (price[i] - price[j] >= LIM)
                    cnt++, j = i;
            }
            return cnt >= k;
        };

        int minDiff = 0, maxDiff = (price[n-1]-price[0])/(k-1);

        // 二分答案
        int left = minDiff, right = maxDiff;
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {13,5,1,8,21,2};
    int ret = solution.maximumTastiness(nums,3);
    std::cout << ret << std::endl;

    nums = {1,3,1};
    ret = solution.maximumTastiness(nums,2);
    std::cout << ret << std::endl;

    nums = {7,7,7,7};
    ret = solution.maximumTastiness(nums,2);
    std::cout << ret << std::endl;
}