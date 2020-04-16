#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int leftCur = m - 1;
        int rightCur = n - 1;
        int size = m + n - 1;
        while (leftCur >= 0 && rightCur >= 0) {
            if (nums1[leftCur] >= nums2[rightCur]) {
                nums1[size--] = nums1[leftCur--];
            }
            else {
                nums1[size--] = nums2[rightCur--];
            }
        }
        while (rightCur >= 0) {
            nums1[size--] = nums2[rightCur--];
        }
    }
};

int main()
{
    auto print = [](const std::vector<int>& result) {
        std::for_each(result.begin(), result.end(), [](const int& it) {
            std::cout << it << ", ";
            });
        std::cout << std::endl;
    };

    Solution sol;
    vector<int> a = { 1,2,3,0,0,0 }, b = { 2,5,6 };
    int sizeA = 3, sizeB = 3;
    sol.merge(a, sizeA, b, sizeB);
    print(a);

    a = { 2,4,6,8,10,0,0,0,0,0 };
    b = { 1,3,5,7,9 };
    sizeA = 5;
    sizeB = 5;
    sol.merge(a, sizeA, b, sizeB);
    print(a);

#if WIN32
    //system("pause");
    int t;
    std::cin >> t;
#endif
    
    return 0;
}
