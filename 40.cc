/*
    题目：《剑指Offer-面试题41-和为s的两个数字 VS 和为s的连续正数序列》
        输出所有和为S的连续正数序列(至少含有两个数)
        序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
    思路：
        考虑用small和big分别代表序列的最小值和最大值
        small初始化为1，big初始化为2
        如果从small到big的序列的和大于sum，则从序列中去掉较小的值，也就是small增大1
        如果从small到big的序列的和小于sum，则应该新增一个数，即big下一个数，也就是big增大1，让这个序列包含更多的数字
        注意small有个上限，即(1+sum)/2，具体原因如下：
        （1）若small = (sum-1)/2，由于序列至少两个数，故big至少为(1+sum)/2，两者和为sum，刚刚好，故small可以取到(sum-1)/2
        （2）若small = (1+sum)/2，由于序列至少两个数，故big至少为(3+sum)/2，两者和为sum+2超过sum了，故small不能取到(sum+1)/2
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> result;
        vector<int> sequence;
        if (sum < 3)
            return result;

        int small = 1;
        int big = 2;
        int middle = (1 + sum) / 2; // small的上限
        int curSum = small + big;   // 初始序列只有两个数small和big

        while (small < middle)
        {
            if (curSum == sum)
                AddSequenceToResult(result, sequence, small, big);

            while (curSum > sum && small < middle)
            {
                curSum -= small;
                small++;
                if (curSum == sum)
                    AddSequenceToResult(result, sequence, small, big);
            }
            big++;
            curSum += big;
        }
        return result;
    }

    void AddSequenceToResult(vector<vector<int>> &result, vector<int> &sequence, int start, int end)
    {
        sequence.clear();
        for (int i = start; i <= end; i++)
            sequence.push_back(i);
        result.push_back(sequence);  // push_back进去的是个sequence的副本
        // 如把sequence定义成本函数的一个局部变量的话，函数结束后即被回收
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.FindContinuousSequence(5);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}