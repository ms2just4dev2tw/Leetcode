
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq(nums.begin(), nums.end());
        int score = 0;
        for (int times = 1; times <= k; times++) {
            int top = pq.top();
            score += top;
            pq.pop();
            pq.push(std::ceil((float)top/3));
        }
        return score;
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {10,10,10,10,10};
    int ret = solution.maxKelements(nums,5);
    std::cout << ret << std::endl;

    nums = {1,10,3,3,3};
    ret = solution.maxKelements(nums,3);
    std::cout << ret << std::endl;
}
