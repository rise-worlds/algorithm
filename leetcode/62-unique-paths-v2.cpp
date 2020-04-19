class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0)
        {
            return 0;
        }
        if (m == 1 || n == 1)
        {
            return 1;
        }

        vector<int> dp(n);
        // 初始化
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }
        // 推导出 dp[m-1][n-1]
        for (int i = 1; i < m; i++)
        {
            // 第 i 行第 0 列的初始值
            dp[0] = 1;
            for (int j = 1; j < n; j++)
            {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n - 1];
    }
};