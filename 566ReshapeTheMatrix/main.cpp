#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums[0].size()*nums.size() != r*c)
            return nums;
        vector<int> num;
        for(int i=0; i<nums.size(); i++)
            for(int j=0; j<nums[0].size(); j++)
                num.push_back(nums[i][j]);
        vector<vector<int>> NUMS(r);
        for (int i = 0; i < NUMS.size(); i++)
            NUMS[i].resize(c);
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                NUMS[i][j] = num[i*c+j];
        return NUMS;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
