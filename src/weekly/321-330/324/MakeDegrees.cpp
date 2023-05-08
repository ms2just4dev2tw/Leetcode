
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Solution
{
public:
    bool isPossible(int n, std::vector<std::vector<int>> &edges)
    {
        int vertexNumber = n;
        std::unordered_map<int, int> countMap{};
        for (auto &edge : edges)
        {
            countMap[edge[0]]++;
            countMap[edge[1]]++;
        }

        int oddCount = 0;
        for (auto& pair : countMap) {
            if (pair.second%2 != 0 && pair.second != vertexNumber-1) {
                oddCount++;
            }
        }

        return oddCount<=4 && oddCount%2 == 0;
    }

    bool isPossible2(int n, std::vector<std::vector<int>> &edges) {
        std::unordered_set<int> g[n + 1];
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].insert(y);
            g[y].insert(x);
        }
        std::vector<int> odd;
        for (int i = 1; i <= n; ++i)
            if (g[i].size() % 2) odd.push_back(i);
        int m = odd.size();
        if (m == 0) return true;
        if (m == 2) {
            int x = odd[0], y = odd[1];
            if (!g[x].count(y)) return true;
            for (int i = 1; i <= n; ++i)
                if (i != x && i != y && !g[i].count(x) && !g[i].count(y))
                    return true;
            return false;
        }
        if (m == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            return !g[a].count(b) && !g[c].count(d) ||
                   !g[a].count(c) && !g[b].count(d) ||
                   !g[a].count(d) && !g[b].count(c);
        }
        return false;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::vector<int>> edges = {{1,2},{2,3},{3,4},{4,2},{1,4},{2,5}};
    bool ret = solution.isPossible2(5, edges);
    std::cout << ret << std::endl;

    edges = {{1,2},{1,3},{1,4}};
    ret = solution.isPossible(4, edges);
    std::cout << ret << std::endl;
}
