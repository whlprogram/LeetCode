#include <iostream>

using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        //�ݹ��㷨
        if(b==0)
            return a;
        int m = a^b;
        int c = (a&b) << 1;//�����λ
        return getSum(c,m);
    }
    int getSum1(int a, int b) {
        while(b)//b��Ϊ0ʱ����ѭ��
        {
            int m = a^b;
            b = (a&b) << 1;//�����λ
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
