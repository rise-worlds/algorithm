#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int pos1 = 0, pos2 = matrix.size() - 1;
        int add = 0, temp = 0;
        while (pos1 < pos2)
        {
            add = 0;
            while (add < pos2 - pos1)
            {
                // 顺时针向右交换 4个面上的点
                temp = matrix[pos2 - add][pos1];
                matrix[pos2 - add][pos1] = matrix[pos2][pos2 - add];
                matrix[pos2][pos2 - add] = matrix[pos1 + add][pos2];
                matrix[pos1 + add][pos2] = matrix[pos1][pos1 + add];
                matrix[pos1][pos1 + add] = temp;
                // std::swap(matrix[pos2 - add][pos1], matrix[pos2][pos2 - add]);
                // std::swap(matrix[pos2][pos2 - add], matrix[pos1 + add][pos2]);
                // std::swap(matrix[pos1 + add][pos2], matrix[pos1][pos1 + add]);
                ++add;
            }
            // 内移一层
            ++pos1;
            // 长度减一
            --pos2;
        }
    }
};
