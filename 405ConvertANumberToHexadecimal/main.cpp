#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    string toHex(int num) {//3ms
        if(num == 0)
            return "0";
        if(num == -2147483648)//���ڲ���ķ�Χ�ǲ��ԳƵ� |TMin| = |TMax|+1  ����TMinû����֮��Ӧ������
            return "80000000";
        string res = "";
        int NUM = abs(num);//ȡ����ֵ
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
    string help(string s){//����ԭ��ȡ��+1
        int sL = s.size()-1,add=1;
        string Res = "";
        while(sL>=0 || add>0)
        {
            int cur=add;
            cur+=sL>=0?(15-reInt(s[sL--])):0;//���� = ԭ��ȡ��+1
            add=cur/16;//�����ж��Ƿ��н�λ
            cur%=16;
            Res=Hex[cur]+Res;
        }
        if(s.size()<8){
            for(int i=1; i<=8-s.size(); i++)
                Res = 'f' + Res;
        }
        return Res;
    }
    int reInt(char c){//���ڷ���ʮ�������е����ַ����������
        for(int i=0; i<=15; i++)
            if(c == Hex[i])
                return i;
        return -1;
    }

    string toHex1(int num) {//0ms ���ⷨ
        string result = "";
        if (num == 0) {
            return "0";
        }
        int count = 0;
        while (num != 0 && count < 8) {
            result = hex[(num & 0xf)] + result;//& λ������AND
            // << >> ��λ����
            // <<k ���� �����ƶ�kλ��������ߵ�kλ�������Ҷ˲�k��0
            // >>k �������ƺ��߼�����  �߼���������˲�k��0
            //�������еı��������з�������֧����������
            num >>= 4;//num>>4 �������� num������4λ������˲�4�������Чλ��ֵ
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
