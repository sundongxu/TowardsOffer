/*
    题目：《剑指Offer-面试题36-》
        在数组中的两个数字
        如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
        输入一个数组，求出这个数组中的逆序对的总数P
        并将P对1000000007取模的结果输出，即输出P%1000000007

        题目保证输入的数组中没有的相同的数字

        数据范围：
            对于%50的数据,size<=10^4
            对于%75的数据,size<=10^5
        	对于%100的数据,size<=2*10^5
    思路：
        归并排序
        先把数组分隔成子数组
        先统计出子数组内部的逆序对的数目
        然后再统计出两个相邻子数组之间的逆序对的数目
        在统计逆序对的过程中，还需要对数组进行排序
*/

class Solution
{
  public:
    int InversePairs(vector<int> data)
    {
        if (data.size() == 0)
            return 0;

        vector<int> copy(data);

        int count = InversePairsCore(data, copy, 0, data.size() - 1);

        return count;
    }

    int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = data[start];
            return 0;
        }

        int len = (end - start) / 2;

        int left = InversePairsCore(copy, data, start, start + len) % 1000000007;    // 前半段内部逆序对个数
        int right = InversePairsCore(copy, data, start + len + 1, end) % 1000000007; // 后半段内部逆序对个数

        // i初始化为前半段最后一个数字的下标
        int i = start + len; // i即前半段最大的数字下标
        // j初始化为后半段最后一个数字的下标
        int j = end;         // j即后半段最大的数字下标
        int indexCopy = end; // 合并排序后的数组当前下标，从最后一个位置开始，即从大到小
        int count = 0;       // 前后段各取一个数字能组成的逆序对个数，合并前进行统计

        while (i >= start && j >= start + len + 1)
        {
            if (data[i] > data[j])
            {
                copy[indexCopy--] = data[i--];
                count += (j - start - len); // 后半段还剩多少个数，包含j在内，即[start+len+1, j]区间大小
                // 错误写法：count += (j - start - len) % 1000000007  // 这是对右边求和再取模后再加到count上了，count超过了1000000007也没人管
                if (count >= 1000000007) // 这里很关键，是对count取模，而不是对count要累加的数取模
                    count %= 1000000007;
            }
            else
            {
                copy[indexCopy--] = data[j--];
            }
        }

        for (; i >= start; i--)
            copy[indexCopy--] = data[i];

        for (; j >= start + len + 1; j--)
            copy[indexCopy--] = data[j];

        // 数组data[start]到data[end]段
        // 逆序对的数目 = 前半段内部逆序对数目 + 后半段内部逆序对数目 + 两段各取一个数字所能构成的逆序对数目
        return (left + right + count) % 1000000007;
    }
};