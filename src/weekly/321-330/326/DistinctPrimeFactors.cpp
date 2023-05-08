
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int distinctPrimeFactors(std::vector<int> &nums)
    {
        std::unordered_set<int> primes{};

        for (auto num : nums)
        {
            // 对每个数分解质因数
            for (int i = 2; i * i <= num; i++)
            {
                // 
                if (num % i == 0)
                {
                    primes.insert(i);
                    // 除尽 i
                    while (num % i == 0)
                    {
                        num /= i;
                    }
                }
            }
            if (num > 1)
            {
                primes.insert(num);
            }
        }

        return (int)primes.size();
    }
};


int main(void)
{
    Solution solution;

    std::vector<int> nums = {2,4,3,7,10,6};
    int ret = solution.distinctPrimeFactors(nums);
    std::cout << ret << std::endl;

    nums = {2,4,8,16};
    ret = solution.distinctPrimeFactors(nums);
    std::cout << ret << std::endl;
}
