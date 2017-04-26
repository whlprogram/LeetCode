/*
�������ֹ����߸�����I(1)��V(5)��X(10)��L(50)��C(100)��D(500)��M(1000)����������Ĺ�����Ա�ʾ������������

�ظ����Σ�һ�����������ظ����Σ��ͱ�ʾ������ļ�����

�Ҽ������
��һ���ϴ���������ֵ��ұ߼���һ����С���������֣���ʾ�����ּ�С���֡�
��һ���ϴ�����ֵ���߼���һ����С���������֣���ʾ�����ּ�С���֡�
���ǣ�������ܿ�Խ�ȼ������磬99��������IC��ʾ����XCIX��ʾ��

���߳�ǧ����һ���������ֵ��Ϸ�����һ�����߻��������·�дM����ʾ��������ֳ���1000������ԭ����1000����ͬ������Ϸ����������ߣ�����ԭ����1000000����

��λ���ƣ�ͬ����λֻ�ܳ���3�Σ���40���ܱ�ʾΪXXXX����Ҫ��ʾΪXL��
*/
/*
˼·1��
��Ϲ���
(1) �������� ��X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
(2) ���ܰѻ������� V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
(3) V �� X ��ߵ�С����ֻ���� ��
(4)L �� C ��ߵ�С����ֻ���� ����
(5)D �� M �� �ߵ�С����ֻ���� C ��

����һ����Ҫ����ע�� MCM��1900 MCMXCVI��1996
Ҳ���ǰ����߼� ������C �Ĵ���MC��M+C�����Ǳ������ڶ���M��ʱ��˳����CM�����ʱ��Ҫ��ȥ���C�Լ�֮ǰ��ӵ�C��Ҳ���Ǽ�ȥ����C��
*/
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //116ms
    int romanToInt(string s) {//�������� �ο� https://segmentfault.com/a/1190000002683379
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
    int romanToInt1(string s) {//�������� �ο� http://blog.csdn.net/booirror/article/details/43197595
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
    int romanToInt2(string s){//�ο� http://blog.csdn.net/nomasp/article/details/49154161
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
