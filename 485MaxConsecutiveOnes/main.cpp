#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0;//��������1��������
        int Min = 0;//��ʱ�洢����1�ĸ���
        int length = nums.size();//���鳤��
        /*if (length == 1)//��Ԫ������
        {
            if(nums[0])//Ԫ��Ϊ1
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
            if(!nums[i])//Ԫ��Ϊ0
            {
                if(Min > Max)//��ʱ�洢����1�ĸ�����֮ǰ�Ĵ����¸�Max��ֵ������Min
                {
                    Max = Min;
                    /*Min = 0;//����Min
                    continue;*/
                }
                Min = 0;//����Min
                continue;
            }
            if(nums[i])//Ԫ��Ϊ1
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
    if(a)//Ԫ��Ϊ1
    {
        cout << "aΪ1" << endl;
    }
    if(!a)//Ԫ��Ϊ0
    {
        cout << "aΪ0" << endl;
    }
    return 0;
}
