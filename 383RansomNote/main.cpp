#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        //考虑了大小写字母，如果只考虑小写字母把128改成26 下面验证的每个字符-97就好
        vector <int> res(128, 0);//A-Z 65-90 a-z 97-122
        for(char m : magazine)
            res[m]++;
        for(char r : ransomNote){
            if(res[r] == 0)
                return false;
            res[r]--;
        }
        return true;
    }
};
int main()
{
    Solution a;
    string ransomNote,magazine;
    cin >> ransomNote >> magazine;
    cout << a.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
