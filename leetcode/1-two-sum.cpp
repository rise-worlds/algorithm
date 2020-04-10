#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        size_t i, j, length = nums.size();
        for (i = 0; i < length; ++i) {
            for (j = i + 1; j < length; ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    i = j = length;
                    break;
                }
            }
        }
        return result;
    }
};