#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //˼·��
    //1.Ӣ�ľ��ӷָ��һ��������
    //2.��ÿ�����ʷ�ת (�Ե����м���ĸΪ���ģ�ǰ��Գ�λ�õ���ĸ����λ��)
    string reverseWords(string s) {
        string res = s;//����Ӣ�ľ���
        int left = 0;//��¼����λ�õ����±�
        int right = 0;//��¼����λ�õ����±�
        for(int i=0; i<res.length()+1; i++){//s.length()+1 ��Ϊ�˱����ַ������Ľ�����'\0'
            if(res[i]==' ' || res[i]=='\0'){//��s="asd dfg" ��s[3]=' ',s[7]='\0'
                left = right;
                right = i-1;//�ո��������������ַ��±� ��Ϊ Ŀǰ����λ�õ����±�
                int L = left;
                int R = right;
                for(; L<R; ++L,--R){//��ת����
                    char temp = res[L];
                    res[L] = s[R];
                    res[R] = temp;
                }
                right = i+1;//�ո��������������ַ��±� ��Ϊ �¸�����λ�õ����±�
            }
        }
        return res;
    }
};
int main()
{
    Solution A;
    string a;
    getline(cin,a);
    //cin >> a;//ֻ������û�пո���ַ������������к��пո���ֻ������ո�֮ǰ���ַ�
    cout << A.reverseWords(a) << endl;
    return 0;
}
