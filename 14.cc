/*
    题目：《剑指Offer-面试题16-反转链表》
        就地反转链表
    思路：
        三个指针，分别指向当前调整的结点，前一个结点和后一个结点
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
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pPre = nullptr, *pCur = pHead, *pNext = pHead->next;
        ListNode *pTemp = nullptr;
        for (; pNext != nullptr; pPre = pCur, pCur = pNext, pNext = pTemp)
        {
            pTemp = pNext->next;
            pNext->next = pCur;
            pCur->next = pPre;
        }
        // 反转后的链表的头结点应该是原链表的尾结点，经过上述处理，pCur已经指向原链表的尾结点了
        return pCur;
    }
};