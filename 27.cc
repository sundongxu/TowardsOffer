/*
    题目：《剑指Offer-面试题29-数组中出现次数超过一半的数字》
        
    思路
        思路一：Partition找中位数
        若有个数出现次数超过数组长度一半，则一定是数组的中位数
        但是中位数不一定是出现次数超过数组长度一半的数，因此找到中位数后还需统计该数到底在数组中出现了多少次
        若出现次数超过数组长度一半且是中位数，那么该数才能是我们要找的数
        若出现次数不超过数组长度一半，说明此数组没有要找的数，应返回0

        快排Partition思想，可在O(n)时间找到数组的中位数，定义中间位置mid = size/2
        每次Partition得到枢轴元素位置pivot
        若pivot < mid，则说明中间位置所在区间为[pivot+1,end]，对该区间进行Partition
        若pivot > mid，则说明中间位置所在区间为[start,pivot-1]，对该区间进行Partition
        若pivot == mid，则说明pivot就是中间位置
        且左边的元素都比numbers[pivot]小，右边的元素都比numbers[pivot]大，numbers[pivot]即为中位数

        思路二：根据数组特点寻找
        数组中有一个数字出现的次数超过数组长度的一半，也就是说它出现的次数比其它所有数字出现次数的还要多
        考虑在遍历数组的时候保存两个值，一个是数组中的一个数字，一个是次数
        当我们遍历到下一个数字时
        如果下一个数字与我们之前保存的数字相同，则次数加1
        如果下一个数字与我们之前保存的数字不同，则次数减1
        如果次数为0，我们需要保存下一个数字，并把次数置为1
        由于我们要找的数字出现的次数比其它所有数字出现的次数之和还要多
        那么要找的数字肯定是最后一次把次数置为1时对应的数字
*/

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

    // 需要检验上面得出的数字是不是真的出现次数超过了数组长度的一半
    bool CheckMoreThanHalf(vector<int> &numbers, int number)
    {
        int times = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == number)
                times++;
        }
        bool isMoreThanHalf = true;
        if (times * 2 <= numbers.size())
            isMoreThanHalf = false;
        return isMoreThanHalf;
    }

    // 思路一：Partition找中位数
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        const int size = numbers.size();
        if (size == 0)
            return 0;

        int start = 0, mid = size / 2, end = size - 1;
        int pivot = Partition(numbers, start, end);
        while (pivot != mid)
        {
            if (pivot > mid)
            {
                end = pivot - 1;
                pivot = Partition(numbers, start, end);
            }
            else
            {
                start = pivot + 1;
                pivot = Partition(numbers, start, end);
            }
        }
        if (CheckMoreThanHalf(numbers, numbers[pivot]))
            return numbers[pivot];
        return 0;
    }

    // 思路二：根据数组特点
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        const int size = numbers.size();
        if (size == 0)
            return 0;

        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); i++)
        {
            if (times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result)
                times++;
            else
                times--;
        }

        if (CheckMoreThanHalf(numbers, result)
            return result;
        return 0;
    }
};