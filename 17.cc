/*
    题目：
        操作给定的二叉树，将其变换为源二叉树的镜像
    思路：
        前序遍历这棵树的每个结点，如果当前结点有子结点则交换它的两个子结点
        当交换完所有非叶结点的左右子结点之后，就得到了树的镜像
        递归，注意一定在递归函数开头对各种指针取值进行判断，优先处理简单情况(收敛情形)
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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        else if (pRoot->left == nullptr && pRoot->right == nullptr)
            return;
        else
        {
            TreeNode *tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};