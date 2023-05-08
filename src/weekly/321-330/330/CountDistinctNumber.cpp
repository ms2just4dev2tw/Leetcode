
#include <iostream>


class Solution {
public:
    int distinctIntegers(int n) {
        return n-1;
    }
};


int main(void)
{
    Solution solution;

    int ret = solution.distinctIntegers(5);
    std::cout << ret << std::endl;

    ret = solution.distinctIntegers(3);
    std::cout << ret << std::endl;
}