/*
    题目：《剑指Offer-面试题24-二叉树的后序遍历序列》
        判断输入序列是不是某二叉搜索树的后序遍历序列
        假设数组中数字各不相同
    思路：
        二叉搜索树：任意结点的左子树上的结点的关键码都小于本结点，右子树上的结点的关键码都大于本结点
        序列的最后一个结点为根结点
        从序列第一个结点开始直到第一个大于根结点的结点之前为根结点的左子树
        从序列第一个大于根结点的结点到根结点之前为根结点的右子树
        递归检查左右子树的合法性，收敛条件要找好
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        const int size = sequence.size();
        return VerifyHelper(sequence, 0, size - 1);
    }

    bool VerifyHelper(vector<int> &seq, int start, int end)
    {
        const int size = end - start + 1;
        if (size <= 0)
            return false;

        int root = seq[end];

        // 在二叉搜索树中左子树的结点小于根结点
        int i = 0;
        for (; i <= end - 1; i++)
        {
            if (seq[i] > root)
                break;
        } // i为右子树第一个结点位置

        // 在二叉搜索树中右子树的结点大于根结点
        int j = i;
        for (; j <= end - 1; ++j)
        {
            if (seq[j] < root) // 有小于根结点的结点存在，故右子树不合法
                return false;
        }

        // 判断左子树是不是二叉搜索树
        bool left = true;
        if (i > start) // 有左子树
            left = VerifyHelper(seq, start, i - 1);

        // 判断右子树是不是二叉搜索树
        bool right = true;
        if (i < end) // 有右子树
            right = VerifyHelper(seq, i, end - 1);

        return left && right;
    }
};

int main()
{
    vector<int> seq1{7, 4, 6, 5};
    vector<int> seq2{5, 7, 6, 9, 11, 10, 8};
    Solution s;
    cout << s.VerifySquenceOfBST(seq1) << endl;
    cout << s.VerifySquenceOfBST(seq2) << endl;
    return 0;
}