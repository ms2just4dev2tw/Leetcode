
#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        int len = (int)skill.size();

        std::sort(skill.begin(), skill.end());
        int ret = skill[0] * skill[len-1];
        int skillSum = skill[0] + skill[len-1];
        for (int offset = 1, end = len/2; offset < end; offset++) {
            int sum = skill[offset] + skill[len-offset-1];
            if (skillSum != sum) {
                return -1;
            }
            ret += skill[offset] * skill[len-offset-1];
        }

        return ret;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> skill = {3,2,5,1,3,4};
    long long ret = solution.dividePlayers(skill);
    std::cout << ret << std::endl;

    skill = {3,4};
    ret = solution.dividePlayers(skill);
    std::cout << ret << std::endl;

    skill = {1,1,2,3};
    ret = solution.dividePlayers(skill);
    std::cout << ret << std::endl;
}
