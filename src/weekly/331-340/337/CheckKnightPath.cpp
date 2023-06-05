
#include <iostream>
#include <vector>
#include <array>
#include <cmath>


/**
 * 2596. 检查骑士巡视方案
 * 
 * https://leetcode.cn/contest/weekly-contest-337/
 * https://leetcode.cn/problems/check-knight-tour-configuration/
 */
class Solution {
public:
    bool checkValidGrid(std::vector<std::vector<int>>& grid) {
        std::vector<std::array<int,2>> seqLocationMap;

        // init
        size_t n = grid.size();
        for (size_t i = 0; i < n*n; i++) {
            seqLocationMap.push_back(std::array<int,2>{0,0});
        }

        for (size_t i = 0; i < n; i++) {
            std::vector<int> row = grid[i];
            for (size_t j = 0; j < row.size(); j++) {
                // 给每一步设置 location(x,y)
                seqLocationMap[row[j]][0] = (int)i;
                seqLocationMap[row[j]][1] = (int)j;
            }
        }

        //
        for (size_t step = 0, nextStep = 1; nextStep < seqLocationMap.size(); step++, nextStep++) {
            int step_x = seqLocationMap[step][0];
            int step_y = seqLocationMap[step][1];
            int next_step_x = seqLocationMap[nextStep][0];
            int next_step_y = seqLocationMap[nextStep][1];

            int distance = std::abs(next_step_x - step_x) + std::abs(next_step_y - step_y);
            // 本应该为 4, 少个对角位
            if (distance != 3) {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::vector<int>> grid = std::vector<std::vector<int>>{
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };
    std::cout << std::boolalpha << solution.checkValidGrid(grid) << std::endl;

    grid = std::vector<std::vector<int>>{
        {0,3,6},
        {5,8,1},
        {2,7,4}
    };
    std::cout << std::boolalpha << solution.checkValidGrid(grid) << std::endl;
}

