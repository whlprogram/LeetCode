#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++)
        {//�����з���ֵ�Ƶ�ǰ��
            if(nums[i] != 0)
            {
               nums[j] = nums[i];
               j += 1;
            }
        }
        for(; j<nums.size(); j++)//ʣ��Ԫ�ص�ȫ����ֵΪ0
            nums[j] = 0;
    }
    void moveZeroes1(vector<int>& nums) {
        int j = 0;
        int num = nums.size();
        for(int i=0; i<num; i++)
        {
            if(nums[i] != 0)
            {
               nums[j] = nums[i];//����ֵ ��λ
               if(i != j)
               {//���ƶ���Ԫ��֮ǰ��λ�ø�ֵ0
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
