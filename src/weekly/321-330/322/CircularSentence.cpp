
#include <iostream>
#include <string>


class Solution {
public:
    bool isCircularSentence(std::string sentence) {
        for (size_t index = 0; index < sentence.size(); index++) {
            if (sentence[index]==' ' && sentence[index-1]!=sentence[index+1]) {
                return false;
            }
        }

        return sentence[0]==sentence[sentence.size()-1] ? true : false;
    }
};

int main(void)
{
    Solution solution;

    bool ret = solution.isCircularSentence("leetcode exercises sound delightful");
    std::cout << std::boolalpha << ret << std::endl;

    ret = solution.isCircularSentence("eetcode");
    std::cout << std::boolalpha << ret << std::endl;

    ret = solution.isCircularSentence("Leetcode is cool");
    std::cout << std::boolalpha << ret << std::endl;
}
