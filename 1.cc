/*
    题目：
        
    思路：
        
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