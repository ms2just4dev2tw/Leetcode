
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 
 * [1,1,1, 2,2,2, 3,3,3,3,3,3, 4,4, 5,5,5,5,5,5, 6,6,6, 7,7,7] 2
 * 反例: 两个次大之和 > 最大和伪次大
 */
class Solution {
public:
    int maximizeWin(std::vector<int>& prizePositions, int k) {
        int ret = 0;

        return ret;
    }

    int maximizeWin2(std::vector<int> &prizePositions, int k) {
        int ans = 0, left = 0, n = prizePositions.size(), pre[n + 1];
        pre[0] = 0;
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                ++left;
            }
            ans = std::max(ans, right - left + 1 + pre[left]);
            pre[right + 1] = std::max(pre[right], right - left + 1);
        }
        return ans;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,1,2,2,3,3,5};
    int ret = solution.maximizeWin2(nums, 2);
    std::cout << ret << std::endl;

    nums = {1,2,3,4};
    ret = solution.maximizeWin2(nums, 0);
    std::cout << ret << std::endl;

    nums = {1,1,1, 2,2,2, 3,3,3,3,3,3, 4,4, 5,5,5,5,5,5, 6,6,6, 7,7,7};
    ret = solution.maximizeWin2(nums, 2);
    std::cout << ret << std::endl;
}
