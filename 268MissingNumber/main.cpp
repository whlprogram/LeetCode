#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//原题链接 https://leetcode.com/problems/missing-number/#/description
public:
    //33ms
    //给数组排序，不缺少元素情况下数组中元素应该与其下标的值相等
    //遍历数组，找出与其下标不相等的元素，即缺少的元素
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != res)
                return res;
            res++;
        }
        return res;
    }
    //26ms
    //n = nums.size()
    //求出不缺少元素情况下数组中所有元素的和,即0~n
    //0+1+2+3+...+n => (n+0)*((n+1)/2) => n*(n+1)/2
    //依次减去数组中的元素，最后剩下的就是缺少的那个数
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        long sum = n*(n+1)/2;//不缺少元素情况下数组中所有元素的和
        for(auto i: nums){
            sum -= i;
        }
        return sum;

    }
    //22ms
    //a^a=0   a^b^a=b  a^b^c^a^c=b
    //nums[] = {0, 2, 1, 3, 5}
    //     i = 0, 1, 2, 3, 4
    //     x = 5 (若数组nums不缺少元素,最大数应该是nums.size()=5)
    //程序结束后x值就是缺少的元素
    int missingNumber2(vector<int>& nums) {
        int x = nums.size();
        for(int i = 0;i<nums.size();i++){
            x = x ^ nums[i] ^ i;
        }
        return x;
    }
};
int main()
{
    Solution a;
    int A[] = {0, 1, 2, 3, 5, 4, 7};
    int Alength = sizeof(A)/sizeof(A[0]);
    vector<int> nums(A, A+Alength);
    cout << a.missingNumber1(nums) << endl;
    return 0;
}
