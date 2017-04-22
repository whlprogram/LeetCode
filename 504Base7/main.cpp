#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string res = "";
        int NUM = abs(num);//È¡¾ø¶ÔÖµ
        while(NUM != 0){
            int tmp = NUM%7;
            NUM = NUM/7;
            res = to_string(tmp) + res;
        }
        if(num < 0)
            return "-"+res;
        return res;
    }
};
int main()
{
    string res1 = "123";
    string res2 = "456";
    cout << res2+res1 << endl;
    cout << "-"+res2 << endl;
    Solution a;
    int num = 0;
    cin >> num;
    cout << a.convertToBase7(num) << endl;
    return 0;
}
