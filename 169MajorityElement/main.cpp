#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)//length==1 只有一个元素
            return nums[0];
        vector<int> tem(length, 1);//定义一个相同长度的数组，默认值为1，代表每个数的数量
        sort(nums.begin(), nums.end());//将nums排序
        /*for(int m=0; m<length; m++){
            cout << nums[m];
        }*/
        for(int i=1; i<length; i++){
            if(nums[i] == nums[i-1]){//前后元素相同
                tem[i] = tem[i-1] + 1;//将该元素代表的数量加1(更新数量)
                tem[i-1] = 0;//之前代表的数量清零
                if(tem[i] > length/2)
                    return nums[i];
            }
        }
    }
};
int main()
{
    if(1)
       cout << "123" << endl;
    Solution a;
    int A[4] = {2, 7, 7, 7};
    vector<int> numbers1(A, A+4);
    cout << a.majorityElement(numbers1) << endl;
    return 0;
}
