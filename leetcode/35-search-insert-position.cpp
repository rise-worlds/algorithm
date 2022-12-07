class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        } else if (size == 1) {
            if (nums[0] < target) {
                return 1;
            }
            return 0;
        } else if (target < nums[0]) {
            return 0;
        } else {
            size -= 1;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] < target && target <= nums[i+1]) {
                return i + 1;
            } else if (nums[i] <= target && target < nums[i+1]) {
                return i;
            }
        }
        return size + 1;
    }
};
