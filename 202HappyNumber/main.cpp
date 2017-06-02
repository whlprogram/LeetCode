//ԭ������ https://leetcode.com/problems/happy-number/#/description
#include <iostream>

using namespace std;
class Solution {
public:
    //�㷨���ͣ� https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
    bool isHappy(int n) {//3ms
        if(n <= 0)//ȷ��nΪ������
            return false;
        int slow=n, fast=n;
        do{
           slow = digitSquaresSum(slow);//��ָ��
           fast = digitSquaresSum(fast);
           fast = digitSquaresSum(fast);//��ָ�� ����ָ���ִ��һ��digitSquaresSum����
        }while(slow != fast);//��ָ��Ϳ�ָ������ͬ������ѭ��
        if(slow == 1)
            return true;
        else
            return false;
    }
    int digitSquaresSum(int n){//����ƽ����
        int squares = 0;
        while(n != 0){
            int temp = n%10;
            squares += (temp*temp);
            n = n/10;
        }
        return squares;
    }

    //���ⷨ
    //������1-9,����ֻ��1��7�ܷ���true,��������false
    //�������е�squares����С��10
    bool isHappy1(int n) {//0ms
        if(n == 0) return 0;
        int squares = n;
        while(squares >= 10){
            int temp = 0;
            while(squares) {
                temp += (squares%10)*(squares%10);
                squares = squares/10;
            }
            squares = temp;
        }

        if(squares == 1 || squares == 7)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    int n = 0;
    cout << "������һ������: ";
    cin >> n;
    cout << "n�Ƿ��� happy number : " << s.isHappy(n) << endl;
    return 0;
}
