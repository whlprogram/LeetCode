#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //错误
    int longestPalindrome(string s) {//求字符串能组成的最大回文串长度 所有偶数加上一个最大的奇数
        int tmp[123] = {0};//a~z 65-9 A~Z 97-122
        int res=0;
        for(int i=0; i<s.size(); i++){
            tmp[s[i]] += 1;
        }
        for(int m=0; m<123; m++)//将所有数量为偶数的字母数量加起来
            if(tmp[m]>0 && tmp[m]%2==0)
                res += tmp[m];
        int maxOddNumber = 0;//最大的 数量为奇数的字母 的数量
        for(int n=0; n<123; n++)//将所有数量为奇数的字母数量加起来
            if(tmp[n]>0 && tmp[n]%2==1)
                if(tmp[n]>maxOddNumber)
                    maxOddNumber = tmp[n];
        cout <<  "maxOddNumber=" << maxOddNumber << endl;
        return res+maxOddNumber;
    }
    //正确
    int longestPalindrome1(string s) {//所有偶数+所有(大于1的奇数-1变成偶数)+1(有奇数+1 ，没奇数不加)
        int tmp[123] = {0};//a~z 65-9 A~Z 97-122
        int res=0;
        for(int i=0; i<s.size(); i++){
            tmp[s[i]] += 1;
        }
        bool a = false;//判断是否有奇数
        for(int m=0; m<123; m++){//将所有数量为偶数的字母数量加起来
            if(tmp[m]>0 && tmp[m]%2==0)
                res += tmp[m];
            if(tmp[m]>0 && tmp[m]%2==1){//所有的奇数-1变成偶数
                a = true;
                res = res + (tmp[m]-1);
            }
        }
        return a ? res+1 : res;//有奇数+1 ，没奇数不加
    }
};
int main()
{
    Solution a;
    string s;
    //cin >> s;
    s="civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << a.longestPalindrome1(s) << endl;//应该是983
    return 0;
}
