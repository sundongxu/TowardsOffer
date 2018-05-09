/*
    题目：《剑指Offer-面试题44-扑克牌的顺子》
        从扑克牌中随机抽取5张牌，判断是不是顺子，即这5张牌是不是连续的
        A为1，J为11，Q为12，K为13，大小王可以是任意数字
    思路：
        将大小王先看做是0
        首先将数组排序，在统计数组中0的个数，最后统计排序之后的数组中相邻数字之间的空缺总数
        如果空缺总数小于或等于0的个数，那么这个数组就是连续的，反之则不连续
*/

class Solution
{
  public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() != 5)
            return false;

        sort(numbers.begin(), numbers.end());

        int count0 = 0;
        for (auto n : numbers)
            if (n == 0)
                count0++;

        int countGap = 0;
        for (int i = count0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] == numbers[i + 1]) // 如有相同的数则无法组成顺子
                return false;
            else
                countGap += numbers[i + 1] - numbers[i] - 1; // 相邻数之间的间隔张数
        }
        if (countGap <= count0)
            return true;
        return false;
    }
};