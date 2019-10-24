#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        auto mapping = map<char, char>{{']', '['}, {'}', '{'}, {')', '('}};
        auto size = s.length();
        if (size % 2 != 0)
        {
            return false;
        }

        auto lifo = stack<char>();
        for (auto value : s)
        {
            auto iter = mapping.find(value);
            if (iter == mapping.end())
            {
                lifo.push(value);
            }
            else
            {
                if (lifo.empty() || iter->second != lifo.top())
                {
                    return false;
                }
                lifo.pop();
            }
        }

        return lifo.empty();
    }
};

int main(int argc, const char **argv)
{
    Solution solution;
    std::cout << std::boolalpha << solution.isValid("(") << std::endl;
    std::cout << std::boolalpha << solution.isValid("((") << std::endl;
    std::cout << std::boolalpha << solution.isValid("()") << std::endl;
    std::cout << std::boolalpha << solution.isValid("()[]{}") << std::endl;
    std::cout << std::boolalpha << solution.isValid("(]") << std::endl;
    std::cout << std::boolalpha << solution.isValid("([)]") << std::endl;
    std::cout << std::boolalpha << solution.isValid("({[]})") << std::endl;

    return 0;
}