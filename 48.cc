/*
    题目：《剑指Offer-面试题49-把字符串转换成整数》
        将一个字符串转换成一个整数
        要求不能使用字符串转换整数的库函数atoi
        数值为0或者字符串不是一个合法的数值则返回0

    思路：
        难点在于边界条件的确定，即什么才是合法字符？或者换个角度，哪些字符串属于非法？
        需要考虑如下几个测试用例：
        （1）空串
        （2）第一个字符为符号位，正、负数
        （3）整形溢出(long long存中间结果)，最大INT_MAX和最小INT_MIN
        （4）每一个字符都是有效数字

        出错时返回0，但是需要设置额外标志位标识不同的用例
*/

enum Status
{
    kValid = 0, // 合法输入
    kInvalid    // 非法输入
};
int g_nStatus = kValid;

class Solution
{
  public:
    int StrToInt(string str)
    {
        g_nStatus = kInvalid;  // 非法输入标志
        long long num = 0;
        int index = 0;
        if (str.size() != 0) // 非空串
        {
            bool minus = false;
            if (str[0] == '-')
            {
                minus = true;
                index++;
            }
            else if (str[0] == '+')
            {
                index++;
            }
            if (str.size() > 1) // 除符号位外还有有效字符
                num = StrToIntCore(str, index, minus);
        }
        return (int)num;
    }

    long long StrToIntCore(string &str, int index, bool minus)
    {
        long long num = 0;
        while (index < str.size())
        {
            if (str[index] >= '0' && str[index] <= '9')
            {
                num = num * 10 + str[index] - '0';
                if (!minus && num > INT_MAX || minus && num < INT_MIN)
                {
                    num = 0;  
                    break;  // 数字溢出，string表示的整型数存在long long中，且已超过int的表示范围，非法输入
                }
                index++;
            }
            else
            {
                num = 0;
                break;  // 出现了非数字字符，非法输入
            }
        }
        if (index == str.size())  // 输入合法
            g_nStatus = kValid;

        return minus ? -num : num;
    }
};