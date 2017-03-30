#include <iostream>

using namespace std;
class Solution {
public:
    int addDigits(int num) {//递归
        int sum = 0;
        if(num < 10 && num >=0)
            return num;
        while(num > 0)
        {
            int temp = num%10;
            sum += temp;
            num /= 10;
        }
        while(sum >= 10)
            return addDigits(sum);
        return sum;
    }
    int addDigits1(int num) {
        while(num >= 10){
           num = (num/10)+num%10;
        }
        return num;
    }
    int addDigits2(int num) {
        return 1+(num-1)%9;
    }
};
int main()
{
    Solution a;
    cout << a.addDigits2(299) << endl;
    return 0;
}
