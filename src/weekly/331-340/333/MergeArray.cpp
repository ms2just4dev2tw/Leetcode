
#include <iostream>
#include <vector>


/**
 * 
 * 
 * 因为 nums1, nums2 都包含 互不相同 的 id ，并按 id 以 递增 顺序排列
 * 所以采用归并排序
 */
class Solution {
public:
    std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
        size_t i = 0, j = 0;
        size_t length1 = nums1.size(), length2 = nums2.size();

        std::vector<std::vector<int>> ret(0);
        while (i < length1 && j < length2)
        {
            int id1 = nums1[i][0], id2 = nums2[j][0];
            if (id1 < id2) {
                ret.push_back(nums1[i++]);
            } else if (id1 == id2) {
                ret.push_back(std::vector<int>{id1,nums1[i++][1]+nums2[j++][1]});
            } else {
                ret.push_back(nums2[j++]);
            }
        }
        
        while (i < length1) {
            ret.push_back(nums1[i++]);
        }

        while (j < length2) {
            ret.push_back(nums1[j++]);
        }

        return ret;
    }
};


int main(void)
{
    Solution solution;
    
    std::vector<std::vector<int>> nums1 {{1,2},{2,3},{4,5}};
    std::vector<std::vector<int>> nums2 {{1,4},{3,2},{4,1}};

    std::vector<std::vector<int>> ret = solution.mergeArrays(nums1, nums2);
    for (size_t index = 0; index < ret.size(); index++)
    {
        std::cout << ret[index][0] << ',' << ret[index][1] << std::endl;
    }

    nums1 = {{2,4},{3,6},{5,5}};
    nums2 = {{1,3},{4,3}};

    ret = solution.mergeArrays(nums1, nums2);
    for (size_t index = 0; index < ret.size(); index++)
    {
        std::cout << ret[index][0] << ',' << ret[index][1] << std::endl;
    }
}