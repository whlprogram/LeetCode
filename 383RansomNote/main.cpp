#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        //�����˴�Сд��ĸ�����ֻ����Сд��ĸ��128�ĳ�26 ������֤��ÿ���ַ�-97�ͺ�
        vector <int> res(128, 0);//A-Z 65-90 a-z 97-122
        for(char m : magazine)
            res[m]++;
        for(char r : ransomNote){
            if(res[r] == 0)
                return false;
            res[r]--;
        }
        return true;
    }
};
int main()
{
    Solution a;
    string ransomNote,magazine;
    cin >> ransomNote >> magazine;
    cout << a.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
