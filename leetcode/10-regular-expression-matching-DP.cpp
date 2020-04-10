#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1 && p[j - 1] == '*')
                {
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                }
                else if (i > 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    cout << "'aa', 'a' : " << solution.isMatch("aa", "a") << endl;
    return 0;
}