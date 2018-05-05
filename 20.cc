/*
    题目：
        输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
        假设压入栈的所有数字均不相等
    思路：
        类似火车出站序列问题
        以压栈顺序1、2、3、4、5为例
        合法的出栈序列应满足：序列中某个元素之后的序列中，比该元素小的元素应该逆序排列
        一般地，可以用压栈序列中的元素下标来代替元素大小
        即在合法的出栈序列中，某个元素之后的序列中，在原入栈数组中下标比它小的应该按下标逆序排列
        上述方法适合于做选择题

        最直接方法，利用一个辅助栈，根据出栈序列，将入栈序列元素一个个按顺序压栈
        若栈顶元素不是出栈序列中的当前元素，则继续压栈，直到是为止，若元素已全部压栈，还是无法满足，则出栈序列不合法
        若栈顶元素就是出栈序列中的当前元素，则出栈，继续判断出栈序列的下一个位置的元素，直至出栈序列耗尽
*/
class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() != popV.size())
            return false;
        bool result = true;
        stack<int> s;
        int pushIdx = 0, popIdx = 0;
        while(popIdx < popV.size())
        {
            while(s.empty() && pushIdx < pushV.size())
                s.push(pushV[pushIdx++]);
            while(s.top() != popV[popIdx] && pushIdx < pushV.size())
                s.push(pushV[pushIdx++]);
            if(pushIdx < pushV.size())
            {
                s.pop();
                popIdx++;
            }
            else
                result = false;
        }
        return result;
    }
};