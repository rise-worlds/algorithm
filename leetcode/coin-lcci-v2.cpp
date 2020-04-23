class Solution {
    static constexpr int mod = 1000000007;
public:
    int waysToChange(int n) {
        int ans = 0;
        for (int i = 0; i * 25 <= n; ++i) {
            int rest = n - i * 25;
            int a = rest / 10;
            int b = rest % 10 / 5;
            ans = (ans + (long long)(a + 1) * (a + b + 1) % mod) % mod;
        }
        return ans;
    }
};