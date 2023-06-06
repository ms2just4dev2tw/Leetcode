
#include <iostream>

/**
 * 2602. 使数组元素全部相等的最少操作次数
 *
 * https://leetcode.cn/contest/weekly-contest-338/
 * https://leetcode.cn/problems/k-items-with-the-maximum-sum/
 */
class Solution
{
public:
    int primeSubOperationkItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (k <= numOnes)
            return k;
        else if (k <= numOnes + numZeros)
            return numOnes;
        else if (k <= numOnes + numZeros + numNegOnes)
            return numOnes - (k - numOnes - numZeros);
        else
            return numOnes - numNegOnes;
    }
};

int main(void)
{
    Solution solution;

    std::cout << solution.primeSubOperationkItemsWithMaximumSum(3,2,0,2) << std::endl;
    std::cout << solution.primeSubOperationkItemsWithMaximumSum(3,2,0,4) << std::endl;
}
