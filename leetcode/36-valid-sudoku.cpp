class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        array<array<int, 9>, 9> rows = {0};
        array<array<int, 9>, 9> columns = {0};
        array<array<int, 9>, 9> boxes = {0};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if ((++rows[board[i][j] - '1'][i] > 1) ||
                        (++columns[board[i][j] - '1'][j] > 1) ||
                        (++boxes[board[i][j] - '1'][(i / 3) * 3 + j / 3] > 1))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};