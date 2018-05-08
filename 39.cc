/*
    题目：《剑指Offer-面试题40-数组中只出现一次的数字》
        一个整型数组里除了两个数字之外，其他的数字都出现了两次
        请找出这两个只出现一次的数字
    思路：
        简化问题：若除了一个数字之外，其它数字都出现了两次，怎么找到这个数字？
        解决方法：可以从头到尾异或一次，出现两次的数字异或之后结果都为0，最终异或结果就是那个出现了一次的数字

        同理，依然异或全部数字，由于这次有两个数字只出现了一次，那么最终异或结果依然不会为0，而就是这两个数字的异或结果
        异或结果不为0，那么其2进制表示中至少一位非0，则这两个数字在该位上一定一个为0，一个为1
        我们按照此位是否为0将原数组分成两个子数组，在该位上为0的数字分成一组，在该位上为1的数字分成一组
        那么显然，这两个数字会被分别分到两个数组中去，再对这两个数组分别异或即可分别得到这两个数啦
*/

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.size() == 0)
            return;

        int xorResult = 0;

        for (int i = 0; i < data.size(); i++)
            xorResult ^= data[i];

        unsigned int indexOf1 = FindFirstBitIs1(xorResult);

        *num1 = *num2 = 0;

        for (int j = 0; j < data.size(); j++)
        {
            if (IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }

    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) // 不得超过32位
        {
            // 找到从右往左第一个1
            num = num >> 1; // 抹掉最低位的0
            indexBit++;
        }
        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return num & 1;
    }
};