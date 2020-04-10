#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p[0] == '*') return -1;
        // 一、 构建有限状态自动机
        // 用一个数据结构存储状态机，每个状态用数字表示
        // 1. 状态的数量等于模式串p中非`*`字符的数量+1，最多有p.size()+1个状态；用map来表示状态和状态的连接关系
        // 2. 每个状态通过某个字符，可以转换到多个状态，用集合来存储
        vector<unordered_map<char, set<int>>> states(p.size()+1);
        
        // 记录所有终止状态
        set<int> endStates;
        
        // 记录当前状态
        int state(0);
        for (int i(0); i < p.size(); ++i) {
            // 模式串当前字符p[i]为'*'，则代表前一个字符p[i-1]字符可以重复多次->自动机从当前状态，通过p[i-1]回到q当前状态。
            if (p[i] == '*'){
                states[state][p[i-1]].insert(state);
            }
            else{
                // p[i]不为'*'，自动机从当前状态，通过当前字符p[i]切换到下一个状态
                states[state][p[i]].insert(state+1);
                
                // 1. 如果p[i+1]为'*'，表示自动机从当前状态state，通过p[i+1]的后一个字符p[i+2]，到达状态state+2(= state+1+1)；
                // 2. 如果1.的条件满足，我们接着检查p[i+3](= p[i+1+1*2])是否为‘*’，如果是，代表当前状态可以通过p[i+4](= p[i+2+1*2])，直接到达状态state + 3(= state+2+1);
                // 3. 如果上一步条件满足，则重复检查p[i+1+count*2]是否为'*'，如果是，则代表当前状态可以通过p[i+2+count*2]，直接到达状态state+2+count;
                // 特别地，如果p[i+1+count*2]为'*'，且i+1+count*2 == p.size()-1，那么代表当前状态可以作为终止状态。
                int count(0);
                while (i + 1 + count * 2 < p.size() && p[i + 1 + count * 2] == '*'){
                    if (i + 2 + count * 2 < p.size()) states[state][p[i + 2 + count * 2]].insert(state + 2 + count);
                    else endStates.insert(state);
                    ++count;
                }
                ++state;
            }
        }
        // 最后一个状态必然为终止状态
        endStates.insert(state);
        
        // 二、匹配有限状态自动机
        set<int> nowStates; // 记录当前遍历中，可能到达的所有状态；
        set<int> preStates; // 上一次遍历中，可能到达的所有状态；
        preStates.insert(0);    // 我们从初始状态开始遍历
        for (int i(0); i < s.size(); ++i){
            for (auto j: preStates){    // 枚举上一步s可能到达的所有状态
                for (auto tranState: states[j][s[i]]){   // 如果上一步的状态通过当前字符s[i]可以发生转移，则将可能到达的所有状态加入到nowStates中
                    nowStates.insert(tranState);
                }
                for (auto tranState: states[j]['.']){    // 如果上一步的状态可以通过任意字符进行转移，则将可能到达的所有状态加入到nowStates中
                    nowStates.insert(tranState);
                }
            }
            if (nowStates.empty()) {
                return false;
            } else {
                preStates = nowStates;  // 为下一次遍历更新状态
                nowStates.clear();
            }
        }
        
        // 遍历结束。检查所有可能到达的状态，如果其中包含了终止状态，则代表匹配成功，否则匹配失败
        for (auto e: endStates) {
            if (preStates.count(e)) return true;
        }
        
        return false;
    }
};

int main() {
    return 0;
}