/*
 * 原题链接: https://leetcode.com/problems/reverse-string-ii/#/description
 * 给定一个字符串和一个整数k，你需要反转从字符串开始计数的每2k个字符的前k个字符。
 * 如果剩余少于k个字符，则将剩余的所有字符都反转。
 * 如果小于2k但大于或等于k个字符，则反转前k个字符，并将另一个作为原始字符
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {//9ms
        int sLength = s.length();
        //cout << "sLength = " << sLength << endl;
        int business = sLength/(2*k);//商
        //cout << "business = " << business << endl;
        int remainder = sLength - business*k*2;//余数
        //cout << "remainder = " << remainder << endl;
        for(int i=0; i<business; i++){
            for(int m=0,sta=i*k*2; m<k/2; m++){//翻转每2K个字符的前K个字符
                char temp = s[sta];
                s[sta] = s[sta+ k-1 - m*2];
                s[sta+ k-1 - m*2] = temp;
                sta++;
            }
        }
        if(remainder<k){//剩余少于k个字符,将所有字符都反转 (剩余必定小于2k个字符)
            for(int m=0,sta=business*k*2; m<remainder/2; m++){
                char temp = s[sta];
                s[sta] = s[sta+ remainder-1 - m*2];
                s[sta+ remainder-1 - m*2] = temp;
                sta++;
            }
        }
        else{//小于2k但大于或等于k个字符,反转前k个字符
            for(int m=0,sta=business*k*2; m<k/2; m++){//翻转前K个字符
                char temp = s[sta];
                s[sta] = s[sta+ k-1 - m*2];
                s[sta+ k-1 - m*2] = temp;
                sta++;
            }
        }
        return s;
    }
    string reverseStr1(string s, int k) {//6ms
        int sLength = s.length();
        int business = sLength/(2*k);//商
        int remainder = sLength - business*k*2;//余数
        for(int i=0; i<business; i++){
            reverseK(s, i*k*2, k);//翻转每2K个字符的前K个字符
        }
        if(remainder<k){//剩余少于k个字符,将所有字符都反转 (剩余必定小于2k个字符)
            reverseK(s, business*k*2, remainder);
        }
        else{//小于2k但大于或等于k个字符,反转前k个字符
            reverseK(s, business*k*2, k);//翻转前K个字符
        }
        return s;
    }
    void reverseK(string &s, int sta, int k){//翻转字符串第sta位置后的K个元素
        for(int m=0; m<k/2; m++){
                char temp = s[sta];
                s[sta] = s[sta+ k-1 - m*2];
                s[sta+ k-1 - m*2] = temp;
                sta++;
        }
    }
};
int main()
{
    //if(-1)//0为false 非0为true
    //    cout << "s = 1" << endl;
    //else
    //    cout << "s = 0" << endl;
    Solution a;
    string s;
    cin >> s;
    cout << "s = " << s << endl;
    cout << "翻转后s = " << a.reverseStr1(s, 4) << endl;
    return 0;
}
