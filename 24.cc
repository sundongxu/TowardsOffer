/*
    题目：《剑指Offer-面试题26-复杂链表的复制》
        输入一个复杂链表，每个节点中有节点值，以及两个指针
        一个指向下一个节点，另一个特殊指针指向任意一个节点
        返回结果为复制后复杂链表的head
        注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空
    思路：
        难点：在创建一个新节点时，需要指定其random指针，该指针原本指向的结点可能还未创建
        解法：
        在同一个链表中创建复制结点，且分别插入在其源结点之后
        源结点N的指针random指向结点S，则结点N'的指针random指向结点S‘
        而N'就在N下一个位置，那么S'也就在S的下一个位置
        将长链表按位置下标的奇偶性拆分，偶数位置的结点用next指针连接起来即为复制得到的链表
*/

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr)
    {
    }
};

// 分治版(返回为空，不懂...)
class Solution
{
  public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }

    // 第一步：遍历链表，复制每个结点，并将克隆结点插入在源结点之后
    void CloneNodes(RandomListNode *pHead)
    {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next; // pCloned的下一个结点即源结点的下一个结点
            pCloned->random = nullptr;

            pNode->next = pCloned; // 克隆结点接在源结点之后
            pNode = pCloned->next; // pNode指向下一个要复制的源结点
        }
    }

    // 第二步：设置复制出来的结点的random指针
    // 假设原始链表上的N的random指向结点S，那么其对应复制出来的结点N'是N的next指向的结点
    // 同样N'的random指向的结点S'，也应该是S结点的next指向的结点
    void ConnectRandomNodes(RandomListNode *pHead)
    {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pCloned = pNode->next;
            if (pNode->random != nullptr)
            {
                pCloned->random = pNode->random->next;
            }
            pNode = pCloned->next;
        }
    }

    // 第三步：将长链表拆分成两个链表
    // 将奇数位置的结点用next链接起来就是原始链表
    // 将偶数位置的结点用next链接起来就是复制出来的链表
    RandomListNode *ReconnectNodes(RandomListNode *pHead)
    {
        RandomListNode *pNode = pHead;
        RandomListNode *pClonedHead = nullptr;
        RandomListNode *pClonedNode = nullptr;

        if (pNode != nullptr)
        {
            pClonedHead = pClonedNode = pNode->next; // 指向长链表第二个结点，即复制链表的第一个结点
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode != nullptr)
        {
            pClonedNode->next = pNode->next;
            pNode->next = pClonedNode->next;
            pClonedNode = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
};

// 合并版，AC
class Solution
{
  public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        RandomListNode *node = pHead;
        while (node != nullptr)
        {
            RandomListNode *nodeCopy = new RandomListNode(node->label);
            nodeCopy->next = node->next;
            nodeCopy->random = node->random;
            node->next = nodeCopy;
            node = node->next->next;
        }

        node = pHead;
        int count = 0; // 长链表第0个位置即第一个结点
        RandomListNode *head = nullptr;
        RandomListNode *temp = nullptr;

        while (node != nullptr)
        {
            count++;
            if (count % 2 == 0) // 偶数位置，复制结点
            {
                if (count == 2) // 长链表中第2个结点，复制链表头结点
                    head = node;

                if (node->random != nullptr)
                    node->random = node->random->next;

                temp = node->next;

                if (node->next != nullptr)
                    node->next = node->next->next;

                node = temp;
            } // 偶数位置，源结点
            else
                node = node->next;
        }
        pHead->next = nullptr;
        return head;
    }
};