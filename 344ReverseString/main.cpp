#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        int a = s.size()-1;
        string b = "";
        for(int i=a;i>=0;i--)
            b += s[i];
        return b;
    }
};
int main()
{
    Solution a;
    cout << a.reverseString("sdfg") << endl;
    return 0;
}
