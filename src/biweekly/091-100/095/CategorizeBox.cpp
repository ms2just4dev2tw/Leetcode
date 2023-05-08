
#include <iostream>
#include <string>


class Solution {
public:
    std::string categorizeBox(int length, int width, int height, int mass) {
        bool flagBulky = false;
        bool flagHeavy = false;

        long long volume = length * width * height;
        if (length>=1e4 || width>=1e4 || height>=1e4 || volume>=1000000000) {
            flagBulky = true;
        }
        if (mass >= 100) {
            flagHeavy = true;
        }

        if (flagBulky && flagHeavy) {
            return "Both";
        } else if (flagBulky) {
            return "Bulky";
        } else if (flagHeavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};

int main(void)
{
    Solution solution;

    std::string ret = solution.categorizeBox(1000, 35, 700, 300);
    std::cout << ret << std::endl;

    ret = solution.categorizeBox(200, 50, 800, 50);
    std::cout << ret << std::endl;
}
