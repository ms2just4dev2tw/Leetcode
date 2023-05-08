
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <functional>

#include "../RandomUtil.cpp"

/**
 * 桶排序
 * 
 * Ascend:升序 => 使用最小堆作为桶结构
 * Descend:降序 => 使用最大堆作为桶结构
 * 
 * 可视化: https://www.cs.usfca.edu/~galles/visualization/BucketSort.html
 * index = value*LENGTH_OF_ARRAY / (MAXIMUM_ARRAY_VALUE+1)
 */
class BucketSort
{
public:
    static void sort(std::vector<int> &nums, int n, bool isAscend = true, int offset = 0)
    {
        int end = offset + n;
        // 找出 nums 的最小值和最大值
        int min = nums[offset], max = nums[end - 1];
        for (int index = offset; index < end; index++)
        {
            min = min > nums[index] ? nums[index] : min;
            max = max < nums[index] ? nums[index] : max;
        }

        // nums 的间距和待排序的数值个数
        int gap = max - min + 1, lenOfBucket = n;
        // 初始化桶数组
        auto my_comp = [&](const int &z1, const int &z2)
        {
            return isAscend ? z1>z2 : z1<z2;
        };
        std::priority_queue<int,std::vector<int>,decltype(my_comp)> bucketPtrList[lenOfBucket];

        // 将值存放入桶
        for (int index = offset; index < end; index++)
        {
            int indexOfBucket = (nums[index] - min) * lenOfBucket / gap;
            bucketPtrList[indexOfBucket].push(nums[index]);
        }

        // 取出桶的值
        for (int indexOfBucket = 0, delta = 0; indexOfBucket < lenOfBucket; indexOfBucket++)
        {
            std::priority_queue<int,std::vector<int>,decltype(my_comp)> bucketPtr = bucketPtrList[indexOfBucket];
            while (!bucketPtr.empty())
            {
                if (isAscend)
                    nums[offset + delta] = bucketPtr.top();
                else
                    nums[end - delta - 1] = bucketPtr.top();
                bucketPtr.pop();
                delta++;
            }
        }
    }
};

int main(void)
{
    int len = 10;
    std::vector<int> nums(len);

    RandomUtil::setRandomVector(nums, 100, 1000, len);
    BucketSort::sort(nums, len, false);

    for (size_t index = 0; index < nums.size(); index++)
    {
        std::cout << nums[index] << ' ';
    }
}
