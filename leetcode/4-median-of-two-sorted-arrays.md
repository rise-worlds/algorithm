# 4. 寻找两个有序数组的中位数

## 题目描述

给定两个大小为 m 和 n 的有序数组 `nums1` 和 `nums2`。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 $O(log(m + n))$。

你可以假设 `nums1` 和 `nums2` 不会同时为空。

示例 1:

    nums1 = [1, 3]
    nums2 = [2]

    则中位数是 2.0

示例 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    则中位数是 (2 + 3)/2 = 2.5

## 题解

为了解决这个问题，我们需要理解 “中位数的作用是什么”。在统计学中，中位数被用来：
将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。

这其中又分为偶数组和奇数组：

奇数组: [2 3 5] 对应的中位数为3

偶数组: [1 4 7 9] 对应的中位数为 (4 + 7) /2 = 5.5

这道题如果时间复杂度没有限定在 $O(log(m+n))$，我们可以用 $O(m+n)$ 的算法解决，用两个指针分别指向两个数组，比较指针下的元素大小，一共移动次数为 `(m + n + 1)/2`，便是中位数。

首先，我们理解什么中位数：指的是该数左右个数相等。

比如：`odd : [1,| 2 |, 3]`，`2` 就是这个数组的中位数，左右两边都只要 1 位；
`even: [1,| 2, 3 |, 4]`，`2, 3` 就是这个数组的中位数，左右两边 1 位；

那么，现在我们有两个数组：

`num1: [a1,a2,a3,...an]`
`nums2: [b1,b2,b3,...bn]`
`[nums1[:left1],nums2[:left2] | nums1[left1:], nums2[left2:]]`

只要保证左右两边 个数 相同，中位数就在 | 这个边界旁边产生。

如何找边界值，我们可以用二分法，我们先确定 num1 取 m1 个数的左半边，那么 num2 取 m2 = (m+n+1)/2 - m1 的左半边，找到合适的 m1，就用二分法找。

当 `[ [a1],[b1,b2,b3] | [a2,..an],[b4,...bn] ]`

我们只需要比较 b3 和 a2 的关系的大小，就可以知道这种分法是不是准确的！

例如：我们令：

`nums1 = [-1,1,3,5,7,9]`
`nums2 = [2,4,6,8,10,12,14,16]`

当 `m1 = 4, m2 = 3` ,它的中位数就是`median = (num1[m1] + num2[m2])/2`

时间复杂度：$O(log(min(m,n)))$