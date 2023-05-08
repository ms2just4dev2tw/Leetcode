
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
    {
        std::string vowel = "aeiou";
        int containVowelArr[words.size()] = {};
        for (size_t index = 0; index < words.size(); index++)
        {
            if (vowel.find(words[index].front()) != std::string::npos && vowel.find(words[index].back()) != std::string::npos)
            {
                containVowelArr[index] = 1;
            }
        }

        std::vector<int> retArr(queries.size());
        for (size_t index = 0; index < queries.size(); index++)
        {
            std::vector<int> querie = queries[index];
            for (int start = querie[0], end = querie[1]; start <= end; start++)
            {
                retArr[index] += containVowelArr[start];
            }
        }

        return retArr;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::string> words = {"aba","bcb","ece","aa","e"};
    std::vector<std::vector<int>> queries = {{0,2},{1,4},{1,1}};

    std::vector<int> retArr = solution.vowelStrings(words, queries);
    for (size_t index = 0; index < retArr.size(); index++) {
        std::cout << retArr[index] << ',';
    }
}
