#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void getNext(vector<int> &next, string t)
    {
        int j = 0, k = -1;
        next[0] = -1;
        while (j < t.length - 1)
        {
            if (k == -1 || t[j] == t[k])
            {
                j++;
                k++;
                if (t[j] == t[k]) //当两个字符相同时，就跳过
                    next[j] = next[k];
                else
                    next[j] = k;
            }
            else
                k = next[k]; //此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        int haystackSize = haystack.size(), needleSize = needle.size();
        if (!needleSize)
            return 0;
        if (!haystackSize)
            return -1;

        vector<int> next(needleSize + 1);
        getNext(next, needle);
        int i = 0, j = 0;
        while (i < haystackSize && j < needleSize)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
                j = next[j]; //j回退。。。
        }
        if (j >= needleSize)
            return (i - needleSize);
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
    int count = solution.strStr("aabaaaababaababaa", "bbbb");
    std::cout << count << std::endl;

    return 0;
}