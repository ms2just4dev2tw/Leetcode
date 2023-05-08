
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::sort(banned.begin(), banned.end());
        std::vector<int> filterNums{};
        std::vector<int>::iterator it = banned.begin();
        for (int num = 1; num <= n; num++) {
            if (it != banned.end() && num == *it) {
                it++;
            } else {
                filterNums.push_back(num);
            }
        }

        int sum = 0, count = 0;
        for (size_t index = 0; index < filterNums.size(); index++) {
            sum += filterNums[index];
            if(sum <= maxSum) {
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,6,5};
    int ret = solution.maxCount(nums, 5, 6);
    std::cout << ret << std::endl;

    nums = {1,2,3,4,5,6,7};
    ret = solution.maxCount(nums, 8, 1);
    std::cout << ret << std::endl;

    nums = {11};
    ret = solution.maxCount(nums, 7, 50);
    std::cout << ret << std::endl;
}