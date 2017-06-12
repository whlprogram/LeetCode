//原题链接https://leetcode.com/problems/climbing-stairs/#/description
//题解 http://blog.csdn.net/whl_program/article/details/73122809
#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        double res=0;//记录爬楼梯方式的数量 必须用double 否则会出现误差
        //one一步一个台阶的次数  two一步两个台阶的次数
        for(int one=n,two=0; (one>=0)&&(two<=n/2); one-=2,two++){
            if(one==0 || two==0)
                res += 1;
            else{
                double temp = factorial(one+two)/(factorial(one)*factorial(two)); //必须用double 否则会出现误差
                res += temp;
            }
        }
        return res;
    }
    double factorial(int n){
        if(n==0) return 1;//0的阶乘是0
        double res = 1;
        for(int i=2; i<=n; i++)
            res*=i;
        return res;
    }

    int climbStairs1(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        //one_step_before表示最后一步登顶跨出一个台阶的方法数
        //two_steps_before表示最后一步登顶跨出两个台阶的方法数
        //总方法数all_ways = one_step_before + two_steps_before
        //n=3时  对one_step_before,two_steps_before初始化
        int one_step_before = 2;
        int two_steps_before = 1;
        int all_ways = 0;//记录爬楼梯方式的总数
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
