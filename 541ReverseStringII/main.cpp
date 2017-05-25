/*
 * ԭ������: https://leetcode.com/problems/reverse-string-ii/#/description
 * ����һ���ַ�����һ������k������Ҫ��ת���ַ�����ʼ������ÿ2k���ַ���ǰk���ַ���
 * ���ʣ������k���ַ�����ʣ��������ַ�����ת��
 * ���С��2k�����ڻ����k���ַ�����תǰk���ַ���������һ����Ϊԭʼ�ַ�
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {//9ms
        int sLength = s.length();
        //cout << "sLength = " << sLength << endl;
        int business = sLength/(2*k);//��
        //cout << "business = " << business << endl;
        int remainder = sLength - business*k*2;//����
        //cout << "remainder = " << remainder << endl;
        for(int i=0; i<business; i++){
            for(int m=0,sta=i*k*2; m<k/2; m++){//��תÿ2K���ַ���ǰK���ַ�
                char temp = s[sta];
                s[sta] = s[sta+ k-1 - m*2];
                s[sta+ k-1 - m*2] = temp;
                sta++;
            }
        }
        if(remainder<k){//ʣ������k���ַ�,�������ַ�����ת (ʣ��ض�С��2k���ַ�)
            for(int m=0,sta=business*k*2; m<remainder/2; m++){
                char temp = s[sta];
                s[sta] = s[sta+ remainder-1 - m*2];
                s[sta+ remainder-1 - m*2] = temp;
                sta++;
            }
        }
        else{//С��2k�����ڻ����k���ַ�,��תǰk���ַ�
            for(int m=0,sta=business*k*2; m<k/2; m++){//��תǰK���ַ�
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
        int business = sLength/(2*k);//��
        int remainder = sLength - business*k*2;//����
        for(int i=0; i<business; i++){
            reverseK(s, i*k*2, k);//��תÿ2K���ַ���ǰK���ַ�
        }
        if(remainder<k){//ʣ������k���ַ�,�������ַ�����ת (ʣ��ض�С��2k���ַ�)
            reverseK(s, business*k*2, remainder);
        }
        else{//С��2k�����ڻ����k���ַ�,��תǰk���ַ�
            reverseK(s, business*k*2, k);//��תǰK���ַ�
        }
        return s;
    }
    void reverseK(string &s, int sta, int k){//��ת�ַ�����staλ�ú��K��Ԫ��
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
    //if(-1)//0Ϊfalse ��0Ϊtrue
    //    cout << "s = 1" << endl;
    //else
    //    cout << "s = 0" << endl;
    Solution a;
    string s;
    cin >> s;
    cout << "s = " << s << endl;
    cout << "��ת��s = " << a.reverseStr1(s, 4) << endl;
    return 0;
}
