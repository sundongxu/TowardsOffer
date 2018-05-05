/*
    题目：
        调整数组元素顺序，使得奇数元素全在偶数元素之前
        且不能改变奇数与奇数、偶数与偶数之间原本的相对关系
    思路：
        见以下两种方法注释
*/

// 第一个思路：类似冒泡排序
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {

        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) // 前偶后奇交换
                {
                    swap(array[j], array[j - 1]);
                }
            }
        }
    }
};

//第二个思路：再创建一个数组
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {

        vector<int> temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();

        for (; ib1 != array.end();)
        {
            //遇见偶数，就保存到新数组，同时从原数组中删除
            if (*ib1 % 2 == 0)
            {
                temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else
            {
                ib1++;
            }
        }
        vector<int>::iterator ib2, ie2;
        ib2 = temp.begin();
        ie2 = temp.end();

        for (; ib2 != ie2; ib2++) //将新数组的数添加到老数组
        {
            array.push_back(*ib2);
        }
    }
};