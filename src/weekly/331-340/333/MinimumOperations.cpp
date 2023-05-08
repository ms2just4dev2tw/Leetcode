
#include <iostream>

class Solution
{
public:
    int minOperations(int n)
    {
        int optCount = 1;
        while (n & (n - 1)) // n 不是 2 的幂次
        {
            // n 最低为 1 的比特位
            int lowbit = n & -n;
            // 如果有多个连续的 1 比特位
            if (n & (lowbit << 1))
                n += lowbit;
            else
                n -= lowbit;
            optCount++;
        }
        return optCount;
    }

    int minOperationsOpt(int n)
    {
        // int count = 0;
        // while (n)
        // {
        //     count++;
        //     n = n & (n-1);
        // }
        return __builtin_popcount(3 * n ^ n);
    }
};

int main(void)
{
    Solution solution;

    int opt = solution.minOperations(39);
    std::cout << opt << std::endl;

    opt = solution.minOperations(39);
    std::cout << opt << std::endl;
}
