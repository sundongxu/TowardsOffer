/*
    题目：《剑指Offer-面试题6-重建二叉树》
        根据二叉树的中序与前序遍历序列重建此二叉树
    思路：
        前序遍历第一个结点即为根结点，在中序遍历序列中找到根结点位置
        则其左边均为根结点的左子树上的结点，获取左子树长度，及其在前序遍历中的起始位置
        右边均为根节点的右子树上的结点，获取右子树长度，及其在前序遍历中的起始位置
        递归构建，每次传入递归函数的参数分别为：
        当前要构造的树的前序序列的第一个结点位置与最后一个节点位置
        当前要构造的树的中序序列的第一个结点位置与最后一个节点位置
        在递归函数中，总是在中序序列中找到当前构造树的根结点位置，根据前序序列的第一个结点即根结点的元素值
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        return constructCore(pre.begin(), pre.end() - 1, vin.begin(), vin.end() - 1);
    }

  private:
    // 四个参数意义如下：
    // 第一、二个为所要构造的树的前序遍历的开始位置和终止位置迭代器
    // 第三、四个为所要构造的树的中序遍历的开始位置和终止位置迭代器
    TreeNode *constructCore(vector<int>::iterator startPre, vector<int>::iterator endPre,
                            vector<int>::iterator startIn, vector<int>::iterator endIn)
    {
        int rootVal = *startPre;
        TreeNode *root = new TreeNode(rootVal);
        root->left = root->right = nullptr;
        if (startPre == endPre)
        {
            if (startIn == endIn && *startPre == *startIn) // 只有一个根结点
                return root;
            else
                return nullptr;
        }
        // 在中序遍历中找到根结点的位置rootIn
        auto rootIn = startIn;
        while (rootIn <= endIn && *rootIn != rootVal)
            ++rootIn;
        if (rootIn == endIn && *rootIn != rootVal) // 没找到根结点，出错
            return nullptr;
        int leftLen = rootIn - startIn;       // 左子树长度
        auto leftPreEnd = startPre + leftLen; // 左子树终止结点位置，在前序遍历序列中
        if (leftLen > 0)
        {
            // 构建左子树
            root->left = constructCore(startPre + 1, leftPreEnd,
                                       startIn, rootIn - 1);
        }
        if (leftLen < endPre - startPre)
        {
            // 还有右子树，构建右子树
            root->right = constructCore(leftPreEnd + 1, endPre,
                                        rootIn + 1, endIn);
        }
        return root;
    }
};