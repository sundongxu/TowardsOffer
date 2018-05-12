/*
    题目：《剑指Offer-面试题52-构建乘积数组》
        给定一个长度为n的数组A[0,1,...,n-1]
        请构建一个数组B[0,1,...,n-1]
        其中B中的元素B[i] = A[0] * A[1] * ... * A[i-1] * A[i+1] * ... * A[n-1]，
        注意少了A[i]这一项，正常来说都是从A[0]累乘到A[n-1]再除以A[i]
        而题目要求不能使用除法
    思路：
        定义C[i] = A[0] * A[1] * ... * A[i-1]，D[i] = A[i+1] * A[i+2] * ... * A[n-1]
        则B[i] = C[i] * D[i]，而C[i] = C[i-1] * A[i-1]，D[i] = D[i+1] * A[i+1]
        时间复杂度O(n)
*/

class Solution
{
  public:
    vector<int> multiply(const vector<int> &A)
    {
        const int size = A.size();  // size即n
        if (size == 0)
            return vector<int>();

        vector<int> B(size, 0);

        B[0] = 1;
        for (int i = 1; i < size; i++)  // 先算C[i]
            B[i] = B[i - 1] * A[i - 1];

        double temp = 1;
        for (int j = size - 2; j >= 0; j--)   // 再算D[i]
        {
            temp *= A[j + 1];
            B[j] *= temp;
        }

        return B;
    }
};