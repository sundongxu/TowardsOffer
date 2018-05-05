/*
    题目：
        用两个栈实现一个队列，实现其push和pop操作
    思路：
        （1）对于push操作：一个栈stack1总是将新元素入栈
        （2）对于pop操作：分两种情况
        如栈stack2为空，则将stack1全部出栈，并按元素出栈顺序依次入栈stack2，再弹出stack2顶部元素
        如栈stack不为空，则直接让其顶部元素出栈
*/
class Solution
{
  public:
    void push(int node)
    {
        // 统统入栈stack1
        // 先检查是否已满，没有size属性，暂不考虑
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            // stack2为空
            // stack1全部出栈，并按出栈顺序入栈stack2
            while (!stack1.empty())
            {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }
        if (stack2.empty())
            return -1;
        int res = stack2.top();
        stack2.pop();
        return res;
    }

    int top()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }
        if (stack2.empty())
            return -1;
        return stack2.top();
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};