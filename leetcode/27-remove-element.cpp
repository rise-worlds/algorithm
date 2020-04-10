#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //双指针
        int k = 0, size = nums.size();
        for(int i = 0; i < size; ++ i)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                ++ k;
            }
        }
        return k;
    }
};

int main(int argc, const char **argv)
{
    Solution solution;
    vector<int> nums = {1,2,3,4,1,2,1,1,4,3,2,1};

    int count = solution.removeElement(nums, 1);

    for (size_t i = 0; i < count; i++)
    {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}