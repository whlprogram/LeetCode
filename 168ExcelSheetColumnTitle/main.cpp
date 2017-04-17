#include <iostream>

using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        if(n == 0)
            return s;
        else
            //return convertToTitle(n/26) + char((n-1)%26+'A');//n=26Ê± return AZ ´íÎó
            return convertToTitle((n-1)/26) + char((n-1)%26+'A');
    }
};
int main()
{
    Solution a;
    int n;
    cin >> n;
    cout << a.convertToTitle(n) << endl;
    return 0;
}
