
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


/**
 * 2611. 老鼠和奶酪
 *
 * https://leetcode.cn/contest/weekly-contest-339/
 * https://leetcode.cn/problems/mice-and-cheese/
 */
class Solution {
public:
    int miceAndCheese(std::vector<int>& reward1, std::vector<int>& reward2, int k) {
        // 优先队列，元素 pair，greater cmp
        auto cmp = [](std::pair<int,int> left, std::pair<int,int> right) { 
            return left.first - left.second < right.first - right.second; 
        };
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(cmp)> pq(cmp);

        for (size_t i = 0; i < reward1.size(); i++) {
            pq.push(std::pair<int,int>{reward1[i], reward2[i]});
        }

        int maxValue = 0;
        // 从 diffArr 选出最小 k 个 diff
        for (int times = 0; times < k; times++) {
            std::pair<int,int> top = pq.top();
            maxValue += top.first;
            pq.pop();
        }

        // 取剩余的值
        while (!pq.empty()) {
            std::pair<int,int> top = pq.top();
            maxValue += top.second;
            pq.pop();
        }

        return maxValue;
    }
};


int main(void) {
    Solution solution;

    std::vector<int> reward1 = std::vector<int>{1,1,3,4};
    std::vector<int> reward2 = std::vector<int>{4,4,1,1};
    std::cout << solution.miceAndCheese(reward1, reward2, 2) << std::endl;

    reward1 = std::vector<int>{1,1};
    reward2 = std::vector<int>{1,1};
    std::cout << solution.miceAndCheese(reward1, reward2, 2) << std::endl;
}