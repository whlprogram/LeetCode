#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++)
        {//将所有非零值移到前面
            if(nums[i] != 0)
            {
               nums[j] = nums[i];
               j += 1;
            }
        }
        for(; j<nums.size(); j++)//剩下元素的全部赋值为0
            nums[j] = 0;
    }
    void moveZeroes1(vector<int>& nums) {
        int j = 0;
        int num = nums.size();
        for(int i=0; i<num; i++)
        {
            if(nums[i] != 0)
            {
               nums[j] = nums[i];//非零值 移位
               if(i != j)
               {//将移动的元素之前的位置赋值0
                   nums[i] = 0;
               }
               j += 1;
            }
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
