/*
    题目：《剑指Offer-面试题35-第一个只出现一次的字符》
        在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符，并返回它的位置
    思路：
        哈希表
        一个字符char一个字节，8位，共2^8=256种可能，创建一个大小为256的字符数组作为哈希表
        遍历一次字符串str，统计每个字符出现的次数，复杂度O(n)
        再遍历一次字符串str，找到第一个出现次数为1的字符，复杂度也是O(n)
        总时间复杂度为O(n)
*/
#include <iostream>
using namespace std;
class Solution
{
  public:
    int FirstNotRepeatingChar(string str)
    {
        if (str.size() == 0)
            return -1;
        const int tableSize = 256;
        unsigned int hashTable[tableSize] = {0};
        for (int i = 0; i < str.size(); i++)
            hashTable[str[i]]++;

        for (int i = 0; i < str.size(); i++)
            if (hashTable[str[i]] == 1)
                return i;

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.FirstNotRepeatingChar("googgle") << endl;
    return 0;
}