/*
    题目：
        输入一个链表，从尾到头打印链表每个节点的值
    思路：
        栈 或 递归
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
// 法1：栈
class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        if (head == nullptr)
            return res;
        stack<int> s;
        ListNode *p = head;
        while (p != nullptr)
        {
            s.push(p->val);
            p = p->next;
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

// 法2：递归
class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        printListFromTailToHead(head, res);
        return res;
    }

  private:
    void printListFromTailToHead(ListNode *head, vector<int> &res)
    {
        if (head == nullptr)
            return;
        if (head->next != nullptr)
            printListFromTailToHead(head->next, res);
        res.push_back(head->val);
    }
};
