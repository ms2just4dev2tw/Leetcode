

#include <iostream>
#include <string>
#include <regex>

/**
 * 831. 隐藏个人信息
 * https://leetcode.cn/problems/masking-personal-information/
 */
class Solution
{
public:
    /**
     * 个人信息脱敏
     */
    std::string maskPersonalInformation(std::string str)
    {
        // 有符号 @ 为 email，否则为 phone
        std::string::size_type index = str.find('@');
        if (index == std::string::npos)
        {
            // 过滤掉所有非数字字符
            std::regex digitFilter("\\D+");
            std::string phoneNumber = std::regex_replace(str, digitFilter, "");
            // 截取后 4 位
            std::string last4 = phoneNumber.substr(phoneNumber.size() - 4);
            // 根据数字长度做不同的处理
            int length = phoneNumber.size();
            if (length == 10)
                return "***-***-" + last4;
            else if (length == 11)
                return "+*-***-***-" + last4;
            else if (length == 12)
                return "+**-***-***-" + last4;
            else
                return "+***-***-***-" + last4;
        }
        else
        {
            std::string ret = "8*****8";
            ret[0] = str[0];
            ret[ret.size() - 1] = str[index - 1];
            return ret + str.substr(index);
        }
    }
};

int main(void)
{
    Solution solution;
    std::cout << solution.maskPersonalInformation("LeetCode@LeetCode.com") << std::endl
              << solution.maskPersonalInformation("AB@qq.com") << std::endl
              << solution.maskPersonalInformation("1(234)567-890") << std::endl
              << solution.maskPersonalInformation("86-(10)12345678") << std::endl;
}
