
#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isItPossible(std::string word1, std::string word2)
    {
        std::unordered_map<char, int> map1{};
        std::unordered_map<char, int> map2{};
        for (char ch : word1)
        {
            map1[ch]++;
        }
        for (char ch : word2)
        {
            map2[ch]++;
        }

        int num1 = (int)map1.size();
        int num2 = (int)map2.size();

        if (num1 == num2)
        {
            return true;
        }

        for (auto &pair1 : map1)
        {
            for (auto &pair2 : map2)
            {
                int t1 = num1;
                int t2 = num2;

                if (!map1.count(pair1.first))
                    ++t1;
                if (!map2.count(pair2.first))
                    ++t2;

                if (pair1.second == 1)
                    --t1;
                if (pair2.second == 1)
                    --t2;

                if (t1 == t2)
                {
                    return true;
                }
            }
        }

        return false;
    }
};


int main(void)
{
    Solution solution;

    bool ret = solution.isItPossible("abcc","aab");
    std::cout << ret << std::endl;

    ret = solution.isItPossible("ac","b");
    std::cout << ret << std::endl;
}
