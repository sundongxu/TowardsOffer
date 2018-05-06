/*
    题目：《剑指Offer-面试题9-斐波那契数列》
        斐波那契数列第n项
    思路：
        非递归实现，记录已经计算过的项，避免重复运算
*/
#include <iostream>
using namespace std;

class Solution
{
  public:
    // 递归太慢了
    // int Fibonacci(int n)
    // {
    //     if (n <= 0)
    //         return 0;
    //     if (n == 1)
    //         return 1;
    //     return Fibonacci(n - 1) + Fibonacci(n - 2);
    // }
    
    // 非递归实现斐波那契数列
    // 除去重复计算
    int Fibonacci(int n)
    {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        
        long long fibMinusOne = 1;
        long long fibMinusTwo = 0;
        long long fibN = 0;
        for(int i = 2; i <= n; i++)
        {
            fibN = fibMinusOne + fibMinusTwo;
            fibMinusTwo = fibMinusOne;
            fibMinusOne = fibN;
        }
        return fibN;
    }
};

int main()
{
    int n = 0;
    while (cin >> n)
        cout << Solution().Fibonacci(n) << endl;
}