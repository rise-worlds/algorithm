class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int result = 0;
        for (int i = 0; temp != 0; ++i) {
            int pop = temp % 10;
            temp /= 10;
            if (result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)) //判断上限
            	return 0;
            if (result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)) //判断下限
            	return 0;
            result = result * 10 + pop;
        }
        return result;
    }
};