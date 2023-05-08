
#include <iostream>

/**
 * 2582. 递枕头
 * 
 * https://leetcode.cn/contest/weekly-contest-335/
 * https://leetcode.cn/problems/pass-the-pillow/
 */
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int arr[2 * n - 2];
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        for (int i = 1; i < n - 1; i++)
        {
            arr[n + i - 1] = n - i;
        }
        //
        return arr[time % (2 * n - 2)];
    }
};

int main(void)
{
    Solution solution;
    std::cout << solution.passThePillow(4, 5) << std::endl
              << solution.passThePillow(3, 2) << std::endl;
}
