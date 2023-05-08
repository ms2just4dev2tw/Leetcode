
#include <iostream>
#include <vector>
#include <queue>


/**
 * 优先队列
 * 
 */
template <class value, typename compare, typename container>
class PriorityQueue
{
private:
    int index = 0;
    container heap;

public:
    PriorityQueue(/* args */);
    ~PriorityQueue();

    value pop() {
        // 首部元素为返回值, 将首部与尾部元素交换位置

        // 首部元素执行下沉操作

    }

    void push(value v) {
        // 尾部插入 value

        // 尾部元素执行上浮操作

    }

private:
    /**
     * 堆的元素上浮操作
     */
    void swim(value v) {

    }

    /**
     * 堆的元素下浮操作
     */
    void sink(value k) {

    }
    
    /**
     * 元素交换位置
     */
    void exchange() {

    }
};

