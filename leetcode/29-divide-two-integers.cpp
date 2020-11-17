#include <algorithm>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int sign;
        if ((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0))
        {
            sign = 0;
        }
        else
        {
            sign = 1;
        }
        // 先全部变成正数，使用int64_t避免溢出
        int64_t a = abs(dividend), cmp = abs(divisor);
        int64_t res = 0, partial_sum = 1;
        int abs_divisor = cmp;
        if (a < cmp)
            return 0;
        while ((cmp << 1) < a)
        {
            cmp = cmp << 1;
            partial_sum = partial_sum << 1;
        }
        while (a >= abs_divisor)
        {
            a -= cmp;
            res += partial_sum;
            //cout << "a: " << a << " cmp: " << cmp << " partial_sum: " << partial_sum << endl;
            while (cmp > a)
            {
                cmp = cmp >> 1;
                partial_sum = partial_sum >> 1;
            }
        }
        if (sign == 1)
        {
            if (-res < INT_MIN)
                return INT_MAX;
            else
                return -res;
        }
        else
        {
            if (res > INT_MAX)
                return INT_MAX;
            else
                return res;
        }
    }
};