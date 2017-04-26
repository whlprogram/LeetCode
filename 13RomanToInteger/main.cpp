/*
罗马数字共有七个，即I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)。按照下面的规则可以表示任意正整数。

重复数次：一个罗马数字重复几次，就表示这个数的几倍。

右加左减：
在一个较大的罗马数字的右边记上一个较小的罗马数字，表示大数字加小数字。
在一个较大的数字的左边记上一个较小的罗马数字，表示大数字减小数字。
但是，左减不能跨越等级。比如，99不可以用IC表示，用XCIX表示。

加线乘千：在一个罗马数字的上方加上一条横线或者在右下方写M，表示将这个数字乘以1000，即是原数的1000倍。同理，如果上方有两条横线，即是原数的1000000倍。

单位限制：同样单位只能出现3次，如40不能表示为XXXX，而要表示为XL。
*/
/*
思路1：
组合规则：
(1) 基本数字 Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
(2) 不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
(3) V 和 X 左边的小数字只能用 Ⅰ。
(4)L 和 C 左边的小数字只能用 ×。
(5)D 和 M 左 边的小数字只能用 C 。

还有一点需要格外注意 MCM是1900 MCMXCVI是1996
也就是按照逻辑 遍历到C 的处理，MC先M+C，但是遍历到第二个M的时候，顺序是CM，这个时候要减去这个C以及之前多加的C，也就是减去两个C。
*/
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //116ms
    int romanToInt(string s) {//从左往右 参考 https://segmentfault.com/a/1190000002683379
        if(s.length()<=1)
            return charToInt(s[0]);
        int res = charToInt(s[0]);
        for(int i=1; i<s.length(); i++){
            if(charToInt(s[i])>charToInt(s[i-1]))
                res = res + charToInt(s[i]) - 2*charToInt(s[i-1]);
            else
                res += charToInt(s[i]);
        }
        return res;
    }
    //89ms
    int romanToInt1(string s) {//从右往左 参考 http://blog.csdn.net/booirror/article/details/43197595
        if(s.length()<=1)
            return charToInt(s[0]);
        int res = 0;
        char maxChar = 'I';
        for(int i=s.size()-1; i>=0; --i){
            if(charToInt(s[i])>=charToInt(maxChar)){
                maxChar = s[i];
                res += charToInt(s[i]);
            }
            else
                res -= charToInt(s[i]);
        }
        return res;
    }
    int charToInt(char s){
        /*if(s==' ') return 0;
        if(s=='I')  return 1;
        if(s=='V')  return 5;
        if(s=='X')  return 10;
        if(s=='L')  return 50;
        if(s=='C')  return 100;
        if(s=='D')  return 500;
        if(s=='M')  return 1000;*/

        switch (s) {
        		case 'I': 	return 1;
        		case 'V':	return 5;
        		case 'X':	return 10;
        		case 'L':	return 50;
        		case 'C':	return 100;
        		case 'D':	return 500;
        		case 'M':	return 1000;
        		default:	return 0;
        	}
    }
    //52ms
    int romanToInt2(string s){//参考 http://blog.csdn.net/nomasp/article/details/49154161
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ((i < s.size()-1) && (map[s[i]] < map[s[i+1]])) {
                res -= map[s[i]];
            }
            else {
                res += map[s[i]];
            }
        }
        return res;
    }


};
int main()
{
    Solution a;
    string s;
    cin >> s;
    cout << a.romanToInt1(s) << endl;
    return 0;
}
