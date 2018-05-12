/*
    题目：《剑指Offer-面试题65-滑动窗口的最大值》
        给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
        例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口
        他们的最大值分别为{4,4,6,6,6,5}； 

        针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
        {[2,3,4],2,6,2,5,1}
        {2,[3,4,2],6,2,5,1}
        {2,3,[4,2,6],2,5,1}
        {2,3,4,[2,6,2],5,1}
        {2,3,4,2,[6,2,5],1}
        {2,3,4,2,6,[2,5,1]}
    思路：
        定义双端队列，存储是可能成为当前或此后的窗口最大值的元素在数组中的位置下标，且队头总是存储当前可能成为窗口最大值的数字中的最大值在数组中的位置下标
        
        每次新遍历一个数字
        判断其与队尾元素的大小关系，若大于等于，则也是可能成为某个窗口最大值的数字，删除原队尾元素
        若遍历到一个位置，队头元素与该位置的位置下标之差大于或等于窗口大小，则删去队头元素，因为它已经不可能成为当前或此后的窗口的最大值了
        上述判断后将该新数字加入到队尾
*/

class Solution
{
  public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> maxInWindows(num.size() - size);

        if (num.size() >= size && size >= 1)
        {
            deque<int> index; // 存储可能成为窗口最大值的元素的下标
            int i = 0;
            for (; i < size; i++) // 访问数组前size个元素
            {
                while (!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();

                index.push_back(i); // 存储的是可能成为窗口最大值的元素在数组中的下标
            }                       // 执行完这里队列index中只保留一个可能成为窗口最大值的元素

            // i == size
            for (; i < num.size(); i++)
            {
                maxInWindows.push_back(num[index.front()]); // 每滑动一个

                while (!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();

                if (!index.empty() && index.front() <= i - size)
                    index.pop_front();

                index.push_back(i);
            }

            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};