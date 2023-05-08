
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Solution
{
public:
    int takeCharacters(std::string s, int k)
    {
        std::vector<int> check(3);
        int n = s.size();
        /* 统计每个字符出现的次数 */
        for (auto &ch : s)
        {
            check[ch - 'a']++;
        }
        if (check[0] < k || check[1] < k || check[2] < k)
        {
            return -1;
        }
        /* 计算中间区间, 每个字符不能超过的个数 */
        for (int i = 0; i < 3; i++)
        {
            check[i] -= k;
        }

        std::vector<int> cnt(3);
        int ans = 0;
        /* 双指针模板, 中间区间[j, i]每个字符都不能超过check */
        for (int i = 0, j = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            cnt[idx]++;
            while (cnt[idx] > check[idx])
            {
                cnt[s[j++] - 'a']--;
            }
            ans = std::max(ans, i - j + 1);
        }
        return n - ans;
    }

    int takeCharacters2(std::string s, int K)
    {
        // 特殊情况
        if (K == 0)
            return 0;

        int n = s.size();
        // 判断无解
        int cnt[3] = {0};
        for (char c : s)
            cnt[c - 'a']++;
        if (cnt[0] < K || cnt[1] < K || cnt[2] < K)
            return -1;

        // 检查二分的答案 LIM 是否符合要求
        auto check = [&](int LIM)
        {
            // 先假设 LIM 个字符全部从左边取出，看是否符合要求
            int cnt[3] = {0};
            for (int i = 0; i < LIM; i++) {
                cnt[s[i] - 'a']++;
            }
            if (cnt[0] >= K && cnt[1] >= K && cnt[2] >= K) {
                return true;
            }
            // 每次左边少取一个字符，右边多取一个字符，看是否符合要求
            for (int i = 1; i <= LIM; i++)
            {
                cnt[s[LIM - i] - 'a']--;
                cnt[s[n - i] - 'a']++;
                if (cnt[0] >= K && cnt[1] >= K && cnt[2] >= K) {
                    return true;
                }
            }
            return false;
        };

        // 二分答案
        int head = 1, tail = n;
        while (head < tail)
        {
            int mid = (head + tail) >> 1;
            if (check(mid))
                tail = mid;
            else
                head = mid + 1;
        }
        return head;
    }
};

int main(void)
{
    Solution solution;

    int ret = solution.takeCharacters2("aabaaaacaabc", 2);
    std::cout << ret << std::endl;
}
