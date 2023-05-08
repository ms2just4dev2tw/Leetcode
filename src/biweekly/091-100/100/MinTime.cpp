
#include <iostream>
#include <vector>


class Solution {
public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        long long score = 0;
        // 当前每个工人维修的车辆数目，起始为0
        std::vector<int> curRepairCar(ranks.size());
        for (int notUse = 0; notUse < cars; notUse++) {
            int nextOneRepair = 0;
            int nextOneRepairExpense = ranks[0] * ((curRepairCar[0]+1)*(curRepairCar[0]+1));
            for (size_t index = 1; index < ranks.size(); index++) {
                int expense = ranks[index] * ((curRepairCar[index]+1)*(curRepairCar[index]+1));
                if (expense < nextOneRepairExpense) {
                    nextOneRepair = index;
                    nextOneRepairExpense = expense;
                }
            }
            curRepairCar[nextOneRepair]++;
            score = nextOneRepairExpense;
        }

        return score;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {4,2,3,1};
    int ret = solution.repairCars(nums, 10);
    std::cout << ret << std::endl;

    nums = {5,1,8};
    ret = solution.repairCars(nums, 6);
    std::cout << ret << std::endl;
}
