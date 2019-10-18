#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows <= 1)
            return s;
        int max_size = (len / numRows + (len % numRows ? 1 : 0)) * numRows;
        string ret(max_size, '\0');
        int step = 2 * numRows - 2;
        int cols = numRows - 1;
        for (int i = 0; i < len; i++)
        {
            int cur_step = i % step;
            if (((i / numRows) + 1) % 2) {
                ret[i / step + (i % step) * step] = s[i];
            } else {
                ret[i / step + ((1 + i) % step) * step] = s[i];
            }
        }
        return ret;
    }
};

// cl .\6-zigzag-conversion.cpp -o test.exe /Zi
int main()
{
    Solution solution;
    // std::cout << solution.convert("LEET", 3) << std::endl;
    // std::cout << solution.convert("LEETCO", 4) << std::endl;
    // std::cout << solution.convert("LEETCODE", 5) << std::endl;
    std::cout << solution.convert("ABCDEFGHIJKLMNOP", 3) << std::endl;
    // std::cout << solution.convert("ABCDEFGHIJKLMNOP", 4) << std::endl;

    return 0;
}