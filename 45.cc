/*
    题目：《剑指Offer-面试题45-圆圈中最后剩下的数字》
        0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字
        求出这个圆圈里剩下的最后一个数字
    思路：
        约瑟夫环问题，两种思路
        思路一：环形链表模拟圆圈
        思路二：分析每次被删除的数字的规律，并直接计算圆圈中最后剩下的数字
        定义f(n,m)为每次在n个数字0,...,n-1中每次删除第m个数字最后剩下的数字
        递推公式如下：
        n = 1时，f(n,m) = 0
        n > 1时，f(n,m) = [f(n-1,m)+m]%n
*/

class Solution
{
  public:
    // 思路一：环形链表，时间复杂度O(mn)，空间复杂度O(n)
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;

        unsigned int i = 0;

        list<int> numbers; // 不能用vector，要支持任意位置元素的删除

        for (i = 0; i < n; i++)
            numbers.push_back(i);

        auto curIter = numbers.begin();

        while (numbers.size() > 1) // 环中还有超过1个人，继续游戏
        {
            for (int j = 1; j < m; j++)
            {
                curIter++;
                if (curIter == numbers.end())
                    curIter = numbers.begin(); // 到末尾了又回到头部
            }

            auto nextIter = ++curIter;
            if (nextIter == numbers.end())
                nextIter = numbers.begin();

            --curIter;
            numbers.erase(curIter); // 删除当前元素
            curIter = nextIter;     // 从被删除元素的下一个位置开始
        }
        return *curIter;
    }

    // 思路二：数学规律，时间复杂度O(n)，空间复杂度O(1)
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;

        int last = 0;
        for (int i = 2; i <= n; i++)
            last = (last + m) % i;

        return last;
    }
};