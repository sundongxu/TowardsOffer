/*
    题目：《剑指Offer-面试题28-字符串的排列》
        输入一个字符串，按字典序 打印出该字符串中字符的所有排列
        输入一个字符串，长度不超过9(可能有字符重复)，字符只包括大小写字母
    思路：
        递归
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Solution
{
  public:
    vector<string> Permutation(string str)
    {
        vector<string> result;
        if (str.size() == 0)
            return result;
        Permutation(str, 0, result);
        sort(result.begin(), result.end()); // 结果字典序
        return result;
    }

    // begin指向当前做排列操作的字符串的第一个字符
    void Permutation(string &str, int begin, vector<string> &result)
    {
        if (begin == str.size()) // 最后一个字符都排列完毕，将本次结果保存在result中
        {
            if (find(result.begin(), result.end(), str) == result.end())
                result.push_back(str);
        }
        else
        {
            for (int i = begin; i < str.size(); i++)
            {
                swap(str[i], str[begin]);            // 交换顺序只为当前的排列操作
                Permutation(str, begin + 1, result); // 前进一个字符
                swap(str[begin], str[i]);            // 还原str
            }
        }
    }

    // void Permutation(char *pStr)
    // {
    //     if (pStr == nullptr)
    //         return;
    //     Permutation(pStr, pStr);
    // }

    // void Permutation(char *pStr, char *pBegin)
    // {
    //     if (*pBegin == '\0')
    //         printf("%s\n", pStr);
    //     else
    //     {
    //         for (char *pCh = pBegin; *pCh != '\0'; pCh++)
    //         {
    //             char temp = *pCh;
    //             *pCh = *pBegin;
    //             *pBegin = temp;

    //             Permutation(pStr, pBegin + 1);

    //             temp = *pCh;
    //             *pCh = *pBegin;
    //             *pBegin = temp;
    //         }
    //     }
    // }
};

int main()
{
    // char str[] = "abc";
    // Solution s;
    // s.Permutation(str);

    string s("abc");
    Solution so;
    vector<string> res = so.Permutation(s);
    for (auto s : res)
        cout << s << endl;
    return 0;
}