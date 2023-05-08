
#include <random>
#include <vector>

#include <map>
#include <iostream>

class RandomUtil
{
public:
    static void setRandomVector(std::vector<int> &nums, int min, int max, int n, int offset=0)
    {
        // 随机数引擎的种子
        std::random_device seed;
        // 随机数引擎: 32 位梅森缠绕器
        std::mt19937 gen(seed());
        // 随机数分布: 产生在一个范围上均匀分布的整数值
        std::uniform_int_distribution<> dis(min, max);

        int end = offset + n;
        for (int index = offset; index < end; index++)
        {
            nums[index] = dis(gen);
        }
    }
};
