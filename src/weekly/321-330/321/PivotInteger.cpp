
#include<iostream>
#include<cmath>


/**
 * 1 ~ x = (x*(x+1)) / 2
 * x ~ n = ((x+1)x) / 2
 * 1 ~ x = x ~ n - 1 ~ x = std::sqrt((n*n+n)/2)
 * 
 * 
 * 
 * https://oeis.org/A001108
 */
class Solution {
public:
    int pivotInteger(int n) {
        // n,n+1,能被2整除
        int tmp = n*(n+1)/2;
        int x = (int)std::sqrt(tmp);
        return x*x == tmp ? true : false;
    }
};

int main(void)
{
    Solution solution;

    bool ret = solution.pivotInteger(8);
    std::cout << std::boolalpha << ret << std::endl;

    ret = solution.pivotInteger(4);
    std::cout << std::boolalpha << ret << std::endl;

    ret = solution.pivotInteger(1);
    std::cout << std::boolalpha << ret << std::endl;
}
