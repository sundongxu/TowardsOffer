/*
    题目：《剑指Offer-面试题62-序列化二叉树》
        请实现两个函数，分别用来序列化和反序列化二叉树
    思路：
        （1）对于序列化：
        使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点不为空时，在转化val所得的字符之后添加一个','作为分隔
        对于空节点则以'#'代替。
        （2）对于反序列化：
        按照前序顺序，递归的使用字符串中的字符创建一个二叉树
        特别注意：在递归时，递归函数的参数一定要是char **，这样才能保证每次递归后指向字符串的指针会随着递归的进行而移动

        思考：在函数f1中定义某变量，然后在调用另一个函数f2时，将该变量的引用或指针传入被调用函数f2，目的是什么？
        void f1()
        {
            int i;
            f2(i);  // 引用参数
            f2(&i)  // 指针参数
        }

        void f2(int &i)
        {
            // change i
        }

        void f2(int *pi)
        {
            // change *pi
        }

        答案：因为我们想在主调函数f1中使用通过f2修改后的原变量i的值
        在f2中无论是修改引用i，还是修改指针pi的解引用(*pi)后的结果，实际都是直接修改了原变量i，
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
    char *Serialize(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        string str;
        Serialize(root, str);                   // 将二叉树序列化成字符串
        char *ret = new char[str.length() + 1]; // 结尾添加结束符'\0'
        int i;                                  // 下标
        for (i = 0; i < str.length(); i++)
        {
            ret[i] = str[i]; // 将字符串转为字符数组
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string &str)
    {
        if (root == nullptr)
        {
            str += '#'; // 空指针用#代替
            return;
        }
        string r = to_string(root->val);
        str += r;
        str += ','; // 正常字符用,分隔
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    TreeNode *Deserialize(char *str)
    {
        if (str == nullptr)
            return nullptr;
        TreeNode *ret = Deserialize(&str);

        return ret;
    }
    TreeNode *Deserialize(char **str)
    {
        // 由于递归时，会不断的向后读取字符串
        // 所以一定要用**str，以保证得到递归后指针str指向未被读取的字符
        if (**str == '#')
        {
            ++(*str);
            return nullptr;
        }

        // repeat
        // if (*str == '#')
        // {
        //     ++str;
        //     return nullptr;
        // }

        int num = 0;
        while (**str != '\0' && **str != ',')
        {
            num = num * 10 + ((**str) - '0'); // 结点值可能超过10
            ++(*str);
        }

        // repeat
        while (*str != '\0' && *str != ',')
        {
            num = num * 10 + (*str - '0');
            ++str;
        }

        TreeNode *root = new TreeNode(num);

        if (**str == '\0') // 当前为结束符，结束，返回当前结点，因为最后一个结点没有左右子树了
            return root;
        else // 当前为逗号分隔符，跳过
            (*str)++;

        // repear
        // if (*str == '\0')
        //     return root;
        // else
        //     str++;
        // so far no problem

        root->left = Deserialize(str);  // 构造根结点的左子树
        root->right = Deserialize(str); // 构造根结点的右子树

        // repeat
        // root->left = Deserialize(str);  // str是个char *，在这一步中修改了str值，但只是当前函数中str的一个拷贝，而非就是这个str
        // root->right = Deserialize(str);  // 从而修改过后的str值不能在这一步使用，这一步仍是使用当前函数的str值

        return root;
    }
};
