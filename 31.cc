/*
    题目：《剑指Offer-面试题33-把数组排成最小的数》
        输入一个正整数数组，把数组里所有数字拼接起来排成一个数
        打印能拼接出的所有数字中最小的一个
    思路：
        实际希望找到一个排序规则，数组根据这个规则排序之后能够排成一个最小的数字
        要确定排序规则，就要比较两个数字，也就是给出连个数字m和n
        我们需要确定一个规则判断m和n哪个应该排在前面，而不仅仅是比较这两个数的值哪个更大

        两个数字m和n能够拼接成数字mn和nm
        如果mn<nm，那么我们应打印出mn，也就是说，在我们定义的这个排序规则下，在排序后的数组中m应该排在n之前，我们定义此时m小于n
        如果mn>nm，那么我们应打印出nm，定义n小于m
        如果mn=nm，则定义m等于n

        再考虑如何拼接数字，即给出数字m和n，怎么得到数字mn和nm并比较它们的大小
        直接用数值计算不难办到，但考虑一个潜在问题是，m和n都在int能表达的范围之内，但是拼起来后的mn和nm可能溢出，这是一个隐形的大数问题

        解决大数问题一个最直观的方法就是把数字转换成字符串
        由于把数字m和n拼接起来得到mn和nm，它们位数一定相同，因此比较它们的大小只需要按照字符串大小的比较规则即可
*/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        string result;
        if (numbers.size() == 0)
            return result;

        vector<string> strNumbers(numbers.size());
        // numbers(int)转换成strNumbers(string)
        for (int i = 0; i < numbers.size(); i++)
        {
            strNumbers[i] = to_string(numbers[i]);
            cout << strNumbers[i] << endl;
        }

        sort(strNumbers.begin(), strNumbers.end(), compare);

        for (int i = 0; i < strNumbers.size(); i++)
            result += strNumbers[i];

        return result;
    }

    static int compare(string &s1, string &s2)
    {
        cout << s1 + s2 << s2 + s1 << endl;
        return s1 + s2 < s2 + s1;  // 小于关系，排序后的数组按升序排列
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    Solution s;
    cout << s.PrintMinNumber(numbers) << endl;
    return 0;
}