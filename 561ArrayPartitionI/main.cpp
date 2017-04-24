// https://leetcode.com/problems/array-partition-i/#/description‘≠Ã‚
//https://discuss.leetcode.com/topic/87206/java-solution-sorting-and-rough-proof-of-algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i+=2){
            res += nums[i];
        }
        return res;
    }
};
int main()
{
    Solution a;
    int num[4] = {1, 4, 3, 2};
    int numLength = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+numLength);
    cout << a.arrayPairSum(nums) << endl;
    return 0;
}
