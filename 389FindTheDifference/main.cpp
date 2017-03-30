#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        for(int i=0;i<s_length;i++)//遍历字符串s
        {
            for(int j=0;j<t_length;j++)//遍历字符串t
            {
                if(s[i] == t[j])//若在字符串t中 找到与 字符串s中元素 相同的字符
                {
                    t[j] = '0';//将t中该元素赋值'0'
                    break;//并结束遍历字符串t
                }
            }

        }
        for(int m=0;m<t_length;m++)//遍历字符串t
        {
            if(t[m] != '0')//找到没有被赋值为'0'的元素 返回该值
                return t[m];
        }
        return t[s_length];
    }
    //运用Hash表
    char findTheDifference1(string s, string t) {
        int a[26] = {0}, lens = s.length(), lent = t.length(), i;
        for(i = 0; i < lens; i++)
            a[s[i] - 'a']++;
        for(i = 0; i < lent; i++)
            if(a[t[i] - 'a'] <= 0)
                break;
            else
                a[t[i] - 'a']--;
        return t[i];
    }
    //运用异或
    /*char findTheDifference2(string s, string t) {
        s += t;
        int ch =0;
        for(auto val: s)
            ch ^= val;
        return ch;
    }*/
};
int main()
{
    Solution a;
    cout << a.findTheDifference1("aa", "aea") << endl;
    return 0;
}
