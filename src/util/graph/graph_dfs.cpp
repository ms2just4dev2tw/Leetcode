
#include <iostream>
#include <stack>


class GraphDFS
{
private:
    // 用栈作为保存节点的容器, 先进后出
    std::stack<int> stack;

    // 每个节点的访问 flag
    bool visited[];
    
public:
    GraphDFS(/* args */);
    ~GraphDFS();
};
