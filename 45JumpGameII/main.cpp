/*
简单动态规划
原题链接 https://leetcode.com/problems/jump-game-ii/description/
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;

		int count = 1;
		int MAX = nums[0];
		int last = 0;
		while (1) {
			if (MAX >= nums.size()-1)
				return count;
			int tmp = MAX;
			MAX = 0;
			for (int i = last; i <= tmp; i++) {
				if (nums[i]+i > MAX)
					MAX = nums[i]+i;
			}
			last = tmp+1;
			count++;
		}
	}
	int jump1(vector<int>& nums) {
        int sc = 0;
        int e = 0;
        int max = 0;
        for(int i=0; i<nums.size()-1; i++) {
            max = max>i+nums[i] ? max : i+nums[i];
            if( i == e ) {
                sc++;
                e = max;
            }
        }
        return sc;
    }
};
int main()
{
    Solution a;
    vector<int> ver0= {2,3,1,1,4};
    cout << a.jump(ver0) << endl;//2
    vector<int> ver1= {2,3,1,1,4};
    cout << a.jump1(ver1) << endl;//2
    return 0;
}
