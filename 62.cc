/*
    题目：《剑指Offer-面试题64-数据流中的中位数》
        如何得到一个数据流中的中位数？
        如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值
        如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
    思路：
        将数据流分为两段，每当当前数字个数为奇数，新到来元素插入到最大堆中，当前数字个数为偶数，则将新到来元素插入到最小堆中(两个堆数字个数的平衡，相差不超过1)
        前面半段用最大堆存储，每次可以O(1)时间从最大堆即前半部分中取出最大值，插入新元素效率为O(logn)
        后面半段用最小堆存储，每次可以O(1)时间从最小堆即后半部分中取出最小值，插入新元素效率为O(logn)

        若数据流总个数为奇数，则中位数为最小堆中的最小元素
        若数据流总个数为偶数，则中位数为最大堆中的最大元素与最小堆中的最小元素的平均数

        优先队列仅支持top/pop/push/emplace操作，不支持front/back
*/

#include <queue>
using namespace std;

class Solution
{
  public:
    void Insert(int num)
    {
        if (((min.size() + max.size()) & 1) == 0)
        {
            // 当前数字总个数为偶数，新增数字应该插入到前半部分的最小堆中
            if (max.size() > 0 && num < max.top())
            {
                // 这个应该插入最小堆(插入之前的总个数为偶数)的数却比最大堆的最大元素还要小
                // 该数字应插入最大堆，并将最大堆的最大元素插入最小堆，保证数目平衡(相差1)
                max.push(num);
                num = max.top();
                max.pop();
            }
            min.push(num);
        }
        else
        {
            if (max.size() > 0 && num > min.top())
            {
                min.push(num);
                num = min.top();
                min.pop();
            }
            max.push(num);
        }
    }

    double GetMedian()
    {
        if ((max.size() + min.size()) == 0)
            return -1;
        if (((max.size() + min.size()) & 1) == 0)
            return (double)(max.top() + min.top()) / 2;
        else
            return (double)(min.top());
    }

  private:
    priority_queue<int, vector<int>, less<int>> max;    // 前半部分用最大堆
    priority_queue<int, vector<int>, greater<int>> min; // 后半部分用最小堆
};