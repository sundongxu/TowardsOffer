/*
    题目：
        青蛙一次可以跳上1级台阶，也可以跳上两级，求其跳上n级台阶的跳法数
    思路：
        动态规划 + 滚动数组，实际就是斐波那契数列
*/
class Solution
{
public:
  int jumpFloor(int number)
  {
    // 设状态f[n]为跳上n级台阶的跳法数
    // 状态转移方程为：f[n] = f[n - 1] + f[n - 2]
    if (number == 0)
      return 0;
    if (number == 1)
      return 1;
    if (number == 2)
      return 2;
    vector<int> f(3, 0);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= number; i++)
      f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
    return f[number % 3];
  }
};