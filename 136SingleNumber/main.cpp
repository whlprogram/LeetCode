#include <iostream>
#include <vector>
using namespace std;
/*
1�������� (a^b  = b^a)
2������ɣ���(a^b)^c = a^(b^c)��
3�������κ���x������x^x=0��x^0=x  ���� x^y^x = y
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
            return nums[0];
        int a = 0;
        for(int i=0;i<length;i++){
            a ^= nums[i];//�����������3
        }
        return a;
    }
};
int main()
{
    if(1)//��ͬΪ1
        cout << "Hello world!" << endl;
    return 0;
}
