/*
    题目：《剑指Offer-面试题55-字符流中第一个不重复的字符》
        请实现一个函数用来找出字符流中第一个只出现一次的字符
        例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"
        当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"
        如果当前字符流没有存在出现一次的字符，返回#字符
    思路：
        参见注释
*/
class Solution
{
  public:
    Solution() : index(0) // 构造函数初始化成员变量
    {
        for (int i = 0; i < 256; i++)
            occurrence[i] = -1;
    }

    // Insert one char from stringstream
    void Insert(char ch)
    {
        if (occurrence[ch] == -1)
            occurrence[ch] = index;
        else if (occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = INT_MAX;
        for (int i = 0; i < 256; i++)
        {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        return ch;
    }

  private:
    // occurrence[i]记录字符i(ACSII码值)的出现次数
    // (1) -1，未出现该字符
    // (2) -2，该字符多次出现
    // (3) >=0，该字符仅出现一次，occurrence[i]等于字符i的出现位置
    int occurrence[256]; // 一个字符8位，共计可表示的ASCII码的表示范围为0~255，共256种可能
    int index;           // 字符流当前遍历到的位置指针
};