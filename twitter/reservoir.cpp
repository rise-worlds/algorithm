#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class reservoir
{
public:
    int64_t getSum(const vector<int>& data)
    {
        return sum(data, 0, data.size() - 1);
    }

private:
    int64_t sum(const vector<int>& data, int left, int right)
    {
        int64_t result = 0;
        // first：left和right之间最高的墙
        // second：left和right之间第二高的墙
        int first = 0, second = 0;
        // firstIndex：第一高的墙在data中的索引
        // secondIndex：第二高的墙在data中的索引
        int firstIndex = 0, secondIndex = 0;
        // 两堵墙必须至少有一堵墙的距离
        if (right - left <= 1)
            return result;
        // 开始获取第一高和第二高墙的砖数
        for (int i = left; i <= right; i++) {
            if (data[i] > first) {
                second = first;
                secondIndex = firstIndex;
                first = data[i];
                firstIndex = i;
            } else if (data[i] > second) {
                second = data[i];
                secondIndex = i;
            }
        }

        // 获取左侧墙的索引
        int leftIndex = std::min(firstIndex, secondIndex);
        // 获取右侧墙的索引
        int rightIndex = std::max(firstIndex, secondIndex);
        // 计算距离
        int distance = rightIndex - leftIndex;
        // 如果第一高的墙和第二高的墙之间至少有一堵墙，那么开始计算这两堵墙之间可以放多少个单位的水
        if (distance > 1) {
            result = result + (distance - 1) * second;
            // 减去这两堵墙之间的砖数
            for (int i = leftIndex + 1; i < rightIndex; i++) {
                result -= data[i];
            }
        }

        // 开始递归处理左侧墙距离开始位置能放多少水
        result += sum(data, left, leftIndex);
        // 开始递归处理右侧墙距离结束位置能放多少水
        result += sum(data, rightIndex, right);
    }
};