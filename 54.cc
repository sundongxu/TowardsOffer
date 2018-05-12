/*
    题目：《剑指Offer-面试题56-链表中环的入口结点》
        一个链表中包含环，请找出该链表的环的入口结点
    思路：
        快慢指针，快指针先走环长距离，然后同时走，则两者相遇处为环的入口结点处
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode *meetingNode = MeetingNode(pHead);
        if (meetingNode == nullptr) // 无环
            return nullptr;

        int nodesInLoop = 1; // 环中结点个数
        ListNode *pNode1 = meetingNode;
        while (pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            nodesInLoop++;
        }

        // 移动pNode1
        pNode1 = pHead;
        for (int i = 0; i < nodesInLoop; i++)
            pNode1 = pNode1->next;

        // 同时一定pNode1和pNode2
        ListNode *pNode2 = pHead;
        while (pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return pNode1;
    }

    ListNode *MeetingNode(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        // 快慢指针，如有环，则一定在某处相遇
        ListNode *pSlow = pHead;
        ListNode *pFast = pHead;

        while (pSlow != nullptr && pFast != nullptr)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;

            if (pFast != nullptr)
                pFast = pFast->next;

            if (pSlow == pFast)
                return pFast;
        }
        return nullptr;
    }
};