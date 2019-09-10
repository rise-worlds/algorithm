class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        set<vector<int>> result;
        // 暴力遍历法
        // for (int i = 0; i < size - 3; ++i) {
        //     if (nums[i] > target && target > 0) break;
        //     for (int j = i + 1; j < size - 2; ++j) {
        //         for (int k = j + 1; k < size - 1; ++k) {
        //             for (int l = k + 1; l < size - 0; ++l) {
        //                 if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
        //                     result.insert({nums[i], nums[j], nums[k], nums[l]});
        //                 }
        //             }
        //         }
        //     }
        // }
        
        // 双指针法
        for(int i = 0; i < size - 3; ++i) {
            if (nums[i] > target && target > 0) break;
            for (int j = i + 1; j < size - 2; ++j) {
                int l = j + 1;
                int r = size - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        ++l;
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                        --r;
                    else  {
                        result.insert({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                    }
                }
            }
        }
        
        return vector<vector<int>>{result.begin(), result.end()};
    }
};