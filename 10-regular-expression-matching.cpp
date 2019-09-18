#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
private:
    int len_s;
    int len_p;
public:
    bool isMatch(string s, string p) {
        string simp_p = string();
        simp_p = patten_simpfy(p);

        len_s = s.length();
        len_p = simp_p.length();

        return Match(s, simp_p, 0, 0);
    }

    string patten_simpfy(string p) {
        stringstream p_ss;

        for(string::iterator iter=p.begin(); iter<p.end(); iter++)
        {
            if (iter < p.end() && *(iter+1) == '*')
            {
                string p_s = p_ss.str();
                int len_p_s = p_s.length();

                if (len_p_s > 1)
                {
                    if (p_s[len_p_s - 2] == *iter && p_s[len_p_s - 1] == '*')
                    {
                        iter ++;
                        continue;
                    }
                }
                p_ss<<*iter;
            } else {
                p_ss<<*iter;
            }
        }

        return p_ss.str();
    }

    bool Match(string s, string p, int i_s, int i_p) {
        cout << "[" << i_s << "," << i_p << "]";
        if (i_p == len_p) // @ string s 的尾部
        {
            return i_s == len_s;
        }

        if (i_p < len_p - 1 && p[i_p + 1] == '*') // 如果p接下来两位是“_*”
        {
            if (i_s < len_s) {
                // 接下来两位“.*“或者”_*“
                if (p[i_p] == '.' || p[i_p] == s[i_s]) {
                    // Match(直接跳过“.*“或”_*“) || Match(利用“.*“或”_*“匹配i_s下一位)
                    return Match(s, p, i_s, i_p + 2) || Match(s, p, i_s + 1, i_p);
                }
            }

            // 不是”.*“ 或 patten的”_*“中的字符和s[i_s]不相同
            // 直接跳过“.*“或者”_*“
            return Match(s, p, i_s, i_p + 2);
        }

        if (i_s < len_s && i_p < len_p) // 最一般的情况
        {
            if (s[i_s] == p[i_p] || p[i_p] == '.') {
                return Match(s, p, i_s + 1, i_p + 1);
            }
        }

        return false;
    }
};

int main() {
    return 0;
}