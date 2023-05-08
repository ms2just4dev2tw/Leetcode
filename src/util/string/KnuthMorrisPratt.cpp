
#include <iostream>
#include <string>
#include <array>

class KMP
{
public:
    static int index(std::string subjectStr, std::string templateStr)
    {
        // 最后一位的 next 无需设置
        int partialMatchTable[templateStr.size()-1]{};
        setOptimizedPartialMatchTable(templateStr, partialMatchTable);

        size_t index4sub = 0, index4tem = 0;
        while (index4sub<subjectStr.size() && index4tem<templateStr.size()) {
            if (subjectStr[index4sub] == templateStr[index4tem]) {
                index4sub++;
                index4tem++;
            } else if (index4tem == 0) {
                index4sub++;
            } else {
                index4tem = partialMatchTable[index4tem-1];
            }
        }

        return index4tem == templateStr.size() ? index4sub-index4tem : -1;
    }

private:
    /**
	 *        a a a a b
	 * index  0 1 2 3 4
	 * value  0 1 2 3 /
	 * 
	 * opt    0 0 0 3 /
	 * 
	 *        a a a a a
	 * opt    0 0 0 0 /
	 * 
	 * 最后一位的 next 无需设置；如果在 b 发生不匹配，等同于求 aaaa 的最大前缀后缀相同长度<br>
	 * 优化点在于j与左右一位都相等，那么在j+1处不匹配，那么必定在j处也不匹配
	 */
    static void setOptimizedPartialMatchTable(std::string templateStr, int* partialMatchTable)
    {
        int len = (int)templateStr.size();

        for (int i=0, j=1; j < len-1;) {
            if (templateStr[i] == templateStr[j]) {
                if (j-i==1 && templateStr[j]==templateStr[j+1]) {
                    *(partialMatchTable+j) = *(partialMatchTable+i);
                } else {
                    *(partialMatchTable+j) = i+1;
                }
                i++;
                j++;
            } else if (i == 0) {
                *(partialMatchTable+j) = 0;
                j++;
            } else {
                i = *(partialMatchTable+(i-1));
            }
        }
    }
};


int main(void) {
    std::cout << KMP::index("aaaaab", "aaab") << std::endl;
    std::cout << KMP::index("ababcabcacbab", "abcac") << std::endl;
    std::cout << KMP::index("abcaabbabcabaacbacba", "abcabaa") << std::endl;
    std::cout << KMP::index("abcaabbabcabaacbacba", "abcdefg") << std::endl;
}
