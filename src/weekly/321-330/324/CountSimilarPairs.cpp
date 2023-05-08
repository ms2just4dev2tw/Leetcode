
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int similarPairs(std::vector<std::string> &words)
    {
        int ret = 0;
        std::unordered_map<int, int> map;
        for (auto &word : words)
        {
            int bitMapNumber = 0;
            for (auto &ch : word)
            {
                bitMapNumber |= (1 << (ch - 'a'));
            }
            ret += map[bitMapNumber]++;
        }
        return ret;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::string> words = {"aba", "aabb", "abcd", "bac", "aabc"};
    int ret = solution.similarPairs(words);
    std::cout << ret << std::endl;

    words = {"aabb", "ab", "ba"};
    ret = solution.similarPairs(words);
    std::cout << ret << std::endl;

    words = {"nba", "cba", "dba"};
    ret = solution.similarPairs(words);
    std::cout << ret << std::endl;
}
