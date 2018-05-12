/*
    题目：《剑指Offer-面试题58-二叉树的下一个结点》
        给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回
        注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针
    思路：
        要找某结点按中序遍历中的下一个结点，分两种情况讨论：
        （1）该结点有右子树，则下一个结点为其右子树中的最左子结点
        （2）该结点无右子树，再分为两种情况讨论：
            ① 如该结点为其父结点的左子结点，则下一个结点为其父结点
            ② 如该结点为其父结点的右子结点，找其下一个结点，需沿着其父结点向上遍历，直至找到某个是其父结点的左子结点的结点，则该结点的父结点为其下一个结点
*/

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // 指向父结点
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
    {
    }
};

class Solution
{
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == nullptr)
            return nullptr;

        TreeLinkNode *pNext = nullptr;

        if (pNode->right != nullptr) // 有右子树
        {
            TreeLinkNode *pRight = pNode->right;
            while (pRight->left != nullptr) // 找到最左子结点即下一个结点
                pRight = pRight->left;
            pNext = pRight;
        }
        else if (pNode->next != nullptr) // 无右子树且父结点不为空，即未到根结点
        {
            TreeLinkNode *pCur = pNode;
            TreeLinkNode *pParent = pNode->next;
            while (pParent != nullptr && pCur == pParent->right)
            {
                pCur = pParent;
                pParent = pParent->next;
            }
            pNext = pParent;
        }
        return pNext;
    }
};