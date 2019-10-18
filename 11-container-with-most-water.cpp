#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // int l = 0, r = height.size() - 1;
        // int square, max = 0;
        // while (r - l >= 1) {
        //     if (height[l] > height[r]) {
        //         square = height[r] * (r - l);
        //         r--;
        //     } else {
        //         square = height[l] * (r - l);
        //         l++;
        //     }
        //     max = std::max(square, max);
        // }
        // return max;

        int l = 0, r = height.size() - 1;
        if (r <= 0) return 0;
        int max = 0;
        while (l < r) {
            int square = std::min(height[l], height[r]) * (r - l);
            max = std::max(square, max);
            if (height[l] <= height[r]) ++l;
            else --r;
        }
        return max;
    }
};


// cl .\11-container-with-most-water.cpp -o test.exe /Zi
int main()
{
    Solution solution;
    std::cout << solution.maxArea({8,6,2,5,4,8}) << std::endl;
    std::cout << solution.maxArea({1,8,6,2,4,7,2}) << std::endl;
    std::cout << solution.maxArea({1,8,3,2,5,4,9,3,7}) << std::endl;

    return 0;
}