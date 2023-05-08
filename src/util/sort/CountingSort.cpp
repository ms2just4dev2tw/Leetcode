
#include <iostream>
#include <vector>
#include <random>

#include "../RandomUtil.cpp"

/**
 * 计数排序
 * 
 * 可视化: https://www.cs.usfca.edu/~galles/visualization/CountingSort.html
 */
class CountingSort
{
public:
    static void sort(std::vector<int> &nums, int n, bool isAscend=true, int offset=0)
    {
        int end = offset + n;
        // 找出 nums 的最小值和最大值
        int min = nums[offset], max = nums[end-1];
        for (int index = offset; index < end; index++) {
            min = min>nums[index] ? nums[index] : min;
            max = max<nums[index] ? nums[index] : max;
        }

        // 计数数组
        int countLen = max-min+1;
        int countArr[countLen]{};
        for (int index = offset; index < end; index++) {
            countArr[nums[index]-min]++;
        }

        // 计数数组的相邻两位计数叠加
        for (int index=0, next=index+1; next<countLen; index++, next++) {
            countArr[next] += countArr[index];
        }

        // 根据 nums 和 countArr 将数据写入 buff
        int buffLen = (int)nums.size();
        int buff[buffLen]{};
        for (int index = offset; index < end; index++) {
            int count = countArr[nums[index]-min]--;
            // Ascend:升序 =>    Descend:降序 => 
            if (isAscend)
                buff[offset+count-1] = nums[index];
            else
                buff[end-count] = nums[index];
        }

        // 覆写数据
        for (int index = offset; index < end; index++) {
            nums[index] = buff[index];
        }
    }
};

int main(void)
{
    int len = 10;
    std::vector<int> nums(len);

    RandomUtil::setRandomVector(nums, 0, len, len);
    CountingSort::sort(nums, len, false);

    for (size_t index = 0; index < nums.size(); index++)
    {
        std::cout << nums[index] << ' ';
    }
}
