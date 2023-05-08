
#include <iostream>
#include <vector>



class Solution {
public:
    int differenceOfSum(std::vector<int>& nums) {
        int sum = 0;
        for (size_t index = 0; index<nums.size(); index++) {
            int number = nums[index];
            sum += number;
            while (number)
            {
                sum -= number % 10;
                number /= 10;
            }
            
        }
        return sum;
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {1,15,6,3};
    int ret = solution.differenceOfSum(nums);
    std::cout << ret << std::endl;

    nums = {1,2,3,4};
    ret = solution.differenceOfSum(nums);
    std::cout << ret << std::endl;
}
