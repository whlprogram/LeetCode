#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //����
    int longestPalindrome(string s) {//���ַ�������ɵ������Ĵ����� ����ż������һ����������
        int tmp[123] = {0};//a~z 65-9 A~Z 97-122
        int res=0;
        for(int i=0; i<s.size(); i++){
            tmp[s[i]] += 1;
        }
        for(int m=0; m<123; m++)//����������Ϊż������ĸ����������
            if(tmp[m]>0 && tmp[m]%2==0)
                res += tmp[m];
        int maxOddNumber = 0;//���� ����Ϊ��������ĸ ������
        for(int n=0; n<123; n++)//����������Ϊ��������ĸ����������
            if(tmp[n]>0 && tmp[n]%2==1)
                if(tmp[n]>maxOddNumber)
                    maxOddNumber = tmp[n];
        cout <<  "maxOddNumber=" << maxOddNumber << endl;
        return res+maxOddNumber;
    }
    //��ȷ
    int longestPalindrome1(string s) {//����ż��+����(����1������-1���ż��)+1(������+1 ��û��������)
        int tmp[123] = {0};//a~z 65-9 A~Z 97-122
        int res=0;
        for(int i=0; i<s.size(); i++){
            tmp[s[i]] += 1;
        }
        bool a = false;//�ж��Ƿ�������
        for(int m=0; m<123; m++){//����������Ϊż������ĸ����������
            if(tmp[m]>0 && tmp[m]%2==0)
                res += tmp[m];
            if(tmp[m]>0 && tmp[m]%2==1){//���е�����-1���ż��
                a = true;
                res = res + (tmp[m]-1);
            }
        }
        return a ? res+1 : res;//������+1 ��û��������
    }
};
int main()
{
    Solution a;
    string s;
    //cin >> s;
    s="civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << a.longestPalindrome1(s) << endl;//Ӧ����983
    return 0;
}
