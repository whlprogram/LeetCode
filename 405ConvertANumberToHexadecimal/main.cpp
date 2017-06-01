#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    string toHex(int num) {//3ms
        if(num == 0)
            return "0";
        if(num == -2147483648)//由于补码的范围是不对称的 |TMin| = |TMax|+1  所以TMin没有与之对应的正数
            return "80000000";
        string res = "";
        int NUM = abs(num);//取绝对值
        while(NUM != 0){
            int temp = NUM%16;
            res = Hex[temp] + res;
            NUM = NUM/16;
        }
        if(num < 0){
            res = help(res);
        }
        return res;
    }
    string help(string s){//用于原码取反+1
        int sL = s.size()-1,add=1;
        string Res = "";
        while(sL>=0 || add>0)
        {
            int cur=add;
            cur+=sL>=0?(15-reInt(s[sL--])):0;//补码 = 原码取反+1
            add=cur/16;//用来判断是否有进位
            cur%=16;
            Res=Hex[cur]+Res;
        }
        if(s.size()<8){
            for(int i=1; i<=8-s.size(); i++)
                Res = 'f' + Res;
        }
        return Res;
    }
    int reInt(char c){//用于返回十六进制中单个字符代表的数字
        for(int i=0; i<=15; i++)
            if(c == Hex[i])
                return i;
        return -1;
    }

    string toHex1(int num) {//0ms 最快解法
        string result = "";
        if (num == 0) {
            return "0";
        }
        int count = 0;
        while (num != 0 && count < 8) {
            result = hex[(num & 0xf)] + result;//& 位级运算AND
            // << >> 移位运算
            // <<k 左移 向左移动k位，丢弃最高的k位，并在右端补k个0
            // >>k 算数右移和逻辑右移  逻辑右移在左端补k个0
            //几乎所有的编译器对有符号数都支持算数右移
            num >>= 4;//num>>4 算数右移 num向右移4位，往左端补4个最高有效位的值
            count++;
        }
        return result;
    }
private:
    char Hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    string hex = "0123456789abcdef";
};
int main()
{
    Solution S;
    int num = -2147483648;
    cout << "num to Hexadecimal is " << S.toHex(num) << endl;

    int a = 0xf;
    cout << "num & 0xf = " << (num & 0xf) <<endl;
    return 0;
}
