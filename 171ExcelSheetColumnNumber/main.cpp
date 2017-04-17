#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++)
            res = res*26 + (s[i]-'A'+1);//A-Z Ê®½øÖÆ65-90   A-'A'=0 A-'A'+1=1 B-'A'+1=2
        return res;
    }
};
int main()
{
    Solution a;
    string s;
    cin >> s;
    cout << a.titleToNumber(s) << endl;
    return 0;
}
