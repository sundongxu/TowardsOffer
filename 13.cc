/*
    题目：
        输出链表倒数第k个结点
    思路：
        快慢指针，快指针先走k-1步，再两者同时走
        直到快指针到达最后一个结点时，慢指针恰好指向倒数第k个结点
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k <= 0) // 边界条件：指针判空与k的合法性
            return nullptr;
        ListNode *pSlow = pListHead, *pFast = pListHead;
        int ahead = k - 1;
        while (ahead--)
        {
            // 注意这里的边界条件：链表长度与k的大小关系
            if (pFast->next != nullptr)
                pFast = pFast->next;
            else // 链表长度不足k
                return nullptr;
        }
        while (pFast->next != nullptr)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};