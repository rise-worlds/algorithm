class Solution {
private:
    static const int64_t int_max = INT_MAX;
    static const int64_t int_min = 2147483648;
public:
    int myAtoi(string str) {
        int64_t number = 0, temp = 0;
        bool plus = false, minus = false, isNum = false;
        int length = str.length();
        for (int i = 0; i < length; ++i) {
            char c = str.at(i);
            if (c == '-' || c == '+' || c == ' ') {
                if (plus || minus || isNum) {
                    break;
                }
                if (c == '-') {
                    minus = true;
                }
                if (c == '+') {
                    plus = true;
                }
            }
            else if ('0' <= c && c <= '9') {
                isNum = true;
                temp = temp * 10 + c - '0';
                if (minus && temp >= int_min) {
                    temp = INT_MIN;
                    break;
                }
                if (!minus && temp >= int_max) {
                    temp = INT_MAX;
                    break;
                }
            }
            else {
                break;
            }
        }
        number = minus ? -temp : temp;
        return number;
    }
};