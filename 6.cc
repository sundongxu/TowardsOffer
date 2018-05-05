/*
    题目：
        在升序旋转数组中找到最小元素
    思路：
        二分查找
*/
class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        // 局部有序，用二分
        int left = 0, right = rotateArray.size() - 1;

        if (left == right) // size == 0
            return 0;
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (rotateArray[left] > rotateArray[mid])
            {
                // 最小值一定在left到mid之间，但是一定不是left，从left+1到mid
                right = mid;
                left++;
            }
            else if (rotateArray[mid] > rotateArray[right])
                // 最小值一定在mid和right之间，但一定不是mid，从mid+1到right
                left = mid + 1;
            else
                break;
        }
        return rotateArray[left];
    }
};