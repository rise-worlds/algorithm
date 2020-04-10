#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> dicts = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        if (digits.empty())
            return {};

        // //solution 1
        // vector<string> result{""};
        // //从左到右增加每个按键
        // for (int j = 0; j < digits.size(); j++)
        // {
        //     //之前所有按键的情况组合数
        //     int len = result.size();
        //     for (int i = 0; i < len; i++)
        //     {
        //         //按键的每个情况，在之前结果上加上一个按键
        //         for (auto m:dicts[digits[j]])
        //         {
        //             result.push_back(result[i] + m);
        //         }
        //     }
        //     //删除上一步中残留的项
        //     result.erase(result.begin(), result.begin() + len);
        // }
        // return result;

        //solution 2
        auto wordsCount = 1;
        auto digitsLenght = digits.size();
        vector<int> baseNum(digitsLenght);
        for (int i = digitsLenght - 1; i >= 0; i--)
        {
            baseNum[i] = wordsCount;
            wordsCount *= dicts[digits[i]].size();
        }
        vector<string> result;
        char* word = new char[digitsLenght + 1];
        for (int num = 0; num < wordsCount; num++)
        {
            for (int i = 0; i < digitsLenght; i++)
            {
                auto letters = dicts[digits[i]];
                word[i] = letters[num / baseNum[i] % letters.size()];
            }
            result.push_back(string(word));
        }
        delete[] word;
        return result;
    }
};

int main() {
    Solution solution;
    {
        auto result = solution.letterCombinations("324");
        std::cout << result.size() << std::endl;
        std::for_each(result.begin(), result.end(), [](string str) { std::cout << str << ", "; });
        std::cout << std::endl;
    }
    {
        auto result = solution.letterCombinations("6789");
        std::cout << result.size() << std::endl;
        std::for_each(result.begin(), result.end(), [](string str) { std::cout << str << ", "; });
        std::cout << std::endl;
    }
}