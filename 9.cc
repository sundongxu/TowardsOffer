/*
    题目：
        用2*1的瓷砖铺满2*N的地板，总共多少种铺法？
    思路：
        动态规划 + 滚动数组，实际还是斐波那契数列
*/
class Solution
{
  public:
    int rectCover(int number)
    {
        vector<int> f(3, 0);
        f[0] = 0;
        f[1] = 1;
        f[2] = 2;

        for (int i = 3; i <= number; i++)
            f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
        return f[number % 3];
    }
};