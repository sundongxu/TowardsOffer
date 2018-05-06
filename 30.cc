/*
    题目：《剑指Offer-面试题32-从1到n这n个整数中1出现的个数》
        输入一个整数n，求出从1到n这n个整数中1出现的个数
    思路：
        每次去掉最高位做递归，递归的次数与位数相同，一个数字n有O(logn)位
        因此时间复杂度为O(logn)
*/

class Solution
{
  public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        char strN[50];
        sprintf(strN, "%d", n); // 将int转化成字符数组

        return NumberOf1(strN);
    }

    int NumberOf1(const char *strN)
    {
        if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
            return 0;

        int first = *strN - '0';
        unsigned int len = static_cast<unsigned int>(strlen(strN));

        if (len == 1 && first == 0) // strN = '0'
            return 0;

        if (len == 1 && first > 0) // strN = 'n'，1~n中有一个1
            return 1;

        // 假设strN是“21345”
        // numFirstDigit是数字10000~19999的第一个位是1的数字的个数
        int numFirstDigit = 0;
        if (first > 1) // 20000以上，则万位为1的数字个数为10的len-1次方，这里是len=5，len-1即4次方
            numFirstDigit = pow(10, len - 1);
        else if (first == 1) // 20000以内，则万位为1的数字的个数为n除去最高位后的的数字再加1
            numFirstDigit = atoi(strN + 1) + 1;

        // numOtherDigits是1346~21345除了第一位之外的数位中1的数目
        int numOtherDigits = first * (len - 1) * pow(10, len - 2);
        // numRecursive是1~1345中的1的数目
        int numRecursive = NumberOf1(strN + 1); // 递归，每次总数位减少1位，即分别在5位数中、4位数中、...、1位数中去找1的个数

        return numFirstDigit + numOtherDigits + numRecursive;
    }
};