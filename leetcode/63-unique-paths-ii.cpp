class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m <= 0 || n <= 0)
        {
            return 0;
        }

        vector<vector<long>> dp(m, vector<long>(n, 0)); //创建大小为m*n的数组,使用long处理数值越界问题
        // 初始化
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else i = m;
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else i = n;
        }
        // 推导出 dp[m-1][n-1]
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};