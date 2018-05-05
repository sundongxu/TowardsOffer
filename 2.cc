/*
    题目：
        请实现一个函数，将一个字符串中的空格替换成“%20”。
        例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    思路：
        双指针，O(n)复杂度
*/
class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        // length是新str最大长度
        int numOfBlank = 0;
        int originalLen = 0, newLen = 0;
        char *p = str;
        // 遍历字符串，记录空格数量
        while (*p != '\0')
        {
            originalLen++;
            if (*p == ' ')
                numOfBlank++;
            p++;
        }
        newLen = originalLen + numOfBlank * 2;
        if (newLen > length)
            return;

        int indexOfOriginal = originalLen;
        int indexOfNew = newLen;
        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if (str[indexOfOriginal] == ' ')
            {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            }
            else
            {
                str[indexOfNew--] = str[indexOfOriginal];
            }
            indexOfOriginal--;
        }
    }
};