#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        //A~Z 65~90  a~z 97~122
        vector<int> res(26, 0);//用res存储各个字符的数量，默认为0
        for(int i=0; i<s.length(); i++)
            res[s[i]-97]++;//将各个字符的数量+1
        for(int i=0; i<s.length(); i++)
            if(res[s[i]-97] == 1)//若字符只有一个，不重复，返回该字符位置
                return i;
        return -1;
    }
};
int main()
{
    Solution a;
    cout << "请输入一个只含小写字母的字符串: ";
    string s;
    cin >> s;
    cout << "第一个不重复字符的索引是: " << a.firstUniqChar(s)<< endl;
    return 0;
}
