#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //g[] children    s[] cookies
    //首先对两个数组进行排序,然后按照优先满足贪婪度较低孩子的原则,
    //若饼干大小能满足,则将它分配给该孩子,
    //若不能,则看比它大一点的饼干能不能满足,而之前的饼干必然满足不了其他所有人的欲望.
    int findContentChildren(vector<int>& g, vector<int>& s) {//循环套循环 明显效率低
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
    int findContentChildren1(vector<int>& g, vector<int>& s) {//单循环 效率提高明显
        int maxNum = 0;
        sort(g.begin(), g.end());//将两个数组排序
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i<g.size() && j<s.size()){
            if(g[i] <= s[j]){//不满足条件 maxNum+1 两个数组下标+1
                maxNum++;
                i++;
                j++;
            }
            else{
                j++;//不满足条件 s下标+1 继续和原g[i]比较
            }
        }
        return maxNum;
    }
    //代码写出来后发现maxNum完全可以用i来取代
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
    /*int findContentChildren3(vector<int>& g, vector<int>& s) {//和上面方法差不多
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
    int findContentChildren4(vector<int>& g, vector<int>& s) {//从数组后面遍历
        int maxNum = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = g.size()-1;
        int j = s.size()-1;
        while(j >= 0){
            while(i >= 0 && g[i]> s[j]) //找到符合条件的孩子下标
                i--;
            if(i >= 0) //若符合条件的孩子下标在数组内 maxNum+1
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
