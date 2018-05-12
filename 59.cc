/*
    题目：《剑指Offer-面试题-按之字形顺序打印二叉树》
        请实现一个函数按照之字形打印二叉树
        即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印
        其他行以此类推。
    思路：
        
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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> result;
        if (pRoot == nullptr)
            return result;

        vector<stack<TreeNode *>> levels(2);
        int current = 0;             // 当前层
        int next = 1;                // 下一层
        levels[current].push(pRoot); // 第一层，即根结点先入奇数层栈

        vector<int> level;

        while (!levels[0].empty() || !levels[1].empty())
        {
            TreeNode *pNode = levels[current].top();
            levels[current].pop();
            level.push_back(pNode->val);

            if (current == 0) // 当前层为偶数层，下层奇数层，则左孩子先入栈，右孩子后入栈
            {
                if (pNode->left != nullptr)
                    levels[next].push(pNode->left);
                if (pNode->right != nullptr)
                    levels[next].push(pNode->right);
            }
            else // 当前层为奇数层，下层偶数层，则右孩子先入栈，左孩子后入栈
            {
                if (pNode->right != nullptr)
                    levels[next].push(pNode->right);
                if (pNode->left != nullptr)
                    levels[next].push(pNode->left);
            }

            if (levels[current].empty())
            {
                // 本层访问完毕
                result.push_back(level);
                level.clear();
                current = 1 - current; // 翻转
                next = 1 - next;       // 翻转
            }
        }
        return result;
    }
};