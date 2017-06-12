//ԭ������https://leetcode.com/problems/climbing-stairs/#/description
//��� http://blog.csdn.net/whl_program/article/details/73122809
#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        double res=0;//��¼��¥�ݷ�ʽ������ ������double �����������
        //oneһ��һ��̨�׵Ĵ���  twoһ������̨�׵Ĵ���
        for(int one=n,two=0; (one>=0)&&(two<=n/2); one-=2,two++){
            if(one==0 || two==0)
                res += 1;
            else{
                double temp = factorial(one+two)/(factorial(one)*factorial(two)); //������double �����������
                res += temp;
            }
        }
        return res;
    }
    double factorial(int n){
        if(n==0) return 1;//0�Ľ׳���0
        double res = 1;
        for(int i=2; i<=n; i++)
            res*=i;
        return res;
    }

    int climbStairs1(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        //one_step_before��ʾ���һ���Ƕ����һ��̨�׵ķ�����
        //two_steps_before��ʾ���һ���Ƕ��������̨�׵ķ�����
        //�ܷ�����all_ways = one_step_before + two_steps_before
        //n=3ʱ  ��one_step_before,two_steps_before��ʼ��
        int one_step_before = 2;
        int two_steps_before = 1;
        int all_ways = 0;//��¼��¥�ݷ�ʽ������
        for(int i=2; i<n; i++){
            all_ways = one_step_before + two_steps_before;
            two_steps_before = one_step_before;
            one_step_before = all_ways;
        }
        return all_ways;
    }

};
int main()
{
    Solution s;
    int a = 0;
    cin >> a;
    cout << s.climbStairs1(a) << endl;
    return 0;
}
