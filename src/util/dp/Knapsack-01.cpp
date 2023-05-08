
#include <iostream>
#include <vector>

#include "../RandomUtil.cpp"

/**
 * 01背包问题
 * 
 */
class Knapsack01
{
public:
    static int maxValue(std::vector<int> values, std::vector<int> volumes, int knapsackCapacity)
    {
        int lenOfGoods = (int)values.size();
        int dp[lenOfGoods + 1][knapsackCapacity + 1]{};

        // 初始化迭代边界为 0
        for (int i = 0; i <= knapsackCapacity; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= lenOfGoods; i++)
            dp[i][0] = 0;

        // 外循环是物品, 内循环是背包容量
        for (int i = 1; i <= lenOfGoods; i++)
        {
            // 获得当前迭代物品的属性
            int value = values[i-1];
            int volume = volumes[i-1];
            // 从容量 1 到容量 knapsackCapacity
            for (int capacity = 1; capacity <= knapsackCapacity; capacity++)
            {
                // 如果当前物品的重量大于背包容量
                if (volume > capacity)
                    dp[i][capacity] = dp[i - 1][capacity];
                else
                {
                    int newValue = value + dp[i - 1][capacity - volume];
                    // 如果
                    if (newValue > dp[i - 1][capacity])
                        dp[i][capacity] = newValue;
                    else
                        dp[i][capacity] = dp[i - 1][capacity];
                }
            }
        }

        return dp[lenOfGoods][knapsackCapacity];
    }
};

int main(void)
{
    int len = 10;
    std::vector<int> values(len);
    std::vector<int> volumes(len);

    RandomUtil::setRandomVector(values, 10, 20, len);
    RandomUtil::setRandomVector(volumes, 10, 20, len);

    std::cout << "value:  ";
    for (auto value : values) {
        std::cout << value << ' ' ;
    }
    std::cout << std::endl;
    std::cout << "volume: ";
    for (auto volume : volumes) {
        std::cout << volume << ' ' ;
    }
    std::cout << std::endl;
    std::cout << Knapsack01::maxValue(values, volumes, len*10) << std::endl;
}
