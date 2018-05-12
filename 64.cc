/*
    题目：《剑指Offer-面试题66-矩阵中的路径》
        请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径
        路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子
        如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子 
        例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
        但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
    思路：
        回溯法
*/

class Solution
{
  public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
            return false;

        bool *visited = new bool[rows * cols]; // 标志该矩阵方格是否被访问过，记得在回溯时需要还原
        memset(visited, false, rows * cols);

        int pathLength = 0;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete[] visited;
        visited = nullptr;
        return false;
    }

    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int &pathLength, bool *visited)
    {
        if (str[pathLength] == '\0') // 递归边界条件
            return true;

        bool hasPath = false;

        if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
        {
            ++pathLength;
            visited[row * cols + col] = true; // 将该方格设置为已访问
            hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
            if (!hasPath)
            {
                --pathLength;                      // 回溯
                visited[row * cols + col] = false; // 把该方格还原成未访问
            }
        }

        return hasPath;
    }
};