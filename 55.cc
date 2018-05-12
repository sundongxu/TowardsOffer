/*
    题目：《剑指Offer-面试题57-删除链表中重复的结点》
        在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点
        重复的结点不保留，返回链表头指针
        例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
    思路：
        保存一个节点的前驱结点，指向下一个没有重复的结点
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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode *pPreNode = nullptr;
        ListNode *pNode = pHead;

        while (pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            bool needDel = false;
            if (pNext != nullptr && pNext->val == pNode->val)
                needDel = true;

            if (!needDel)
            {
                pPreNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                int val = pNode->val;
                ListNode *pToBeDel = pNode;
                while (pToBeDel != nullptr && pToBeDel->val == val)
                {
                    pNext = pToBeDel->next;
                    delete pToBeDel;
                    pToBeDel = nullptr;
                    pToBeDel = pNext;
                }
                if (pPreNode == nullptr) // 当前结点pNode为头结点，pPreNode为空，因为头结点之前没有前驱
                    pHead = pNext;
                else
                    pPreNode->next = pNext;
                pNode = pNext;
            }
        }
        return pHead;
    }
};