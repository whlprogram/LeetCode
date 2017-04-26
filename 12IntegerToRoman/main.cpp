/*
I(1)��V(5)��X(10)��L(50)��C(100)��D(500)��M(1000)
��Ϲ���
(1) �������� ��X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
(2) ���ܰѻ������� V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
(3) V �� X ��ߵ�С����ֻ���� ��
(4)L �� C ��ߵ�С����ֻ���� ����
(5)D �� M �� �ߵ�С����ֻ���� C ��


*/
#include <iostream>

using namespace std;
class Solution {//�ο� https://discuss.leetcode.com/topic/12384/simple-solution
public:
    string intToRoman(int num) {//����ת��Ϊ��������
        string M[] = {"", "M", "MM", "MMM"};//1000 - 3000
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//100 - 900
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//10 - 90
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//0 - 9
        return M[num/1000] + C[(num/100)%10] + X[(num/10)%10] + I[num%10];
    }
};
int main()
{
    Solution a;
    int num;
    cin >> num;
    cout << a.intToRoman(num) << endl;
    return 0;
}
