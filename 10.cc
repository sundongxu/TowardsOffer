/*
    题目：
        求整数n的二进制表示中1的个数
    思路：
        位运算
        (n-1) & n 可以去掉n的最右边的1
*/
class Solution
{
  public:
    // 超时
    // int NumberOf1(int n)
    // {
    //     if (n == 0)
    //         return 0;
    //     int count = 0;
    //     bool sign = n > 0 ? true : false;
    //     if (!sign)
    //         n = -n;
    //     while (n != 0)
    //     {
    //         if (n & 1)
    //             count++;
    //         n = n >> 1;
    //     }
    //     if (!sign)
    //         count++;
    //     return count;
    // }

    // 常规
    // int NumberOf1(int n)
    // {
    //     if (n == 0)
    //         return 0;
    //     int flag = 1;
    //     int count = 0;
    //     while (flag)
    //     {
    //         if (n & flag)
    //             count++;
    //         flag = flag << 1;
    //     }
    //     return count;
    // }

    // 最优
    // 一个整数减去1，都是把最右边的1变成0
    // 如果其右边还有0，则把所有的0都变成1
    // 而它左边所有位保持不变
    // 故(n-1) & n可以去掉n的最后也就是最右边的1
    // 原整数有多少个1循环就执行多少次
    int NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};