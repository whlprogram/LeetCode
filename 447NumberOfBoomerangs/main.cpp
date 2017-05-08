#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
class Solution { //ԭ������: https://leetcode.com/problems/number-of-boomerangs/#/description
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(pair<int, int> p1 : points){
            unordered_map <double, int> Hash;
            for(pair<int, int> p2 : points){
                //hypot(a, b) ��ֱ��������б�߳�����(a, bΪֱ�������ε�ֱ�Ǳ�) #include <math.h>
                Hash[hypot(p1.first-p2.first, p1.second-p2.second)]++;
            }
            for(auto val : Hash){
                if(val.second > 1)
                    //����������㵽�����������, ��ô��2����,
                    //�����5���㵽�����������, ��ô������5�����������ȡ2��������, Ҳ����һ��������ϵļ�����.
                    //5��   (4+3+2+1)*2 -> (4+1) * [(5-1)/2] * 2 -> 5*(5-1)
                    res += val.second*(val.second-1);
            }
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
