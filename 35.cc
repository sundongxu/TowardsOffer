/*
    题目：《剑指Offer-面试题37-两个链表的第一个公共结点》
        输入两个链表，找出它们的第一个公共结点
    思路：
        如果两个链表有公共结点，那么从该公共结点之后的结点都相同
        如果两个链表长度不等且有公共结点，那么长度差只可能发生在头结点到公共结点这一段上
        先计算两个链表的长度差l，让长的链表的指针从头结点开始先走l步
        然后两个指针一起后移，若两者在到达各自尾结点之前相遇，即指向同一个结点，则返回该当前结点
*/

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};
class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;

        // 都不为空
        int len1 = 0, len2 = 0;
        ListNode *p1 = pHead1, *p2 = pHead2;

        while (p1 != nullptr)
        {
            len1++;
            p1 = p1->next;
        }

        while (p2 != nullptr)
        {
            len2++;
            p2 = p2->next;
        }

        int l = abs(len1 - len2);
        if (l == 0 && pHead1 == pHead2) // 长度相等
            return pHead1;
        else if(l == 0)
            return nullptr;

        p1 = pHead1;
        p2 = pHead2;

        if (len1 > len2) // p1先走l步
            while (l--)
                p1 = p1->next;
        else // p2先走l步
            while (l--)
                p2 = p2->next;

        // p1和p2同时走，到各自尾结点之前
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        return nullptr;
    }
};