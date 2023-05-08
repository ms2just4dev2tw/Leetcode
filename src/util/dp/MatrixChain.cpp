
#include <iostream>
#include <vector>
#include <limits>

#include "../RandomUtil.cpp"

/**
 * 矩阵连乘
 * 
 * 矩阵连乘例子：A1(30x35)A2(35x15)A3(15x5)A4(5x10)A5(10x20)A6(20x25)
 * 
 * 0(0)    15750(1)    7875(2)    9375(3)    11875(4)    15125(5)
 *         0(0)        2625(1)    4375(2)    7125(3)     10500(4)
 *                     0(0)       750(1)     2500(2)     5375(3)
 *                                0(0)       1000(1)     3500(2)
 *                                           0(0)        5000(1)
 *                                                       0(0)
 */
class MatrixChain
{
public:
    static int minValue(std::vector<int> rows, std::vector<int> cols)
    {
        int lenOfMatrix = (int)rows.size();

        int dp[lenOfMatrix][lenOfMatrix]{};

        //
        for (int gap = 1; gap < lenOfMatrix; gap++)
        {
            for (int left = 0, right = left + gap; right < lenOfMatrix; left++, right++)
            {
                // 初始设置最大值
                dp[left][right] = std::numeric_limits<int>::max();
                for (int index = left; index < right; index++)
                {
                    int newValue = dp[left][index] + dp[index + 1][right];
                    newValue += rows[left] * cols[index] * cols[right];
                    if (newValue < dp[left][right])
                        dp[left][right] = newValue;
                }
            }
        }

        return dp[0][lenOfMatrix-1];
    }
};

int main(void)
{
    int len = 6;
    std::vector<int> rows(len);
    std::vector<int> cols(len);

    RandomUtil::setRandomVector(rows, 10, 20, len);
    RandomUtil::setRandomVector(cols, 10, 20, len);

    // A1(30x35)A2(35x15)A3(15x5)A4(5x10)A5(10x20)A6(20x25)
    rows = {30,35,15,5,10,20};
    cols = {35,15,5,10,20,25};

    std::cout << "row: ";
    for (auto row : rows)
    {
        std::cout << row << ' ';
    }
    std::cout << std::endl;
    std::cout << "col: ";
    for (auto col : cols)
    {
        std::cout << col << ' ';
    }
    std::cout << std::endl;
    std::cout << MatrixChain::minValue(rows, cols) << std::endl;
}
