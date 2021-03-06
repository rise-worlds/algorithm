# 64. 最小路径和

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:
```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

## 题解

这题是 [62题](62-unique-paths.md) 的延申题，状态转移公式为`dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]`;

### 优化

根据公式 `dp[i][j] = dp[i-1][j] + dp[i][j-1]`，我们可以知道，当我们要计算第 `i` 行的值时，除了会用到第 `i - 1` 行外，其他第 `1` 至 第 `i-2` 行的值我们都是不需要用到的，因为计算某一行的时候，依赖的是左一结果和上一结果，所以我们存一行的记录，只要这一行包含当前元素的左一结果和上一结果即可。我们只需要用一个一维的 `dp[]` 来保存一行的历史记录就可以了。然后在计算的过程中，不断着更新 `dp[]` 的值。
所以在`dp[n]`这个数组里面，`dp[0]...dp[j-1]`是本一行的，`dp[j]...dp[n]`是上一行。
