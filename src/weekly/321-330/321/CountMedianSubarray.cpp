
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int countSubarrays(std::vector<int>& nums, int k) {
        int flag[nums.size()]{};
        int location = -1;
        for (size_t index = 0; index < nums.size(); index++) {
            if (nums[index] > k) {
                flag[index] = 1;
            } else if (nums[index] < k) {
                flag[index] = -1;
            } else {
                flag[index] = 0;
                location = (int)index;
            }
        }

        int count = 1;
        for (int selectLen = 1; selectLen < (int)nums.size(); selectLen++) {
            int left,right;
            if (selectLen > location) {
                left = 0;
                right = selectLen;
            } else {
                left = location-selectLen;
                right = location;
            }

            // 算一次和值
            int flagSum = 0;
            for (int index = left; index <= right; index++) {
                flagSum += flag[index];
            }
            if (flagSum==0 || flagSum==1) {
                count++;
            }

            // 选择的长度不变，右移
            for (left++,right++; left<=location&&right>=location && right<(int)nums.size(); left++,right++) {
                flagSum = flagSum - flag[left-1] + flag[right];
                if (flagSum==0 || flagSum==1) {
                    count++;
                }
            }
        }

        return count;
    }

    int countSubarrays2(std::vector<int>& nums, int k) {
        int n = nums.size();
        int kIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                kIndex = i;
                break;
            }
        }
        int ans = 0;
        std::unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sign(nums[i] - k);
            if (i < kIndex) {
                counts[sum]++;
            } else {
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                ans += prev0 + prev1;
            }
        }
        return ans;
    }

    inline int sign(int num) {
        if (num == 0) {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

};

int main(void)
{
    Solution solution;

    std::vector<int> nums = {3,2,1,4,5};
    int ret = solution.countSubarrays(nums,4);
    std::cout << ret << std::endl;

    nums = {2,3,1};
    ret = solution.countSubarrays(nums, 3);
    std::cout << ret << std::endl;

    nums = {4,5,3,1,2};
    ret = solution.countSubarrays(nums, 3);
    std::cout << ret << std::endl;

    nums = {1,4,3,5,2};
    ret = solution.countSubarrays(nums, 3);
    std::cout << ret << std::endl;

    nums = {1,4,3,5,2};
    ret = solution.countSubarrays2(nums, 3);
    std::cout << ret << std::endl;

    nums = {5,4,3,6,7};
    ret = solution.countSubarrays2(nums, 3);
    std::cout << ret << std::endl;
}
