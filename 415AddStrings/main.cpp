//原题链接 https://leetcode.com/problems/add-strings/#/description
//博客题解 http://blog.csdn.net/whl_program/article/details/72804115
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {//错误 只能运行在int范围内  题目要求num1和num2长度小于5100
        int NUM1 = stringToInt(num1);
        cout << NUM1 << endl;
        int NUM2 = stringToInt(num2);
        cout << NUM2 << endl;
        return intToString(NUM1+NUM2);
    }
    string intToString(int i){//整数转化为字符串
        string s = "";
        if(i < 0)
            return "-1";
        if(i == 0)
            s = "0";
        while(i > 0){
            int temp = i%10;
            s = intToChar(temp) + s;
            i /= 10;
        }
        return s;
    }
    int stringToInt(string s){//字符串转化为整数
        int Length = s.size();
        int t = 1;
        int num = 0;
        for(int i=Length-1; i>=0; i--){
            int temp = charToInt(s[i]);
            num += temp*t;
            t *= 10;
        }
        return num;
    }
    int charToInt(char c){//字符转化为整数
        char charArray[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i=0; i<=9; i++){
            if((charArray[i]^c) == 0){// ^ 优先级小于 ==， 必须在charArray[i]^c外加括号
                return i;
            }
        }
        return -1;
    }
    char intToChar(int i){//整数转化为字符
        char charArray[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int m=0; m<=9; m++){
            if((m^i) == 0){// ^ 优先级小于 ==， 必须在charArray[i]^c外加括号
                return charArray[m];
            }
        }
        return '-1';
    }

    string addStrings1(string num1, string num2) {//正确  但是效率太低 12ms
        int length1 = num1.size();
        int length2 = num2.size();
        if(length1>length2)
            return addStrings2(num1, num2, length1, length2);
        else if(length1<length2)
            return addStrings2(num2, num1, length2, length1);
        else{//两个字符串长度相等
            int a =0;
            string res = addStr(num1, num2, a);
            if(a == 1){
                return '1'+res;
            }
            return res;
        }
    }
    string addStrings2(string Max, string Min, int MaxLength, int MinLength){//两个长度不相等的字符串相加
        string res = "";
        string LString =  "";
        string RString =  "";
        int t = MaxLength-MinLength;
        for(int i=0; i<MaxLength; i++){//将长字符串分为左右两部分
            if(i<t)
                LString += Max[i];
            else
                RString += Max[i];
        }

        int a = 0;
        res = addStr(Min, RString, a) + res;//将右半部分和短字符串相加赋值给res
        if(a == 1){//右半部分和短字符串相加有进位
            string tempA = "1";
            for(int j=0; j<LString.size()-1; j++)
                tempA = '0' + tempA;
            a = 0;
            LString = addStr(LString, tempA, a);//左半部分和进位相加
            if(a == 1)//左半部分和进位相加仍然有进位
                LString = '1' + LString;
        }
        res = LString + res;
        return res;
    }
    string addStr(string num1, string num2, int &a){//相同字符串长度相加,a代表是否有进位
        string res = "";
        for(int i=num1.size()-1; i>=0; i--){
            int temp = charToInt(num1[i]) + charToInt(num2[i]) + a;
            if(temp < 10){
                a =0;
                res = intToChar(temp) + res;
            }
            else{
                a = 1;
                res = intToChar(temp%10) + res;
            }
        }
        return res;
    }


    string addStrings3(string num1, string num2) {//速度最快3ms
        string res = "";
        int add=0,i=num1.size()-1,j=num2.size()-1;
        while(i>=0 || j>=0 || add>0)
        {
            int cur=add;
            cur+=(i>=0?num1[i--]-'0':0);
            cur+=(j>=0?num2[j--]-'0':0);
            add=cur/10;//用来判断是否有进位
            cur%=10;
            res+=('0'+cur);
        }
        reverse(res.begin(), res.end());//翻转字符串
        return res;
    }
};
int main()
{
    Solution S;
    string num1 = "13423452345345";
    string num2 = "93423423423423423";
    cout << S.addStrings3(num1, num2) << endl;
    return 0;
}
