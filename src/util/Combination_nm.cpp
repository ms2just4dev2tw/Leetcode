
#include <iostream>
#include <vector>
#include <string>


class Combination {
public:
    int times(int n, int m) {
        int ord1 = 1;
        for (int i = n, step = 0; step < m; i--, step++) {
            ord1 *= i;
        }

        int ord2 = 1;
        for (int j = 1; j <= m; j++) {
            ord2 *= j;
        }

        return ord1/ord2;
    }

    std::vector<std::string> getCombinationVector(std::vector<int>& nums, int k) {
        std::vector<std::string> retArr{};

        std::vector<int> indexArr{};
        for (int index = 0; index < k; index++) {
            indexArr.push_back(index);
        }

        size_t length = nums.size();

        for ( ;isValid(indexArr,k,length); setNextIndex(indexArr,k,length)) {
            for (size_t index = indexArr[k-1]; index < length; index++) {
                std::string ret;
                indexArr[k-1] = index;
                // ret.assign(indexArr.begin(), indexArr.end());
                ret = "(" + std::to_string(nums[indexArr[0]]);
                for (int i = 1; i<k; i++) {
                    ret += "," + std::to_string(nums[indexArr[i]]);
                }
                ret += ")";
                retArr.push_back(ret);
            }
        }

        return retArr;
    }

private:
    bool isValid(std::vector<int>& indexArr, int k, int n) {
        return indexArr[0] <= n-k && indexArr[k-1] <= n-1;
    }

    void setNextIndex(std::vector<int>& indexArr, int k, int n) {
        int index = k-2;
        for ( ;index >= 0; index--) {
            if (indexArr[index] < n-k+index) {
                indexArr[index]++;
                break;
            }
        }

        if (index < 0) {
            indexArr[index+1]++;
        } else {
            for (int i = index+1; i < k; i++) {
                indexArr[i] = indexArr[i-1] + 1;
            }
        }
    }

};


int main(void) {
    Combination combination;

    int times = combination.times(8,4);
    std::cout << times << std::endl;

    std::vector<int> nums = {13,5,1,8,21,2};
    std::vector<std::string> retArr = combination.getCombinationVector(nums, 3);
}