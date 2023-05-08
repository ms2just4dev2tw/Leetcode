
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>> &score, int k)
    {
        cmp.k = k;
        std::sort(score.begin(), score.end(), cmp);
        return score;
    }

    struct
    {
        int k = 0;
        bool operator()(const std::vector<int> &a, const std::vector<int> &b) const
        {
            return a[k] > b[k];
        }
    } cmp;

private:
    int k = 0;
};

int main(void)
{
    Solution solution;

    std::vector<std::vector<int>> score = {{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}};

    std::vector<std::vector<int>> sortScore = solution.sortTheStudents(score, 2);
    for (size_t i = 0; i < sortScore.size(); i++)
    {
        for (size_t j = 0; j < sortScore[i].size(); j++)
        {

            std::cout << sortScore[i][j] << ',';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    sortScore = solution.sortTheStudents(score, 1);
    for (size_t i = 0; i < sortScore.size(); i++)
    {
        for (size_t j = 0; j < sortScore[i].size(); j++)
        {

            std::cout << sortScore[i][j] << ',';
        }
        std::cout << std::endl;
    }
}