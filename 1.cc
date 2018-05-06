/* 
    题目：《剑指Offer-面试题3-二维数组中的查找》
    在一个二维数组中，
    每一行都按照从左到右递增的顺序排序，
    每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

    思路：
    总是选取矩阵右上角元素与目标元素比较
    （1）若大于目标元素，则剔除该元素所在的列
    （2）若小于目标元素，则剔除该元素所在的行
    也就是说，如果要查找的数字不在矩阵右上角，则每一次都可以在数组的查找范围内剔除一行或一列
    这样每步都可以缩小范围，直到找到要查找的数字(成功)，或查找范围为空(失败)
 */

class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        // 可用二分查找
        const int rows = array.size();
        if (rows == 0) // 0行
            return false;
        const int cols = array[0].size();
        if (cols == 0) // 0列
            return false;
        int startRow = 0, startCol = 0;
        int endRow = rows - 1, endCol = cols - 1;
        while (startRow <= endRow && startCol <= endCol)
        {
            int cur = array[startRow][endCol];
            if (cur == target)
                return true;
            else if (cur > target)
                endCol--;
            else
                startRow++;
        }
        return false;
    }
};