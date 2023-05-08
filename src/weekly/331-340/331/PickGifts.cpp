
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

class Solution
{
public:
    long long pickGifts(std::vector<int> &gifts, int k)
    {
        // 优先队列默认模板作为最大堆
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++)
        {
            int curMax = pq.top();
            pq.pop(); // delete
            pq.push(std::sqrt(curMax));
        }
        int sum = 0;
        while (pq.size())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums1 = {25, 64, 9, 4, 100};
    int count = solution.pickGifts(nums1, 4);
    std::cout << count << std::endl;
}
