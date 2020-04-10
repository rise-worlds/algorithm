#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (!m) return 0;
        if (!n) return -1;
        for (int i = 0; i < n - m + 1; ++i)
        {
            int j = 0;
            for( ; j < m; ++j)
            {
                if(haystack[i + j] !=  needle[j])
                    break;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};

int main(int argc, const char **argv)
{
    Solution solution;

    int count = solution.strStr("hello", "ll");
    std::cout << count << std::endl;
    int count = solution.strStr("hello", "a");
    std::cout << count << std::endl;
    int count = solution.strStr("hello world", "");
    std::cout << count << std::endl;
    int count = solution.strStr("", "");
    std::cout << count << std::endl;
    int count = solution.strStr("", "a");
    std::cout << count << std::endl;

    return 0;
}