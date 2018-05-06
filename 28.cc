/*
    题目：《剑指Offer-面试题30-最小的k个数》
        输入n个整数，找出其中最小的k个数
    思路：
        思路一：Partition找第k小的数，即划分后排在位置k-1上的数，包括它在内左边的就是最小的k个数，前提是可以修改源数组
        思路二：维护一个元素个数为k的最大堆(优先队列)
        每次插入新元素都将其与堆顶元素比较，若大于堆顶元素直接丢弃，小于堆顶元素则插入，重新调整堆后，删除堆顶元素
        适合处理海量数据，复杂度为O(nlogk)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int Partition(vector<int> &numbers, int start, int end)
    {
        while (start < end)
        {
            while (start < end && numbers[start] <= numbers[end])
                end--;
            swap(numbers[start], numbers[end]);
            while (start < end && numbers[start] <= numbers[end])
                start++;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }

    // 思路一：Partition
    // vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    // {
    //     vector<int> result;
    //     const int size = input.size();
    //     if (size <= 0 || k > input.size() || k <= 0)
    //         return result;

    //     int start = 0, end = size - 1;
    //     int pivot = Partition(input, start, end);
    //     while (pivot != k - 1)
    //     {
    //         if (pivot > k - 1)
    //         {
    //             end = pivot - 1;
    //             pivot = Partition(input, start, end);
    //         }
    //         else
    //         {
    //             start = pivot + 1;
    //             pivot = Partition(input, start, end);
    //         }
    //     }
    //     for (int i = 0; i < k; i++)
    //         result.push_back(input[i]);

    //     return result;
    // }

    // 思路二：最大堆，即优先队列
    // vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    // {
    //     vector<int> result;
    //     const int size = input.size();
    //     if (size <= 0 || k > input.size() || k <= 0)
    //         return result;
    //     priority_queue<int> maxHeap; // 默认升序排列，即最大堆
    //     int i = 0;
    //     while (maxHeap.size() < k)
    //         maxHeap.push(input[i++]);

    //     while (i <= size - 1)
    //     {
    //         if (input[i] < maxHeap.top())
    //         {
    //             maxHeap.push(input[i]);
    //             maxHeap.pop();
    //         }
    //         i++;
    //     }
    //     while (!maxHeap.empty())
    //     {
    //         result.push_back(maxHeap.top());
    //         maxHeap.pop();
    //     }

    //     return result;
    // }

    typedef multiset<int, greater<int>> intSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        const int size = input.size();
        if (size <= 0 || k > input.size() || k <= 0)
            return result;

        intSet leastKNumbers;
        vector<int>::const_iterator iter = input.begin();
        for (; iter != input.end(); ++iter)
        {
            if (leastKNumbers.size() < k)
                leastKNumbers.insert(*iter);
            else
            {
                setIterator iterGreatest = leastKNumbers.begin();
                if (*iter < *(leastKNumbers.begin()))
                {
                    leastKNumbers.erase(iterGreatest);
                    leastKNumbers.insert(*iter);
                }
            }
        }
        for (auto i : leastKNumbers)
            result.push_back(i);

        return result;
    }
};

int main()
{
    vector<int> v = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    Solution s;
    for (int n : s.GetLeastNumbers_Solution(v, 2))
        cout << n << " ";
    return 0;
}