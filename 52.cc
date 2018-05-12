/*
    题目：《剑指Offer-面试题54-表示数值的字符串》
        请实现一个函数用来判断字符串是否表示数值(包括整数和小数)
        例如，字符串 "+100"、"5e2"、"-123"、"3.1416" 和 "-1E-16" 都表示数值
        但是 "12e","1a3.14","1.2.3","+-5" 和 "12e+4.3" 都不是。
    思路：
        符号位
        小数点
        e之前和之后都必须有数字
        e后面还有数字，可能含符号位
*/

class Solution
{
  public:
    bool isNumeric(char *string)
    {
        if (string == nullptr)
            return false;

        if (*string == '+' || *string == '-')
            string++;

        if (*string == '\0') // 空字符串或只有一个符号位的字符串
            return false;

        bool numeric = true;

        scanDigit(&string); // 跳过接下来的连续数字位

        if (*string != '\0') // 字符串未到扫描至末尾
        {
            if (*string == '.') // 碰到小数点
            {
                string++; // 跳过小数
                scanDigit(&string);
                if (*string == 'e' || *string == 'E')
                    numeric = isExponential(&string);
            }
            else if (*string == 'e' || *string == 'E') // 碰到e或E
                numeric = isExponential(&string);
            else // 非法字符
                numeric = false;
        }

        return numeric && (*string == '\0');
    }

    // 从string位置开始跳过接下来的若干连续数字位
    int scanDigit(char **string)
    {
        int countDigit = 0;
        while (**string != '\0' && **string >= '0' && **string <= '9')
        {
            countDigit++;
            ++(*string);
        }
        return countDigit;
    }

    // 判断是否是有效的以10(e或E)为底指数
    bool isExponential(char **string)
    {
        if (**string != 'e' && **string != 'E')
            return false;

        ++(*string); // 出现了e或E，跳过

        if (**string == '+' || **string == '-') // 跳过e或E之后可能的符号位
            ++(*string);

        int countDigit = scanDigit(string); // 跳过若干连续数字位

        return **string == '\0' && countDigit != 0; // 若字符串扫描到末尾，说明是有效的指数
    }
};