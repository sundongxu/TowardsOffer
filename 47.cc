/*
    题目：《剑指Offer-面试题47-不用加减乘除做加法》
        不用加减乘除实现两个数求和
    思路：
        位运算
        （1）先算无进位情况下，两数之和(位异或)
        （2）再算进位(位与之后再左移一位)
        （3）返回第（1）步继续循环，直至进位为0，无进位之和就是两数和
*/

class Solution
{
  public:
    int Add(int num1, int num2)
    {
        int sum, carry;

        do
        {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;

            num1 = sum;
            num2 = carry;
        } while (num2 != 0);
        return sum;
    }
};