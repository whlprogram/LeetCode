/*
简单动态规划
原题链接 https://leetcode.com/problems/jump-game/description/
参考链接 https://www.cnblogs.com/fengziwei/p/7612879.html
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size()-1 && reach >= i; i++) {
              reach = nums[i]+i > reach ? nums[i]+i : reach;
         }
         return reach >= nums.size() - 1;
    }
};
int main()
{
    Solution a;
    vector<int> ver0= {2,3,1,1,4};
    cout << a.canJump(ver0) << endl;//true
    vector<int> ver1= {3,2,1,0,4};
    cout << a.canJump(ver1) << endl;//false
    return 0;
}
