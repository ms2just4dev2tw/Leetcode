
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    long long countGood(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> cnt;
        long ans = 0;
        int left = 0, pairs = 0;
        for (int x : nums) {
            pairs += cnt[x]++; // 移入右端点
            ans += left;
            while (pairs >= k) {
                pairs -= --cnt[nums[left++]]; // 移出左端点
                ++ans;
            }
        }
        return ans;
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,1,1,1,1};
    int ret = solution.countGood(nums,10);
    std::cout << ret << std::endl;

    nums = {3,1,4,3,2,2,4};
    ret = solution.countGood(nums,2);
    std::cout << ret << std::endl;
}

