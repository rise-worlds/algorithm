# 蓄水池储水量问题

### 描述

给出一个数组，每个数代表地面的高度，求地面可以存多少水。

### 解答

这是今天面试的时候被问的一个问题，之前没见到过这个题，当时第一思路是从前向后遍历，取出比左则大的下标，再接着向右计算，匆忙间被问几个问题后思路被带偏了。。。
后面回来的路上想了下，应该用二分比较或者双指针对比，回来在网上搜索了下，没想到是现成的一题。使用的是头尾指针加递归分段计算。

主要思路是数组下标0是左边界，最后一个下标是右边界，开始从前身后循环进行比较，找出第一和第二高。如果两堵墙紧邻者，就忽略它，否则算一下，如果墙之间没有任何其他的砖的情况下可以有多少水（只是一个乘法而已），然后扫描两堵墙之间有多少块砖，减去这个砖数就可以了。最后用递归处理。将两堵墙两侧到各自的左右边界再重新进行前面的操作（递归处理）。直到无墙可处理。
