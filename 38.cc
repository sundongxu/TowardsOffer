/*
    题目：《剑指Offer-面试题39.2-判断一棵树是否为平衡二叉树》
        输入一棵二叉树，判断该二叉树是否是平衡二叉树
    思路：
        如果某二叉树的任意结点的左右子树深度相差不超过1，那么它就是一棵平衡二叉树
        思路一：沿用上一题的TreeDepth()方法计算每个根结点左右子树的深度，深度差不超过1，就是AVL
        思路二：思路一可能会多次遍历同一个结点，用后序遍历，在遍历到一个结点之前我们就已经遍历了它的左右子树
        只要在遍历每个结点的时候记录它的深度，我们就可以一边遍历一边判断每个结点是不是平衡的
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
    // 思路一：每次都会计算子树深度，可能重复遍历下层结点
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == nullptr) // 边界条件，因为是在递归中，要仔细考虑
            return true;
        int dLeft = TreeDepth(pRoot->left);
        int dRight = TreeDepth(pRoot->right);
        if (abs(dLeft - dRight) > 1)
            return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return 0;

        int dLeft = TreeDepth(pRoot->left);
        int dRight = TreeDepth(pRoot->right);

        return (dLeft > dRight) ? dLeft + 1 : dRight + 1;
    }

    // 思路二：后序遍历，遍历每个结点时通过depth记录其深度，边遍历边判断平衡性
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int depth = 0;
        return IsBalanced(pRoot, depth);
    }

    bool IsBalanced(TreeNode *pRoot, int &depth)
    {
        if (pRoot == nullptr)
        {
            depth = 0;
            return true;
        }

        int left, right;
        if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)) // 先左右子树后根结点
        {
            if (abs(left - right) <= 1)
            {
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};