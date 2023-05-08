
#include <iostream>

class Solution
{
public:
    int smallestValue(int n)
    {
        int pre = 0, next = n;
        while (pre != next)
        {
            pre = next;
            next = 0;
            int num = pre;
            for (int factor = 2; factor * factor <= pre; factor++)
            {
                while (num % factor == 0)
                {
                    num /= factor;
                    next += factor;
                }
            }
            next += num>1 ? num : 0;
        }

        return next;
    }
};

int main(void)
{
    Solution solution;

    int ret = solution.smallestValue(15);
    std::cout << ret << std::endl;

    ret = solution.smallestValue(3);
    std::cout << ret << std::endl;
}
