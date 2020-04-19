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

        vector<vector<int>> dp(m, vector<int>(n)); //创建大小为m*n的数组
        // 初始化
        dp[0][0] = grid[0][0]; //防止grid[0][0]重复加
        // 初始化最左边的列
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // 初始化最上边的行
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        // 推导出 dp[m-1][n-1]
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};