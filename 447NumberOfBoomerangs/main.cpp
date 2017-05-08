#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
class Solution { //原题链接: https://leetcode.com/problems/number-of-boomerangs/#/description
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(pair<int, int> p1 : points){
            unordered_map <double, int> Hash;
            for(pair<int, int> p2 : points){
                //hypot(a, b) 求直角三角形斜边长函数(a, b为直角三角形的直角边) #include <math.h>
                Hash[hypot(p1.first-p2.first, p1.second-p2.second)]++;
            }
            for(auto val : Hash){
                if(val.second > 1)
                    //如果有两个点到这个点距离相等, 那么有2个答案,
                    //如果有5个点到这个点距离相等, 那么会是这5个点的中有序取2个点的组合, 也就是一个排列组合的简单问题.
                    //5个   (4+3+2+1)*2 -> (4+1) * [(5-1)/2] * 2 -> 5*(5-1)
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
