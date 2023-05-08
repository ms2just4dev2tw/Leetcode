
#include <iostream>
#include <string>

class Solution
{
public:
    int minimumPartition(std::string s, int k)
    {
        int count = 0;
        size_t gap = std::to_string(k).size();
        for (size_t index = 0; index < s.size(); index += gap) {
            int num = std::stoi(s.substr(index,gap));
            if (num <= k) {
                count++;
            } else {
                index--;
                count++;
            }
        }
        return count;
    }
};


int main(void)
{
    Solution solution;

    int ret = solution.minimumPartition("165462",60);
    std::cout << ret << std::endl;
}
