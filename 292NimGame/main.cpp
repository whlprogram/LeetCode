#include <iostream>

using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4 == 0 && n)
            return false;
        return true;
    }
};
int main()
{
    Solution a;
    cout << a.canWinNim(0) << endl;
    return 0;
}
