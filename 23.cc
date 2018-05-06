/*
    题目：《剑指Offer-面试题25-二叉树中和为某一值的路径》
        输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径
        路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
    思路：
        深度搜索 + 回溯 + 递归
        
        由于路径是从根结点出发到叶结点，也就是说路径总是以根结点为起始点
        因此需要首先遍历根结点，在树的前序、中序和后序三种遍历方式中，只有前序遍历是先访问根结点的

        按照前序遍历的顺序遍历二叉树，在遍历完一个结点时，我们是不知道前面经过了哪些结点的
        除非我们把经过的路径上的结点保存下来，每访问一个结点时，我们都将这个结点添加到路径中去
        直到到达叶结点，判断这条路径上的和是不是我们指定的和
        是则路径合法，否则路径丢弃，即该叶结点不可用，退回到路径上一个结点
        即每一次从子结点回退到父结点时，都需要在路径上删除子结点

        总结一下完整思路：
        当用前序遍历的方式访问到某一结点时，将当前结点添加到路径上，并累加该结点的值
        如果该结点为叶结点并且路径中结点值的和刚好等于输入的整数，则当前路径符合要求，将其打印出来
        如果该结点不是叶结点，则继续访问它的子结点
        当前结点访问结束后，递归函数将自动回到其父结点
        因此，在每次递归函数退出之前要在路径上删除当前结点并减去当前结点的结点值，以确保返回父结点时，路径刚好是从根结点到父结点的路径

        不难看出，保存路径的数据结构实际是一个栈，因为路径要与递归调用状态一致
        而递归调用的本质就是一个压栈与出栈的过程
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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> result;
        vector<int> curPath;
        FindPath(root, expectNumber, curPath, result);
        return result;
    }

    void FindPath(TreeNode *root, int gap, vector<int> curPath, vector<vector<int>> &result)
    {
        if (root == nullptr)
            return;

        curPath.push_back(root->val);

        if (root->left == nullptr || root->right == nullptr)
            // root为叶结点，curPath已经完结
            if (gap == root->val) // 加上该叶结点root的值恰好为目标和，则路径合法，添加到result中
                result.push_back(curPath);

        FindPath(root->left, gap - root->val, curPath, result);  // root非叶结点，对其左子树递归
        FindPath(root->right, gap - root->val, curPath, result); // root非叶结点，对其右子树递归

        curPath.pop_back(); // 回溯到root上一个结点处
    }
};

// 《剑指Offer》实例代码
class Solution
{
  public:
    void FindPath(TreeNode *root, int expectNumber)
    {
        if (root == nullptr)
            return;
        vector<int> path;
        int currentSum = 0;
        FindPath(root, expectNumber, path, currentSum);
    }

    void FindPath(TreeNode *root, int expectedSum, vector<int> &path, int currentSum)
    {
        currentSum += root->val;
        path.push_back(root->val);

        // 如果是叶结点，并且路径上结点的和等于输入的值
        // 打印出路径
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (currentSum == expectedSum && isLeaf)
        {
            cout << "A Path is Found:" << endl;
            for (auto iter = path.begin(); iter != path.end(); iter++)
                cout << *iter << " ";
            cout << endl;
        }

        // 如果不是叶结点
        if (root->left != nullptr)
            FindPath(root->left, expectedSum, path, currentSum);
        if (root->right != nullptr)
            FindPath(root->right, expectedSum, path, currentSum);

        // 在返回父结点之前，在路径上删除当前结点
        path.pop_back();
    }
};