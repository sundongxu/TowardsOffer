/*
    题目：《剑指Offer-面试题17-合并两个排序的链表》
        合并两个单调递增的链表成为一个单调不减的长链表
    思路：
        两个指针分别指向两个链表的当前结点
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return pHead1 == nullptr ? pHead2 : pHead1;
        ListNode head(-1);
        ListNode *p = &head;
        for (; pHead1 != nullptr && pHead2 != nullptr; p = p->next)
        {
            if (pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
        }
        // pHead1或pHead2有一个没到底
        p->next = pHead1 != nullptr ? pHead1 : pHead2;
        return head.next;
    }
};