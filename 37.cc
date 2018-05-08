/*
    题目：《剑指Offer-面试题39-二叉树的深度》
        输入一棵二叉树，求该树的深度
        从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径上的结点数为树的深度
    思路：
        树的问题优先想到递归，分别计算左子树和右子树的深度后，当前树深度应该还要算上根结点，即要记得加1
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
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return 0;

        int dLeft = TreeDepth(pRoot->left);
        int dRight = TreeDepth(pRoot->right);

        return (dLeft > dRight) ? dLeft + 1 : dRight + 1;
    }
};