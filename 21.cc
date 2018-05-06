/*
    题目：《剑指Offer-面试题23-从上往下打印二叉树》
        从上往下打印出二叉树每个结点，同层结点从左往右
    思路：
        即二叉树的层次遍历，利用一个辅助队列
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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *t = nullptr;
        while (!q.empty())
        {
            t = q.front();
            q.pop();
            result.push_back(t->val);
            if (t->left != nullptr)
                q.push(t->left);
            if (t->right != nullptr)
                q.push(t->right);
        }
        return result;
    }
};