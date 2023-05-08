
#include <iostream>


class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int count = 0;
        for (int length = low; length <= high; length++) {

        }

        return count;
    }
};

int main(void)
{
    Solution solution;

    int ret = solution.countGoodStrings(3,3,1,1);
    std::cout << ret << std::endl;

    ret = solution.countGoodStrings(2,3,1,2);
    std::cout << ret << std::endl;
}
