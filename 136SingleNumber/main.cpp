#include <iostream>
#include <vector>
using namespace std;
/*
1、交换律 (a^b  = b^a)
2、结合律（即(a^b)^c = a^(b^c)）
3、对于任何数x，都有x^x=0，x^0=x  所以 x^y^x = y
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
            return nums[0];
        int a = 0;
        for(int i=0;i<length;i++){
            a ^= nums[i];//利用异或性质3
        }
        return a;
    }
};
int main()
{
    if(1)//不同为1
        cout << "Hello world!" << endl;
    return 0;
}
