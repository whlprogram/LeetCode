#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
using namespace std;
class Solution {//https://leetcode.com/problems/distribute-candies/#/description
public:
    int distributeCandies(vector<int>& candies) {
        if(candies.size()%2 != 0)
            return 0;
        unordered_map<int, int> HASH;
        int res = 0;
        for(int c: candies){
           HASH[c]++;
           if(HASH[c]==1 && res<candies.size()/2)
                res++;
        }
        return res;
    }
    int distributeCandies1(vector<int>& candies) {
        assert(candies.size()%2 == 0);//assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行
        sort(begin(candies), end(candies));//将数组排序
        int ans = 0;//记录糖果种类
        for (int i=0; i<candies.size(); ++i) {
            if(i==0 || candies[i]!=candies[i-1])
                ++ans;
        }
        //若糖果种类大于数组的一半，妹妹最多得到candies.size()/2种糖果,否则每种糖果都可以得到
        return min(ans, (int)candies.size()/2);
    }

};
int main()
{
    Solution a;
    int candies[] = {1, 1, 1, 2, 2, 2, 3, 4};
    int candiesLength = sizeof(candies)/sizeof(candies[0]);
    vector<int> Candies(candies, candies+candiesLength);
    cout << "the maximum number of kinds of candies the sister could gain is ";
    cout << a.distributeCandies1(Candies) << endl;
    return 0;
}
