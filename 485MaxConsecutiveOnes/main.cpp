#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0;//定义连续1的最大个数
        int Min = 0;//暂时存储连续1的个数
        int length = nums.size();//数组长度
        /*if (length == 1)//单元素数组
        {
            if(nums[0])//元素为1
            {
                Max = 1;
                return Max;
            }
            else
            {
                Max = 0;
                return Max;
            }
        }*/
        for(int i=0;i<length;i++)
        {
            if(!nums[i])//元素为0
            {
                if(Min > Max)//暂时存储连续1的个数比之前的大，重新给Max赋值并重置Min
                {
                    Max = Min;
                    /*Min = 0;//重置Min
                    continue;*/
                }
                Min = 0;//重置Min
                continue;
            }
            if(nums[i])//元素为1
            {
                Min++;
            }
        }
        if(Min > Max)
            Max = Min;
        return Max;
    }
};
int main()
{
    int a = 0;
    if(a)//元素为1
    {
        cout << "a为1" << endl;
    }
    if(!a)//元素为0
    {
        cout << "a为0" << endl;
    }
    return 0;
}
