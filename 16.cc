/*
    题目：
        输入两棵二叉树A，B，判断B是不是A的子结构
        约定空树不是任何树的子结构
    思路：
        需遍历树A，可递归
        先在A中找到与B根结点元素值相同的结点
        再判断该结点下面的结构是否与B一致
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
    // 递归遍历树A，当A当前结点与B根结点元素值相同时调用DoesTree2HaveTree1()做第二部判断
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        // 边界条件：空树不是任何树的子结构，任何树的都不是空树的子结构
        bool result = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr)
        {
            if (pRoot1->val == pRoot2->val)
                // 在树A中找到与树B根结点相同的结点，判断该结点下面的结构是否与B的一致
                result = DoesTree2HaveTree1(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2); // 根结点的左子树是否包含树B
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2); // 根结点的右子树是否包含树B
        }
        return result;
    }

    // 递归遍历树B，判断以r1和r2为根结点(相同)的两棵树是否结构一致
    bool DoesTree2HaveTree1(TreeNode *r1, TreeNode *r2)
    {
        // r1->val == r2->val
        // 遍历树B
        // 先要判断指针
        if (r2 == nullptr)
            return true;
        if (r1 == nullptr)
            return false;
        if (r1->val != r2->val)
            return false;
        return DoesTree2HaveTree1(r1->left, r2->left) && DoesTree2HaveTree1(r1->right, r2->right);
    }
};