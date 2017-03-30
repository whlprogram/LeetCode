#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        for(int i=0;i<s_length;i++)//�����ַ���s
        {
            for(int j=0;j<t_length;j++)//�����ַ���t
            {
                if(s[i] == t[j])//�����ַ���t�� �ҵ��� �ַ���s��Ԫ�� ��ͬ���ַ�
                {
                    t[j] = '0';//��t�и�Ԫ�ظ�ֵ'0'
                    break;//�����������ַ���t
                }
            }

        }
        for(int m=0;m<t_length;m++)//�����ַ���t
        {
            if(t[m] != '0')//�ҵ�û�б���ֵΪ'0'��Ԫ�� ���ظ�ֵ
                return t[m];
        }
        return t[s_length];
    }
    //����Hash��
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
    //�������
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
