/*
    题目：《剑指Offer-面试题38-》
        统计一个数字在排序数组中出现的次数
    思路：
        排序数组，首先想到二分查找
*/

class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int number = 0;
        if (data.size() == 0)
            return 0;
        int firstKPos = GetFirstK(data, k, 0, data.size() - 1);
        int lastKPos = GetLastK(data, k, 0, data.size() - 1);

        if (firstKPos != -1 && lastKPos != -1)
            number = lastKPos - firstKPos + 1;

        return number;
    }

    int GetFirstK(vector<int> &data, int k, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (start + end) / 2;
        int midNumber = data[mid];

        if (midNumber == k)
        {
            if (mid == 0 || (mid > 0 && data[mid - 1] != k))
                return mid;
            else
                end = mid - 1;
        }
        else if (midNumber > k)
            end = mid - 1;
        else
            start = mid + 1;

        return GetFirstK(data, k, start, end);
    }

    int GetLastK(vector<int> &data, int k, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (start + end) / 2;
        int midNumber = data[mid];

        if (midNumber == k)
        {
            if (mid == end || (mid < end && data[mid + 1] != k))
                return mid;
            else
                start = mid + 1;
        }
        else if (midNumber > k)
            end = mid - 1;
        else
            start = mid + 1;

        return GetLastK(data, k, start, end);
    }
};