#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //思路：
    //1.英文句子分割成一个个单词
    //2.将每个单词反转 (以单词中间字母为中心，前后对称位置的字母交换位置)
    string reverseWords(string s) {
        string res = s;//复制英文句子
        int left = 0;//记录单词位置的左下标
        int right = 0;//记录单词位置的右下标
        for(int i=0; i<res.length()+1; i++){//s.length()+1 是为了遍历字符串最后的结束符'\0'
            if(res[i]==' ' || res[i]=='\0'){//若s="asd dfg" 则s[3]=' ',s[7]='\0'
                left = right;
                right = i-1;//空格或结束符的左邻字符下标 即为 目前单词位置的右下标
                int L = left;
                int R = right;
                for(; L<R; ++L,--R){//反转单词
                    char temp = res[L];
                    res[L] = s[R];
                    res[R] = temp;
                }
                right = i+1;//空格或结束符的右邻字符下标 即为 下个单词位置的左下标
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
    //cin >> a;//只能输入没有空格的字符串，当输入中含有空格，则只能输出空格之前的字符
    cout << A.reverseWords(a) << endl;
    return 0;
}
