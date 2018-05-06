/*
    题目：《剑指Offer-面试题27-二叉搜索树与双向链表》
        输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
        要求不能创建任何新的结点，只能调整树中结点指针的指向
    思路：
        从下到大给二叉树结点排序，第一反应中序遍历序列就是从下到大的结点序列
        有树的问题优先想到递归
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *pLastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeInList);

        // pLastNodeInList指向双向链表尾结点
        TreeNode *pHeadOfList = pLastNodeInList; // 结果链表的头结点
        while (pHeadOfList != nullptr && pHeadOfList->left != nullptr)
            // 将pHeadOfList从尾结点一路向左指回到头结点
            pHeadOfList = pHeadOfList->left;
        return pHeadOfList;
    }

    // 递归函数
    void ConvertNode(TreeNode *pNode, TreeNode **pLastNodeInList)
    {
        if (pNode == nullptr)
            return;

        TreeNode *pCur = pNode;
        // 中序遍历，先访问pCur左子树
        if (pCur->left != nullptr)
            ConvertNode(pCur->left, pLastNodeInList);

        pCur->left = *pLastNodeInList; // pLastNodeInList总是指向当前结果链表的尾结点，即pCur左子树中最大结点，与pCur相连
        if (*pLastNodeInList != nullptr)
            (*pLastNodeInList)->right = pCur;

        // 中序遍历，再访问pCur
        *pLastNodeInList = pCur; // pLastNodeInList在双向链表中后移，继续指向现在已为尾结点的pCur

        // 中序遍历，最后访问pCur右子树
        if (pCur->right != nullptr)
            ConvertNode(pCur->right, pLastNodeInList);
    }
};