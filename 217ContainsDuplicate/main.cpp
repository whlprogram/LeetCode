//https://leetcode.com/problems/contains-duplicate/#/description‘≠Ã‚
#include <iostream>
#include <vector>
#include <algorithm>//≈≈–Ú
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)
            return false;
        vector<int> num = nums;
        sort(num.begin(), num.end());
        for(int i=1; i<num.size(); i++){
            if(num[i] == num[i-1])
                return true;
        }
        return false;
    }
    //≤Œøº https://discuss.leetcode.com/topic/14944/single-line-c-solution-60ms
    bool containsDuplicate1(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
int main()
{
    Solution a;
    int A[] = {1, 3, 6, 9, 8, 4, 2};
    int ALength = sizeof(A)/sizeof(A[0]);
    vector<int> nums(A, A+ALength);
    cout << a.containsDuplicate1(nums) << endl;
    return 0;
}
