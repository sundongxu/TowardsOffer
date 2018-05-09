/*
    题目：《剑指Offer-面试题43-反转单词顺序》
        输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变
        标点符号和普通字母一样处理
        例如，输入字符串“I am a student.”，则输出"student. a am I"
    思路：
        两次翻转，先将整个string翻转，再每个单词分别翻转
        在英语句子中，单词被空格分割，因此可以通过扫描空格来确定每个单词的起始和终止位置
        在翻转每个单词的阶段，指针begin用指向当前单词的第一个字符，而end指向单词的最后一个字符
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string ReverseSentence(string str)
    {
        if (str.size() == 0)
            return "";

        string strResult;

        int begin = 0;
        int end = str.size() - 1;

        // 翻转整个句子
        Reverse(str, begin, end);

        begin = 0; // 指向每个单词开头
        end = 0;   // 指向每个单词结尾

        // 翻转句子中的每个单词
        while (begin < str.size())
        {
            if (str[begin] == ' ')
            {
                begin++;
                end++;
            }
            else if (str[end] == ' ')
            {
                // end指向当前单词的下一个空格
                Reverse(str, begin, end - 1); // 翻转当前单词
                begin = ++end;                // begin指向空格的下一个单词开始
            }
            else if (end == str.size() - 1)
            {
                Reverse(str, begin, end);
                begin = ++end;
            }
            else
            {
                // end尚未指向单词末尾，begin不动，end后移
                end++;
            }
        }
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

int main()
{
    Solution s;
    string str = "abc defg";
    // s.Reverse(str, 0, str.size() - 1);
    // s.ReverseSentence(str);
    cout << s.ReverseSentence(str);
    return 0;
}