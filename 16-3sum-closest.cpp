#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closestSumValue = nums[0] + nums[1] + nums[2];
        int digit1_index, digit2_index, digit3_index; // 所选定的要求和的三个数的下标
        int max_digit1_index = nums.size() - 2;
        // 从左到遍历一遍数组，遍历到第i个元素时则认为该元素为第一个选定元素
        // 另外两个元素是从该元素的右边选择（即从第i+1到end之间选另外两个元素）。
        for (int i = 0; i < max_digit1_index; i++)
        {
            digit1_index = i;
            digit2_index = i + 1;
            digit3_index = nums.size() - 1;
            int tmp_sum = nums[digit1_index] + nums[digit2_index] + nums[digit3_index];
            // 第一个数是在当前时刻是指定不变了
            // 下面这个循环要做的事情就是确定在第一个数是nums[i]的情况下
            // 剩下两个数怎么选最合适
            while (digit2_index < digit3_index)
            {
                if (abs(tmp_sum - target) < abs(closestSumValue - target))
                    closestSumValue = tmp_sum;
                int difference = target - tmp_sum;
                if (difference == 0)
                    return target;
                if (difference > 0)
                {
                    // target比tmp_sum大，所以为了缩小差距那就应该增大tmp_sum
                    // 但是第3个数已经是最大了那就增大第2个数
                    digit2_index++;
                }
                else
                {
                    // target比tmp_sum小，所以为了缩小差距那就应该减小tmp_sum
                    // 但是第2个数已经是最小了那就减小第3个数
                    digit3_index--;
                }
                tmp_sum = nums[digit1_index] + nums[digit2_index] + nums[digit3_index];
            }
        }
        return closestSumValue;
    }
};