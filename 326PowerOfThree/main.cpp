#include <iostream>

using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0 || n>2147483647)//3的幂最小是1  int最大为2147483647
            return false;
        // 1162261467 is 3^19,  3^20 is bigger than int
        return 1162261467%n==0;
    }
};
int main()
{
    Solution s;
    int a =0;
    cin >> a;
    cout << s.isPowerOfThree(a) << endl;
    return 0;
}
