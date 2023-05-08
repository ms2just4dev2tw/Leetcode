
#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> cycleLengthQueries(int n, std::vector<std::vector<int>>& queries) {
        std::vector<int> retArr = {};
        for (auto& querie : queries) {
            int ret = 0;

            std::vector<int> firstSequence = getTreeSequence(querie[0]);
            std::vector<int> secondSequence = getTreeSequence(querie[1]);

            size_t len1 = firstSequence.size(), len2 = secondSequence.size();
            int i = len1-1, j = len2-1;
            while (i>=0&&j>=0&&firstSequence[i]==secondSequence[j]) {
                i--;
                j--;
            }

            ret = i+j+3;
            retArr.push_back(ret);
        }
        return retArr;
    }

    std::vector<int> getTreeSequence(int num) {
        std::vector<int> sequence = {};

        int value = num;
        while (value != 0)
        {
            sequence.push_back(value);
            value /= 2;
        }
        
        return sequence;
    }
};

int main(void)
{
    Solution solution;

    std::vector<std::vector<int>> edges = {{5,3},{4,7},{2,3}};
    std::vector<int> retArr = solution.cycleLengthQueries(3, edges);
    for (auto& ret : retArr) {
        std::cout << ret << std::endl;
    }

    edges = {{1,2}};
    retArr = solution.cycleLengthQueries(2, edges);
    for (auto& ret : retArr) {
        std::cout << ret << std::endl;
    }
}
