
#include <iostream>
#include <vector>
#include <random>

#include "../RandomUtil.cpp"

/**
 * 冒泡排序
 * 
 * 可视化: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html 
 */
class BubbleSort
{
public:
    static void sort(std::vector<int> &nums, int n, bool isAscend = true, int offset = 0)
    {
        int end = offset + n;
        for (int left = offset; left < end; left++)
        {
            // 从 [left,n) 找出最值
            for (int right = left + 1; right < end; right++)
            {
                // 如果 left, right 不符合排序规则, 就交换两个值
                if (notAccord(nums[left], nums[right], isAscend))
                    std::swap(nums[left], nums[right]);
            }
        }
    }

private:
    static bool accord(int left, int right, bool isAscend)
    {
        // Ascend:升序 => 0,1,2   Descend:降序 => 2,1,0
        return isAscend ? left < right : left > right;
    }

    static bool notAccord(int left, int right, bool isAscend)
    {
        return !accord(left, right, isAscend);
    }
};

int main(void)
{
    int len = 20;
    std::vector<int> nums(len);

    RandomUtil::setRandomVector(nums, 0, len, len);
    BubbleSort::sort(nums, len, false);

    for (size_t index = 0; index < nums.size(); index++)
    {
        std::cout << nums[index] << ' ';
    }
}
