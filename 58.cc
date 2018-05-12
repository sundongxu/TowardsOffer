/*
    题目：《剑指Offer-面试题60-把二叉树打印成多行》
        从上到下按层打印二叉树，同一层结点从左至右输出，每一层输出一行
    思路：
        层次遍历，需用到一个辅助队列，每次从队头取一个元素并打印，再将其左右孩子依次入队
        两个辅助变量：nextLevel用于记录下一层的总结点数(在入队时计数)，toBePrinted用于记录当前层剩余还未打印的结点数
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
        queue<TreeNode *> nodes; // 层次遍历辅助队列
        nodes.push(pRoot);
        int nextLevel = 0;   // 下一层的结点数
        int toBePrinted = 1; // 本层尚未打印的结点数
        vector<int> seq;
        while (!nodes.empty())
        {
            TreeNode *pNode = nodes.front();
            seq.push_back(pNode->val);

            if (pNode->left != nullptr)
            {
                nodes.push(pNode->left);
                nextLevel++; // 当前结点有左子结点，故下一层结点数加一
            }
            if (pNode->right != nullptr)
            {
                nodes.push(pNode->right);
                nextLevel++; // 当前结点有右子结点，故下一层结点数加一
            }

            nodes.pop();
            --toBePrinted; // 当前结点出队，即打印成功(添加到当前层seq中)，本层剩余未打印的结点数减一

            if (toBePrinted == 0) // 本层打印完毕，转至下一层
            {
                result.push_back(seq);
                seq.clear();
                toBePrinted = nextLevel; // 待打印层的结点数即之前记录的上一层的总结点数
                nextLevel = 0;
            }
        }
        return result;
    }
};