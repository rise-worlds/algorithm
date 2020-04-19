class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m <= 0 || n <= 0)
        {
            return 0;
        }

        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = (i == 0 ? 0 : dp[i - 1]) + grid[0][i]; // 初始化第一行
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    dp[j] = dp[j] + grid[i][j];
                }
                else
                {
                    dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j]; // 左边和上边，哪一个小就从哪里走过来。
                }
            }
        }
        return dp[n - 1];
    }
};