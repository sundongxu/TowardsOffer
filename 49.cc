/*
    题目：《剑指Offer-面试题51-数组中的重复数字》
        在一个长度(length)为n的数组里的所有数字都在0到n-1的范围内
        数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次
        请找出数组中任意一个重复的数字
        例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2
    思路：
        排序后扫描，时间复杂度为O(nlogn)，不够快
        哈希表，时间复杂度O(n)，但需要空间复杂度(辅助哈希表)也是O(n)
        推荐方法：
        注意到数组中的数字都在0到n-1的范围内，如果数组中没有重复的数字，那么排序后数字i将出现在下标为i的位置上
        由于数组中有重复的额数字，有些位置可能存在多个数字，同时有些位置可能没有数字
        现在重排数组，从头到尾依次扫描数组中的每个数字，当扫描到下标为i的数字时，首先看这个数字m(第i个数字)是不是等于i
        如果等于i，接着扫描下一个数字
        如果不等于i，再拿它和第m个位置进行比较
        如果等于第m个数字，则说明找到了重复数字
        如果不等于第m个数字，则将第i个数字(m)与第m个数字交换，故将m放到了其该放的位置(第m个位置)
        接下来重复这个比较、交换的过程，直至数组扫描完毕，如中间找到重复元素则结束

        尽管有一个双重循环，但每个数字最多只交换两次就能找到属于它自己的位置
        因此总的时间复杂度还是O(n)，而且不需要额外分配内存，空间复杂度为O(1)
*/

class Solution
{
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (numbers == nullptr || length <= 0)
            return false;

        for (int i = 0; i < length; i++)
            if (numbers[i] < 0 || numbers[i] > length - 1) // 数字必须在0到length之间
                return false;

        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};