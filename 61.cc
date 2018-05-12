/*
    题目：《剑指Offer-面试题63-二叉搜索树的第k个结点》
        给定一颗二叉搜索树，请找出其中的第k大的结点
        例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4
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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == nullptr || k <= 0)
            return nullptr;

        return KthNodeCore(pRoot, k);
    }

    TreeNode *KthNodeCore(TreeNode *pRoot, int &k)
    {
        TreeNode *target = nullptr;
        if (pRoot->left != nullptr)
            target = KthNodeCore(pRoot->left, k); // 中序遍历，先去左子树中找，在找寻第k个结点过程中，每遍历一个结点都会把k减1

        if (target == nullptr) // 第k个结点不在根结点的左子树中
        {
            if (k == 1) // 遍历左子树后，发现k已经被减小至1，即在左子树中有k-1个结点，那么当前根结点即第k个结点
                target = pRoot;
            k--;
        }

        if (target == nullptr && pRoot->right != nullptr) // 中序遍历，最后去右子树中找
            target = KthNodeCore(pRoot->right, k);

        return target;
    }
};