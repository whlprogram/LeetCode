#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> A;
        for(int findNum : findNums)
        {
            bool B = false;
            for(int i=0;i<nums.size();i++)
            {
                if(findNum == nums[i])
                    B=true;
                if(b && findNum < nums[i])
                {
                    A.push_back(nums[i]);
                    B=false;
                    break;
                }
            }
            if(B)
                A.push_back(-1);
        }
        return A;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
