class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int size = nums.size();
        if (size == 0) return 0;
        
        // auto iter = nums.cbegin();
        // auto iter2 = iter++;
        // while (iter != nums.cend() && iter2 != nums.cend()) {
        //     if (*iter2 == *iter) {
        //         iter = nums.erase(iter);
        //     } else {
        //         iter2 = iter++;
        //     }
        // }
        // return nums.size();
        
        
        // int i = 0, j = 1;
        // while ( j < size ) {
        //     if (nums[i] == nums[j]) {
        //         nums.erase(nums.begin() + j);
        //         --size;
        //     } else {
        //         ++j;
        //         ++i;
        //     }
        // }
        // return size;
        
        int i = 0, j = 1;
        while ( j < size ) {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
            ++j;
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return i + 1;
    }
};