/*
    题目：《剑指Offer-面试题34-丑数》
        把只包含因子2、3和5的数称作丑数（Ugly Number）
        例如6、8都是丑数，但14不是，因为它包含因子7
        习惯上我们把1当做是第一个丑数
        求按从小到大的顺序的第N个丑数
    思路：
        创建一个数组，存储排好序的丑数，每个丑数都是前面的丑数乘以2、3或者5得到的
        假设数组中已经有若干排好序的丑数，并且最大的那个丑数记作M
        接下来分析如何生成下一个丑数，该丑数一定是前面某一个丑数乘以2、3或者5的结果
        所以先考虑把已有的每个丑数乘以2，在乘以2的时候，能得到若干个小于或等于M的结果
        由于是按顺序生成的，小于或者等于M的丑数肯定已经在数组中了，不需再次考虑
        还会得到若干大于M的结果，但我们只需要第一个大于M的结果，因为我们希望丑数是按从小到大顺序生成的
        其它的更大的结果以后再说
        把得到的第一个乘以2后大于M的结果记为M2，同样，把已有的每一个丑数乘以3和5
        能得到第一个大于M的结果M3和M5，那么下一个丑数就是M2、M3和M5中最小的一个
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;

        int *uglyNumbers = new int[index];
        uglyNumbers[0] = 1;
        int nextUglyIndex = 1;

        int *uglyNumbersMultiply2 = uglyNumbers;
        int *uglyNumbersMultiply3 = uglyNumbers;
        int *uglyNumbersMultiply5 = uglyNumbers;

        while (nextUglyIndex < index)
        {
            int min = Min(*uglyNumbersMultiply2 * 2, *uglyNumbersMultiply3 * 3, *uglyNumbersMultiply5 * 5);
            uglyNumbers[nextUglyIndex] = min;

            while (*uglyNumbersMultiply2 * 2 <= uglyNumbers[nextUglyIndex])
                uglyNumbersMultiply2++;
            while (*uglyNumbersMultiply3 * 3 <= uglyNumbers[nextUglyIndex])
                uglyNumbersMultiply3++;
            while (*uglyNumbersMultiply5 * 5 <= uglyNumbers[nextUglyIndex])
                uglyNumbersMultiply5++;
            nextUglyIndex++;
        }

        return uglyNumbers[nextUglyIndex - 1];
    }

    int Min(int n1, int n2, int n3)
    {
        int min = (n1 < n2) ? n1 : n2;
        min = (min < n3) ? min : n3;
        return min;
    }
};

int main()
{
    Solution s;
    cout << s.GetUglyNumber_Solution(10) << endl;
    return 0;
}