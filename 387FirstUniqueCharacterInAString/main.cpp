#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        //A~Z 65~90  a~z 97~122
        vector<int> res(26, 0);//��res�洢�����ַ���������Ĭ��Ϊ0
        for(int i=0; i<s.length(); i++)
            res[s[i]-97]++;//�������ַ�������+1
        for(int i=0; i<s.length(); i++)
            if(res[s[i]-97] == 1)//���ַ�ֻ��һ�������ظ������ظ��ַ�λ��
                return i;
        return -1;
    }
};
int main()
{
    Solution a;
    cout << "������һ��ֻ��Сд��ĸ���ַ���: ";
    string s;
    cin >> s;
    cout << "��һ�����ظ��ַ���������: " << a.firstUniqChar(s)<< endl;
    return 0;
}
