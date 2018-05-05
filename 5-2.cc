/*
    题目：
        用两个队列实现一个栈，实现其push和pop操作
    思路：
        （1）对于push操作：一个队列queue1总是将新元素入队
        （2）对于pop操作：弹出from中最后一个元素
        模拟栈的过程中，保证两个队列中始终有一个队列为空，另一个队列不空，空栈时两队列全部为空；；
        queue1和queue2运行过程中有时充当from，有时充当to；
        非空队列from中所有元素依次出队并入队to队列中，直到from中只剩下一个元素，
        实现top()


*/
class Solution
{
  public:
    void push(int node)
    {
        queue1.push(node);
    }

    void move(queue<int> &from, queue<int> &to)
    {
        while (from.size() > 1)
        {
            int node = from.top();
            from.pop();
            to.push(node);
        }
    }

    int pop()
    {
        int res = -1; // 为空返回-1
        if (!empty())
        {
            if (!queue1.empty())
            {
                move(queue1, queue2);
                res = queue1.top();
                queue1.pop();
            }
            else
            {
                move(queue2, queue1);
                res = queue2.top();
                queue2.pop();
            }
        }
        return res;
    }

    int top()
    {
        int res = -1; // 为空返回-1
        if (!empty())
        {
            if (!queue1.empty())
            {
                move(queue1, queue2);
                res = queue1.top();
                queue1.pop();
                queue2.push(res);
            }
            else
            {
                move(queue2, queue1);
                res = queue2.top();
                queue2.pop();
                queue2.push(res);
            }
        }
        return res;
    }

    bool empty()
    {
        return queue1.empty() && queue2.empty();
    }

  private:
    queue<int> queue1;
    queue<int> queue2;
};