class Solution {
    static constexpr mod = 1000000007;
    static constexpr array<int, 4> coins = {1, 5, 10, 25};
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        // dp方程：dp[i] += dp[i - coin];
        for (int coin : coins) {
            for (int i = coin; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i - coin]) % mod;
            }
        }
        
        return dp[n];
    }
};