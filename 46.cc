/*
    题目：《剑指Offer-面试题46-求1+2+...+n》
        求1~n之和，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句(A?B:C)
    思路：
        思路一：构造函数
        思路二：虚函数
        思路三：函数指针
*/

// 思路一：构造函数
class Temp
{
  public:
    Temp()
    {
        ++N;
        sum += N;
    }

    static void Reset()
    {
        N = 0;
        Sum = 0;
    }

    static unsigned int GetSum()
    {
        return Sum;
    }

  private:
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

class Solution
{
  public:
    int Sum_Solution(int n)
    {
        Temp::Reset();

        Temp *a = new Temp[n];
        delete[] a;
        a = nullptr;

        return Temp::GetSum();
    }
};

// 思路二：虚函数
class A;
A *Array[2];

class A
{
  public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B : public A
{
  public:
    unsigned int Sum(unsigned int n)
    {
        return Array[!n]->Sum(n - 1) + n;
    }
};

class Solution
{
  public:
    int Sum_Solution(int n)
    {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;

        int value = Array[1]->Sum(n);
        return value;
    }
};

// 思路三：函数指针
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution_Teminator(unsigned int n)
{
    return 0;
}

class Solution
{
  public:
    static unsigned int Sum_Solution(unsigned int n)
    {
        static fun f[2] = {Solution_Teminator, Sum_Solution};
        return n + f[!!n](n - 1);
    }
};