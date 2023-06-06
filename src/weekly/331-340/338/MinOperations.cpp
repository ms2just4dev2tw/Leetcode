
#include <iostream>
#include <vector>
#include <cmath>


/**
 * 2600. K 件物品的最大和
 *
 * https://leetcode.cn/contest/weekly-contest-338/
 * https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/
 */
class Solution {
public:
    std::vector<long long> minOperations(std::vector<int>& nums, std::vector<int>& queries) {
        std::vector<long long> answer;

        for (auto query : queries) {
            long long op = 0;
            for (auto num : nums) {
                op += std::abs(num - query);
            }
            answer.push_back(op);
        }

        return answer;
    }
};



int main(void)
{
    Solution solution;

    std::vector<int> nums = std::vector<int>{3,1,6,8};
    std::vector<int> queries = std::vector<int>{1,5};

    std::vector<long long> answer = solution.minOperations(nums, queries);
    for (auto op : answer) {
        std::cout << op << std::endl;
    }
    

    nums = std::vector<int>{2,9,6,3};
    queries = std::vector<int>{10};
    
    answer = solution.minOperations(nums, queries);
    for (auto op : answer) {
        std::cout << op << std::endl;
    }
}
