//原题链接 https://leetcode.com/problems/happy-number/#/description
#include <iostream>

using namespace std;
class Solution {
public:
    //算法解释： https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
    bool isHappy(int n) {//3ms
        if(n <= 0)//确保n为正整数
            return false;
        int slow=n, fast=n;
        do{
           slow = digitSquaresSum(slow);//慢指针
           fast = digitSquaresSum(fast);
           fast = digitSquaresSum(fast);//快指针 比慢指针多执行一次digitSquaresSum方法
        }while(slow != fast);//慢指针和快指针结果相同，跳出循环
        if(slow == 1)
            return true;
        else
            return false;
    }
    int digitSquaresSum(int n){//计算平方和
        int squares = 0;
        while(n != 0){
            int temp = n%10;
            squares += (temp*temp);
            n = n/10;
        }
        return squares;
    }

    //最快解法
    //测试了1-9,发现只有1和7能返回true,其他都是false
    //最终所有的squares都会小于10
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
    cout << "请输入一个数字: ";
    cin >> n;
    cout << "n是否是 happy number : " << s.isHappy(n) << endl;
    return 0;
}
