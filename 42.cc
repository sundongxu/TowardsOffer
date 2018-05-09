/*
    题目：《剑指Offer-面试题42-左旋转字符串》
        对于一个给定的字符序列S，请你把其循环左移K位后的序列输出
        例如，字符序列S=”abcXYZdef”，要求输出循环左移3位后的结果，即“XYZdefabc”
    思路：
        
*/

class Solution
{
  public:
    string LeftRotateString(string str, int n)
    {
        int len = str.size();

        if (len == 0 || n < 0)
            return "";

        // 将字符串分为两个部分
        // 第一个部分为由于循环左移会被放到字符串末尾去的字符串
        int firstStart = 0;
        int firstEnd = n - 1;
        int secondStart = n;
        int secondEnd = len - 1;

        // 翻转字符串前n个字符，即第一个部分
        Reverse(str, firstStart, firstEnd);
        // 翻转字符串后len-n个字符，即第二个部分
        Reverse(str, secondStart, secondEnd);
        // 翻转整个字符串
        Reverse(str, 0, len - 1);

        return str;
    }

    // 反转整个句子
    void Reverse(string &str, int begin, int end)
    {
        if (str.size() == 0)
            return;

        if (begin > end)
            return;

        while (begin < end)
        {
            swap(str[begin], str[end]);
            begin++;
            end--;
        }
    }
};