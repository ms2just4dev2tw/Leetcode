
#include <iostream>
#include <queue>


class GraphBFS
{
private:
    // 队列作为保存节点的容器, 先进先出
    std::queue<int> queue;

    // 每个节点的访问 flag
    bool visited[];
    
public:
    GraphBFS(/* args */);
    ~GraphBFS();
};
