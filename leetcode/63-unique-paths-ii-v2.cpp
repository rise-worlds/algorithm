class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m <= 0 || n <= 0)
        {
            return 0;
        }

        vector<long> dp(n, 0); // 使用long处理数值越界问题
        // 初始化
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0) dp[i] = 1;
            else i = n;
        }
        // 推导出 dp[n-1]
        for (int i = 1; i < m; i++)
        {
            // 第 i 行第 0 列的初始值
            dp[0] = (obstacleGrid[i][0] == 0) ? dp[0] : 0;
            for (int j = 1; j < n; j++)
            {
                dp[j] = (obstacleGrid[i][j] == 0) ? dp[j - 1] + dp[j] : 0;
            }
        }
        return dp[n - 1];
    }
};