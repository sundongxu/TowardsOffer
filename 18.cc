/*
    题目：《剑指Offer-面试题20-顺时针打印矩阵》
        顺时针(螺旋)打印矩阵
    思路：
        四个指针记录横向起始和终止位置和纵向起始于终止位置
*/
class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> result;
        const int n = matrix.size();    // 行数
        const int m = matrix[0].size(); // 列数
        if (m == 0)
            return result;
        int startX = 0, endX = m - 1, startY = 0, endY = n - 1;
        while (true)
        {
            // 横向，从左往右
            for (int j = startX; j <= endX; j++)
                result.push_back(matrix[startY][j]);
            if (++startY > endY) // startY这一行处理完，如已经到底则跳出
                break;
            // 纵向，从上往下
            for (int i = startY; i <= endY; i++)
                result.push_back(matrix[i][endX]);
            if (--endX < startX) // endX这一列处理完，如已经到底则跳出
                break;
            // 横向，从右往左
            for (int j = endX; j >= startX; j--)
                result.push_back(matrix[endY][j]);
            if (--endY < startY)
                break;
            // 纵向，从下往上
            for (int i = endY; i >= startY; i--)
                result.push_back(matrix[i][startX]);
            if (++startX > endX)
                break;
        }
        return result;
    }
};