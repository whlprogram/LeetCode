#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int length = word.length();
        if (length == 1)
            return true;
        if (word[0]> 'Z')//����ĸСд �����д�д�Ͳ����Ϲ���
        {
            for (int i=1;i<length;i++)//����������ĸ��ʣ����ĸ
            {
              if (word[i]<='Z')//������д�ͷ���false
              {
                return false;
              }
            }
        }
        else
        {
            if(word[1]<='Z')//����ĸ��д �ڶ�����ĸҲ��д
            {
                for (int i=2;i<length;i++)//�ӵ�������ĸ����
                {
                  if (word[i]>'Z')//����Сд�ͷ���false
                  {
                    return false;
                  }
                }
            }
            else //����ĸ��д �ڶ�����ĸСд
            {
                for (int i=2;i<length;i++)//�ӵ�������ĸ����
                {
                  if (word[i]<='Z')//������д�ͷ���false
                  {
                    return false;
                  }
                }
            }
        }
        return true;
    }
    bool detectCapitalUse1(string word) {
        if (word.length() <= 1) return true;
        if (islower(word[0]) || (isupper(word[0]) && islower(word[1]))) {
            for (int i = 1; i < word.length(); i++){
                    if (isupper(word[i]))
                        return false;
                }
        } else {
            for (int i = 1; i < word.length(); i++){
                if (islower(word[i]))
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution a;
    cout << a.detectCapitalUse("A") << endl;
    return 0;
}
