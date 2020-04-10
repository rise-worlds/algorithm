#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution
{
private:
    string preProcess(string s)
    {
        int size = s.length();
        if (size == 0)
        {
            return "^$";
        }
        string ret(s.length() * 2 + 3, '#');
        ret[0] = '^';
        for (int i = 0; i < size; ++i)
        {
            ret[i * 2 + 2] = s[i];
        }
        ret[ret.length() - 1] = '$';
        return ret;
    }

    // 马拉车算法
public:
    string longestPalindrome2(string s)
    {
        string str = preProcess(s);
        std::cout << str << std::endl;
        size_t size = str.length();
        vector<int> P(size, 0);
        int C = 0, R = 0;
        for (int i = 1; i < size - 1; i++)
        {
            int i_mirror = 2 * C - i;
            if (R > i)
            {
                P[i] = std::min(R - i, P[i_mirror]); // 防止超出 R
            }
            else
            {
                P[i] = 0; // 等于 R 的情况
            }

            // 碰到之前讲的三种情况时候，需要利用中心扩展法
            while (str.at(i + 1 + P[i]) == str.at(i - 1 - P[i]))
            {
                P[i]++;
            }

            // 判断是否需要更新 R
            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }

        // 找出 P 的最大值
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < size - 1; i++)
        {
            if (P[i] > maxLen)
            {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2; //最开始讲的求原字符串下标
        return s.substr(start, maxLen);

        // string str(s.length() * 2 + 2, '#');
        // str[0] = '$';
        // for (int i = s.length(); i--; )
        //     str[i * 2 + 2] = s[i];
        // vector<int> lens(str.length(), 0);
        // int center = 0, r = 0;
        // for (int i = 1, mx = 0, id = 0; i < str.length(); ++i)
        // {
        //     lens[i] = mx > i ? min(lens[id * 2 - i], mx - i) : 1;
        //     for (; str[i - lens[i]] == str[i + lens[i]]; ++lens[i])
        //         ;
        //     if (mx < i + lens[i])
        //     {
        //         mx = i + lens[i];
        //         id = i;
        //     }
        //     if (r < lens[i])
        //     {
        //         r = lens[i];
        //         center = i;
        //     }
        // }
        // return s.substr((center - r) / 2, r - 1);
    }
};

int main()
{
    Solution solution;
    std::cout << solution.longestPalindrome2("babad") << std::endl;
    std::cout << solution.longestPalindrome2("cbbd") << std::endl;
}