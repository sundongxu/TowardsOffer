/*
    题目：《剑指Offer-面试题41-和为s的两个数字 VS 和为s的连续正数序列》
        输入一个递增排序的数组和一个数字S，在数组中查找两个数
        使得它们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的
    思路：
        双指针，夹逼
        乘积最小的两个数，应该相距最远的两个数
        behind指针遍历找到的第一个符合条件的数和对应的ahead指向的数即为应返回的乘积最小的结果
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> result;
        // vector<pair<int, int>> resultPairs;
        if (array.size() < 2)
            return result;

        int ahead = array.size() - 1;
        int behind = 0;

        while (ahead > behind)
        {
            long long curSum = array[ahead] + array[behind];

            if (curSum == sum)
            {
                result.push_back(array[behind]);
                result.push_back(array[ahead]);
                // resultPairs.push_back(make_pair(array[behind], array[ahead])); // 从小到大
                // cout << array[behind] << " " << array[ahead] << endl;
                break;
                // ahead--;
                // behind++;
            }
            else if (curSum > sum)
                ahead--;
            else // curSum < sum
                behind++;
        }

        // sort(resultPairs.begin(), resultPairs.end(), compare);

        // result.push_back(resultPairs[0].first);
        // result.push_back(resultPairs[0].second);

        return result;
    }

    // static int compare(pair<int, int> &p1, pair<int, int> &p2)
    // {
    //     return p1.first * p1.second < p2.first * p2.second;
    // }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    for (auto n : s.FindNumbersWithSum(v, 5))
        cout << n;
    return 0;
}