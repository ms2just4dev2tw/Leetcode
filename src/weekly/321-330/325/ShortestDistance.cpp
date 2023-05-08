
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


class Solution {
public:
    int closetTarget(std::vector<std::string>& words, std::string target, int startIndex) {
        size_t length = words.size();
        int minDistance = -1;

        // 正向
        for (int index = (startIndex+1)%length, step = 1; index != startIndex; index = (index+1)%length, step++) {
            if (words[index].compare(target) == 0) {
                minDistance = step;
                break;
            }
        }

        // 负向
        for (int index = (startIndex-1+length)%length, step = 1; index != startIndex; index = (index-1+length)%length, step++) {
            if (words[index].compare(target) == 0) {
                minDistance = minDistance == -1 || minDistance > step ? step : minDistance;
            }
        }

        return minDistance;
    }
};



int main(void)
{
    Solution solution;

    std::vector<std::string> words = {"hello","i","am","leetcode","hello"};
    int ret = solution.closetTarget(words,"hello",1);
    std::cout << ret << std::endl;

    words = {"a","b","leetcode"};
    ret = solution.closetTarget(words,"leetcode",0);
    std::cout << ret << std::endl;

    words = {"i","eat","leetcode"};
    ret = solution.closetTarget(words,"ate",0);
    std::cout << ret << std::endl;
}
