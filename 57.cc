/*
    题目：《剑指Offer-面试题59-对称的二叉树》
        请实现一个函数，用来判断一颗二叉树是不是对称的
        注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
    思路：
        递归，定义好边界条件即可
        另可考虑前序遍历和其对称前序遍历是否一致，需添加上nullptr叶结点
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
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == nullptr) // 空树 - 对称
            return true;
        return isSymmetrical(pRoot->left, pRoot->right); // 判断左右子树是否对称
    }

    // 判断某结点的左右子树是否对称
    bool isSymmetrical(TreeNode *pLeft, TreeNode *pRight)
    {
        if (pLeft == nullptr && pRight == nullptr) // 左右子树均为空，对称
            return true;
        if (pLeft == nullptr || pRight == nullptr) // 左右子树仅一棵为空，不对称
            return false;
        if (pLeft->val != pRight->val) // 左结点与右结点值不一样，不对称
            return false;

        // 上面收敛条件均不满足，则继续向下遍历，此时考虑对称的结点为，当前结点的左结点的左孩子和右结点的右孩子，以及左结点的右孩子和右结点左孩子
        return isSymmetrical(pLeft->left, pRight->right) && isSymmetrical(pLeft->right, pRight->left);
    }
};