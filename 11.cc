/*
    题目：
        数值的整数次方
    思路：
        边界条件判断：底数为0、指数为0或负数
        公式：
        当n为偶数时，a^n = a^n/2 * a^n/2
        当n为奇数时，a^n = a^((n-1)/2) * a^((n-1)/2) * a
*/
class Solution
{
  public:
    // 超内存
    // double Power(double base, int exponent)
    // {
    //     if (exponent == 0)
    //         return 1;
    //     if (exponent == 1)
    //         return base;
    //     double result = Power(base, exponent >> 1);
    //     result *= result;
    //     if (exponent & 0x1 == 1) // exponent是奇数
    //         result *= base;
    //     return result;
    // }

    double Power(double base, int exponent)
    {
        int p = abs(exponent);
        double r = 1.0;
        while (p) // p = 5 = 101(2次方) -> 10(4次方) -> 1(10次方) -> 0
        {
            if (p & 1) // p最后一位是1
                r *= base;
            base *= base; // 翻倍
            p >>= 1;      // p / 2
        }
        return (exponent > 0) ? r : 1 / r;
    }
};