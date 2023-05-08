
#include<iostream>
#include<string>


/**
 * KMP
 * 
 */
class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        int i,j;
        for( i=0,j=0; i<(int)t.size()&&j<(int)s.size(); j++)
        {
            if(s[j]==t[i])
                i++;
        }
        return t.size()-i;
    }
};

int main(void)
{
    Solution solution;

    int ret = solution.appendCharacters("coaching", "coding");
    std::cout << ret << std::endl;

    ret = solution.appendCharacters("abcde", "a");
    std::cout << ret << std::endl;

    ret = solution.appendCharacters("z", "abcde");
    std::cout << ret << std::endl;

    ret = solution.appendCharacters("aaaaab", "aaab");
    std::cout << ret << std::endl;
}
