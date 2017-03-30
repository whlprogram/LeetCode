#include <iostream>

using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        //递归算法
        if(b==0)
            return a;
        int m = a^b;
        int c = (a&b) << 1;//计算进位
        return getSum(c,m);
    }
    int getSum1(int a, int b) {
        while(b)//b不为0时进入循环
        {
            int m = a^b;
            b = (a&b) << 1;//计算进位
            a = m;
        }
        return a;
    }
};
int main()
{
    Solution A;
    cout << A.getSum1(5,8) << endl;
    return 0;
}
