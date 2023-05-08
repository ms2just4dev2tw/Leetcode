
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int posStart = 0;
        int posEnd = (int)nums.size();
        int posMid = (posStart+posEnd)/2;

        for (; nums[posMid-1]<=0&&nums[posMid]>0; posMid = (posStart+posEnd)/2) {
            if (nums[posMid] <= 0) {
                posStart = posMid;
            } else {
                posEnd = posMid;
            }
        }

        int negStart = 0;
        int negEnd = (int)nums.size();
        int negMid = (negStart+negEnd)/2;
        for (; nums[negMid+1]>=0&&nums[negMid]<0; negMid = (negStart+negEnd)/2) {
            if (nums[negMid] >= 0) {
                negEnd = negMid;
            } else {
                negStart = negMid;
            }
        }

        return std::max((int)(nums.size()-posMid),negMid+1);
    }
};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {-2,-1,-1,1,2,3};
    int ret = solution.maximumCount(nums);
    std::cout << ret << std::endl;

    nums = {-3,-2,-1,0,0,1,2};
    ret = solution.maximumCount(nums);
    std::cout << ret << std::endl;

}
