#include <iostream>
#include <string>
using namespace std;
class Solution {//‘≠Ã‚ https://leetcode.com/problems/student-attendance-record-i/#/description
public:
    bool checkRecord(string s) {
        if(s.size() <= 1)
            return true;
        int Acount = 0;
        int ContinuousLcount = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'A'){
               Acount++;
               ContinuousLcount = 0;
            }
            else if(s[i] == 'L')
                ContinuousLcount++;
            else
                ContinuousLcount = 0;
            if(Acount>1 || ContinuousLcount>2)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution a;
    string s;
    cin >> s;
    cout << s.size() << endl;
    //cout << true << endl; //1
    //cout << false << endl; //0
    cout << a.checkRecord(s) << endl;
    return 0;
}
