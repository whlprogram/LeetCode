#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //˼·1(���ʧ��)
    //1.�����������ͬԪ��ȫ�����ɡ�A��
    //2.Ѱ���������A��������г���
    //3.���رȽϱȵ�������г���
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        for(int m=0; m<a.length(); m++){
            for(int n=0; n<b.length(); n++){
                if(a[m] == b[n]){
                    a[m] = 'A';
                    b[n] = 'A';
                }
            }
        }
        int a_Max = NotA_findLSlength(a);
        int b_Max = NotA_findLSlength(b);
        return a_Max>b_Max ? a_Max : b_Max;
    }
    int NotA_findLSlength(string Array){
        int Max = 0;
        int temp = 0;
        for(int m=0; m<Array.length(); m++){
            if(Array[m] != 'A')
                ++temp;
            if(Array[m] == 'A' && temp > Max){
                Max = temp;
                temp = 0;
            }
        }
        if(temp > Max)
            Max = temp;
        return Max;
    }
    //˼·2(��ȷ���)
    int findLUSlength1(string a, string b) {
        int a_length = a.length();
        int b_length = b.length();
        if(a == b)
            return -1;
        else
            return a_length>b_length ? a_length : b_length;
    }
};
int main()
{
    Solution A;
    string a, b;
    cin >> a >> b;
    cout << A.findLUSlength1(a, b) << endl;
    return 0;
}
