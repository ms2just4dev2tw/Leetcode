
#include <iostream>
#include <string>


class Solution {
public:
    int alternateDigitSum(int n) {
        std::string str = std::to_string(n);

        int sum = 0;
        for (size_t index = 0; index <= str.size(); index++) {
            if (index % 2 == 0) {
                sum += str[index] - '0';
            } else {
                sum -= str[index] - '0';
            }
        }
        return sum;
    }
};



int main(void)
{
    Solution solution;

    int ret = solution.alternateDigitSum(521);
    std::cout << ret << std::endl;

    ret = solution.alternateDigitSum(111);
    std::cout << ret << std::endl;
}
