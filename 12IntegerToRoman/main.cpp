/*
I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)
组合规则：
(1) 基本数字 Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
(2) 不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
(3) V 和 X 左边的小数字只能用 Ⅰ。
(4)L 和 C 左边的小数字只能用 ×。
(5)D 和 M 左 边的小数字只能用 C 。


*/
#include <iostream>

using namespace std;
class Solution {//参考 https://discuss.leetcode.com/topic/12384/simple-solution
public:
    string intToRoman(int num) {//整数转化为罗马数字
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
