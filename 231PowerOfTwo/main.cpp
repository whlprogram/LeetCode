//原题链接 https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description
//题解 http://blog.csdn.net/whl_program/article/details/72972961
#include <iostream>

using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0 || n>2147483647)//2的幂最小是1  int最大为2147483647
            return false;
        while(n != 1){
            if(n%2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};
int main()
{
    Solution s;
    int a =0;
    cin >> a;
    cout << s.isPowerOfTwo(a) << endl;
    return 0;
}
