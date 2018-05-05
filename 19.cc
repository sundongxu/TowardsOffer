/*
    题目：
        实现一个包含min函数的栈
    思路：
        用一个辅助栈每次在新元素压栈或弹出栈顶元素时，往辅助栈中压人当前最小元素或弹出栈顶元素
        保证每次辅助栈顶都是最小值
        如新元素小于最小元素，则往辅助栈中压人该新元素
        若新元素大于最小元素，则往辅助栈中再次压入当前最小元素，即辅助栈栈顶元素
*/
class Solution
{
  public:
    void push(int value)
    {
        s.push(value);
        if (s_min.size() == 0 || value < s_min.top())  // 开始没考虑边界条件，当最小栈为空时没有top元素
            s_min.push(value);
        else
            s_min.push(s_min.top());
    }
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
            s_min.pop();
        }
    }
    int top()
    {
        if (!s.empty())
            return s.top();
        else
            return -1;
    }
    int min()
    {
        if(!s_min.empty())
            return s_min.top();
        else
            return -1;
    }

  private:
    stack<int> s;
    stack<int> s_min;
};