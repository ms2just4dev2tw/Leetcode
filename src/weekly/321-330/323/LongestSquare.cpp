
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> lastArr = {nums[0]};
        std::vector<int> countArr = {1};

        for (size_t i = 1; i < nums.size(); i++) {
            int num = nums[i];
            int flagIndex = -1;
            for (size_t j = 0; j < lastArr.size(); j++) {
                int last = lastArr[j];
                if(last*last == num) {
                    flagIndex = j;
                    break;
                }
            }
            if (flagIndex >= 0) {
                lastArr[flagIndex] = num;
                countArr[flagIndex]++;
            } else {
                lastArr.push_back(num);
                countArr.push_back(1);
            }
        }

        int ret = -1;
        for (auto& count : countArr) {
            if (count > 1 && count > ret) {
                ret = count;
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution solution;

    std::vector nums = {4,3,6,16,8,2};
    int ret = solution.longestSquareStreak(nums);
    std::cout << ret << std::endl;

    nums = {2,3,5,6,7};
    ret = solution.longestSquareStreak(nums);
    std::cout << ret << std::endl;
}
