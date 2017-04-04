#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //g[] children    s[] cookies
    //���ȶ����������������,Ȼ������������̰���Ƚϵͺ��ӵ�ԭ��,
    //�����ɴ�С������,����������ú���,
    //������,�򿴱�����һ��ı����ܲ�������,��֮ǰ�ı��ɱ�Ȼ���㲻�����������˵�����.
    int findContentChildren(vector<int>& g, vector<int>& s) {//ѭ����ѭ�� ����Ч�ʵ�
        int maxNum=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j=0;
        for (int i=0; i<g.size(); i++){
            while(j < s.size()){
                if(g[i]<=s[j]){
                    j++;
                    maxNum++;
                    break;
                }
                j++;
            }
        }
        return maxNum;
    }
    int findContentChildren1(vector<int>& g, vector<int>& s) {//��ѭ�� Ч���������
        int maxNum = 0;
        sort(g.begin(), g.end());//��������������
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i<g.size() && j<s.size()){
            if(g[i] <= s[j]){//���������� maxNum+1 ���������±�+1
                maxNum++;
                i++;
                j++;
            }
            else{
                j++;//���������� s�±�+1 ������ԭg[i]�Ƚ�
            }
        }
        return maxNum;
    }
    //����д��������maxNum��ȫ������i��ȡ��
    int findContentChildren2(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i<g.size() && j<s.size()){
            if(g[i] <= s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
    /*int findContentChildren3(vector<int>& g, vector<int>& s) {//�����淽�����
        int maxNum = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int Size:s) {
            if(Size >= g[maxNum]) {
                ++maxNum;
                if(maxNum == g.size())
                    break;
            }
        }
        return maxNum;
    }*/
    int findContentChildren4(vector<int>& g, vector<int>& s) {//������������
        int maxNum = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = g.size()-1;
        int j = s.size()-1;
        while(j >= 0){
            while(i >= 0 && g[i]> s[j]) //�ҵ����������ĺ����±�
                i--;
            if(i >= 0) //�����������ĺ����±��������� maxNum+1
                maxNum++;
            j--;
            i--;
        }
        return maxNum;
    }


};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
