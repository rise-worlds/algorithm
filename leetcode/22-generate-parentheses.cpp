#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		if (n == 0)
			return {};
		if (n == 1)
			return {"()"};

		// // 动态规划
		// vector<vector<string>> dp(n + 1);
		// dp[0] = {""};
		// dp[1] = {"()"};
		// for (int i = 2; i <= n; ++i)
		// {
		// 	for (int j = 0; j < i; ++j)
		// 	{
		// 		for (string p : dp[j])
		// 		{
		// 			for (string q : dp[i - j - 1])
		// 			{
		// 				string str = "(" + p + ")" + q;
		// 				dp[i].push_back(str);
		// 			}
		// 		}
		// 	}
		// }

		// return dp[n];

		// 回溯法
		vector<string> ans;
		backtrack(ans, "", 0, 0, n);
		return ans;
	}
	
private:
	void backtrack(vector<string>& ans, string cur, int open, int close, int max)
	{
		if (cur.length() == max * 2)
		{
			ans.push_back(cur);
			return;
		}
		if (open < max)
		{
			this->backtrack(ans, cur + "(", open + 1, close, max);
		}
		if (close < open)
		{
			backtrack(ans, cur + ")", open, close + 1, max);
		}
	}
};

int main(int argc, const char **argv)
{
	auto print_list = [](vector<string> list) { for_each(list.begin(), list.end(), [](const string &value) { std::cout << value << ", "; }); std::cout << std::endl; };

	Solution solution;
	print_list(solution.generateParenthesis(0));
	print_list(solution.generateParenthesis(1));
	print_list(solution.generateParenthesis(2));
	print_list(solution.generateParenthesis(3));
	print_list(solution.generateParenthesis(4));
	print_list(solution.generateParenthesis(5));
	print_list(solution.generateParenthesis(6));

	return 0;
}