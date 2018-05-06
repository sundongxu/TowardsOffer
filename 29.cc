/*
    题目：《剑指Offer-面试题31-连续子数组的最大和》
        一个既有正数也有负数的数组
        求所有可能的连续子数组的和的最大值
        要求时间复杂度为O(n)
    思路：
        贪心或动规
*/

class Solution
{
  public:
    // 贪心法
    // int FindGreatestSumOfSubArray(vector<int> array)
    // {
    //     if (array.size() == 0)
    //         return 0;
    //     int maxSum = INT_MIN;
    //     int curSum = INT_MIN;
    //     for (int i = 0; i < array.size(); i++)
    //     {
    //         if (curSum <= 0) // 之前元素的当前和<0，对当前和不会有任何增益，故当前和从当前元素开始重新计算
    //             curSum = array[i];
    //         else // 之前元素的当前和>0，继续保留
    //             curSum += array[i];
    //         if (curSum > maxSum) // 当前和超过之前保存的最大和，更新最大和
    //             maxSum = curSum;
    //     }

    //     return maxSum;
    // }

    // 动规
    // 定义状态f[i]为以第i个数字结尾的子数组的最大和
    // 状态转移方程为：
    // f[i] = array[i]，i=0或f[i-1]<0
    // f[i] = f[i-1] + array[i]，i不等于0且f[i-1]>0
    // 返回值为数组f中最大值
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        const int n = array.size();
        if (n == 0)
            return 0;

        vector<int> f(n, INT_MIN);
        f[0] = array[0];

        for (int i = 1; i < n; i++)
        {
            if (f[i - 1] < 0)
                f[i] = array[i];
            else
                f[i] = f[i - 1] + array[i];
        }

        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (f[i] > maxSum)
                maxSum = f[i];
        }
        return maxSum;
    }
};