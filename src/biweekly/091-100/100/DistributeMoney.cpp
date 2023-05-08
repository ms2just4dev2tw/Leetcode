
#include <iostream>


class Solution {
public:
    int distMoney(int money, int children) {
        int k = money/children;
        int remind = money%children;

        if (k == children) {
            return k;
        } else if (k > children) {
            return children-1;
        } else {
            while (remind < children-k) {
                remind += 8;
                k--;
            }

            if (children-k==1 && remind==4) {
                return --k;
            }
            return k;
        }
    }
};

