#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int length = word.length();
        if (length == 1)
            return true;
        if (word[0]> 'Z')//首字母小写 后面有大写就不符合规则
        {
            for (int i=1;i<length;i++)//遍历除首字母外剩下字母
            {
              if (word[i]<='Z')//遇到大写就返回false
              {
                return false;
              }
            }
        }
        else
        {
            if(word[1]<='Z')//首字母大写 第二个字母也大写
            {
                for (int i=2;i<length;i++)//从第三个字母遍历
                {
                  if (word[i]>'Z')//遇到小写就返回false
                  {
                    return false;
                  }
                }
            }
            else //首字母大写 第二个字母小写
            {
                for (int i=2;i<length;i++)//从第三个字母遍历
                {
                  if (word[i]<='Z')//遇到大写就返回false
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
