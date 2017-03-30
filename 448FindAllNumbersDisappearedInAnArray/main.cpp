#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //以数组下标作为索引标记哪些数字出现过，标记方法为将出现数字对应下标的数字标为负数
        int length = nums.size();
        vector<int> res;
        for(int i=0;i<length;i++){
            //计算出数组中出现的数字x的下标形式，则下标为index = |x| - 1，
            //可将数组a中得a[index]标为负数来标记数字x出现在数组中
            int a = abs(nums[i]) - 1;//abs()返回绝对值
            if(nums[a]>0)
                nums[a] *= -1;
        }
        //若数组中某数字已为负数，说明该数字在数组中出现过
        //最终遍历数组，若a[i]为正数，表明数字 i + 1在数组中没有出现过
        for(int i=0;i<length;i++){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
