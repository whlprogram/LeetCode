#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())//判断两个字符串长度是否相同
            return false;
        if(s.size() == 0)//判断两个字符串长度是否为空
            return true;
        sort(s.begin(), s.end());//将两个字符串排序
        sort(t.begin(), t.end());
        bool res;
        for(int i=0; i<s.size(); i++){
            res = s[i]^t[i];//相同为0 不同为1
            if(res == 1)
                return false;
        }
        return true;
    }
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());//将两个字符串排序
        sort(t.begin(), t.end());
        return s == t;
    }
    bool isAnagram2(string s, string t) {
        if(s.size() != t.size())//判断两个字符串长度是否相同
            return false;
        int counts[26] = {0};
        for(int i=0; i<s.size(); i++){
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for(int m=0; m<26; m++){
            if(counts[m])//counts[m]!=0
                return false;
        }
        return true;
    }
};
int main()
{
    //0 false; 1 true
    //异或 相同为0 不同为1
    /*
    char a0 = 'a';
    char a1 = 'b';
    char a2 = 'a';
    bool b = a0^a1;//1 bool类型
    int b1 = a0^a1;//3 int类型
    bool c = a0^a2;//0
    bool d = (a0^a1)^(a1^a0);//0
    b ^= (a1^a0);//1
    b1 ^= (a1^a0);//0
    cout << b << c << d << b1<< endl;//1 0 0 0
    */
    Solution a;
    string s = "aa";
    string t = "bb";
    string s1 = "ab";
    string t1 = "ba";
    cout << a.isAnagram(s, t) << endl;
    cout << a.isAnagram(s1, t1) << endl;
    return 0;
}
