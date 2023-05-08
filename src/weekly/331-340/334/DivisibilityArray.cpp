
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<int> divisibilityArray(std::string word, int m)
    {
        size_t length = word.length();
        std::vector<int> divs(length);

        unsigned long long curNum = word[0] - '0';
        divs[0] = curNum % m == 0 ? 1 : 0;

        for (size_t index = 1; index < length; index++)
        {
            curNum = curNum * 10 + (word[index] - '0');
            divs[index] = curNum % m == 0 ? 1 : 0;
        }

        return divs;
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> divs = solution.divisibilityArray("998244353", 3);
    for (size_t index = 0; index < divs.size(); index++)
    {
        std::cout << divs[index] << ',';
    }
    std::cout << std::endl;
}