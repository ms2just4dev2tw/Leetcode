
#include <iostream>
#include <vector>
#include <random>

#include "../RandomUtil.cpp"

/**
 * 堆排序
 * 
 * 可视化: https://www.cs.usfca.edu/~galles/visualization/HeapSort.html
 */
class HeapSort
{
public:
    static void sort(std::vector<int> &nums, int n, bool isAscend = true, int offset = 0)
    {
        // 初始操作: 无序区所有内部节点执行下沉操作
        int end = offset + n;
        for (int internal = end / 2; internal >= 1; internal--)
        {
            sink(nums, internal, end, isAscend);
        }

        // 无序区 => 有序区, 交换顶点与无序区尾部节点后, 顶点执行下沉操作
        int endOfUnorder = n;
        while (endOfUnorder > 1)
        {
            // 交换 1, endOfUnorder
            std::swap(nums[0], nums[endOfUnorder - 1]);
            // 无序区减一
            endOfUnorder--;
            // 下沉 1
            sink(nums, 1, endOfUnorder, isAscend);
        }
    }

private:
    /**
     * 最符合排序规则的元素在 top, 这与 BubbleSort 是相反的
     */
    static void sink(std::vector<int> &nums, int top, int bottom, bool isAscend)
    {
        while (top * 2 <= bottom)
        {
            // top 的左节点
            int swapNode = top * 2;

            // 如果 top 有右节点, 且右节点比左节点更加符合排序规则
            if (swapNode < bottom && accord(nums[swapNode-1], nums[swapNode], isAscend))
                swapNode++;

            // top 与 swapNode 不符合排序规则, 停止循环
            if (notAccord(nums[top-1], nums[swapNode-1], isAscend))
            {
                break;
            }
            else
            {
                std::swap(nums[top-1], nums[swapNode-1]);
                top = swapNode;
            }
        }
    }

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
    int len = 10;
    std::vector<int> nums(len);

    RandomUtil::setRandomVector(nums, 0, len, len);
    HeapSort::sort(nums, len, true);

    for (size_t index = 0; index < nums.size(); index++)
    {
        std::cout << nums[index] << ' ';
    }
}