#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int length = nums.size();
        if(nums.front() > 0 || nums.back() < 0 || length < 3)
            return result;
        for (int i = 0; i < length - 2; ++i) { //i是最左边元素
            // if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue; //排序后的数组如果出现相同的元素的话，以最左边的数为下界
    //         // for (int j = i + 1; j < length-1; ++j) {
    //         //     for (int k = j + 1; k < length; ++k) {
    //         //         if ((nums[i] + nums[j] + nums[k]) == 0) {
    //         //             // result.push_back(vector<int>{i, j, k});
    //         //             result.push_back(vector<int>{nums[i], nums[j], nums[k]});
    //         //             // j = length;
    //         //             k = length;
    //         //             while (nums[i] == nums[j]) {
    //         //                 ++j;
    //         //             }
    //         //         }
    //         //     }
    //         // }
    //         //--------
    //         // int left = i + 1, right= length - 1;//后面的两位数
    //         // int temp = -nums[i];
    //         // while (left < right)
    //         // {
    //         //     if (nums[left] + nums[right] == temp)
    //         //     {
    //         //         result.push_back(vector<int>{nums[i], nums[left], nums[right]});
    //         //         while (right > left && nums[right] == nums[right-1]) right--;
    //         //         while (right > left && nums[left] == nums[left+1]) left++;
    //         //         right--;
    //         //         left++;
    //         //     }
    //         //     else if (nums[left] + nums[right] < temp) left++;
    //         //     else right--;
    //         // }
    //         //--------
    //         if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {  // 跳过可能重复的答案
    //             int l = i + 1, r = length - 1, sum = 0 - nums[i];
    //             while (l < r) {
    //                 if (nums[l] + nums[r] == sum) {
    //                     result.push_back(vector<int>{nums[i], nums[l], nums[r]});
    //                     while (l < r && nums[l] == nums[l + 1]) l++;
    //                     while (l < r && nums[r] == nums[r - 1]) r--;
    //                     l++;
    //                     r--;
    //                 } else if (nums[l] + nums[r] < sum) {
    //                     while (l < r && nums[l] == nums[l + 1]) l++;   // 跳过重复值
    //                     l++;
    //                 } else {
    //                     while (l < r && nums[r] == nums[r - 1]) r--;
    //                     r--;
    //                 }
    //             }
    //         }
            //--------
            int left = i + 1, right = length - 1; //后面的两位数
            int temp = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == temp)
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left++;
                }
                else if (nums[left] + nums[right] < temp)
                    left++;
                else
                    right--;
            }
        }
        return result;
    }
};

int main()
{
    auto print = [](std::vector<std::vector<int>> result) {
        std::for_each(result.begin(), result.end(), [](const std::vector<int> &it) {
            std::for_each(it.begin(), it.end(), [](const int &it) {
                std::cout << it << ", ";
            });
            std::cout << std::endl;
        });
        std::cout << std::endl;
    };
    Solution sol;

    std::vector<int> a = {-1, 0, 1};
    print(sol.threeSum(a));

    std::vector<int> b = {-1, 0, 1, 2, -1, -4};
    print(sol.threeSum(b));

    return 0;
}