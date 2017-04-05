#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
    //思路1:
    //复制一个相同数组 排序
    //定下数组最大值 其余元素均+1 最终得到相等数组
    //暴力解法  效率低下
    int minMoves(vector<int>& nums) {
        vector<int> num = nums;
        sort(num.begin(), num.end());
        bool a = false;//判断数组是否符合条件
        int m = 0;//初始步骤
        while(!a){
            a = isEqualArray(a, num);//验证是否数组元素相等，相等则返回true,否则返回false
            if(a)//验证数组符合条件，结束循环
                break;
            m++;//步骤+1
            incrementBy1(num);//将数组中除最大数外所有元素+1
        }
        return m;
    }
    bool isEqualArray(bool a, vector<int>& num){
        for(int i=1; i<num.size(); i++){
            if(num[i] != num[0]){
                return false;
            }
        }
        return true;
    }
    void incrementBy1(vector<int> &num){
        int maxNum = 0;
        for(int i=1; i<num.size(); i++){
            if(num[i] > num[maxNum]){
                num[maxNum]++;
                maxNum = i;
            }
            else
                num[i]++;
        }
    }
    //思路2 ：数学问题！！！考虑清楚后简单
    //首先将sum定义为初始数组中所有数字的总和; minNum作为列表中的最小数字; n是列表的长度;
    //之后，移动m次，我们得到所有的数字为x，我们将得到以下等式
    // sum + m *（n-1）= x * n
    //实际上，
    // x = minNum + m
    //最后，通过计算会得到
    //   sum - minNum * n = m
    int minMoves1(vector<int>& nums) {
        int m = 0;//初始步骤
        int sum = 0;//初始数组中所有数字的总和
        int minNum = nums[0];//列表中的最小数字,默认为第一个
        int n = nums.size();//列表长度
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(nums[i] < minNum)//找列表中的最小数字
                minNum = nums[i];
        }
        m = sum - minNum*n;
        return m;
    }
    //思路3 ：
    //将n-1个元素加1，可以换个思路相等于将最大元素减1，最终减到最小那个元素的值。
    //因为每次最大元素-1，那肯定是将除了最小数minNum之外的其他所有数一次次减，直到他们等于都最小数minNum。
    //所以m就等于 所有数与最小数的差 的和
    //先求出数组的最小值minNum，然后累加的所有数和minNum之间的差即为所求
    int minMoves2(vector<int>& nums) {
        int n = nums.size();//列表长度
        //求数组最小值
        //int minNum = *min_element(nums.begin(), nums.end());与下面效果相同
        int minNum = nums[0];//列表中的最小数字,默认为第一个
        for(int i=0; i<n; i++){
            if(nums[i] < minNum)//找列表中的最小数字
                minNum = nums[i];
        }
        //累加的所有数和minNum之间的差
        int m = 0;//初始步骤
        for(int i=0; i<n; i++){
            m += nums[i] - minNum;
        }
        return m;
    }
};
int main()
{
    Solution a;
    int A[3] = {1, 2, 3};
    vector<int> nums(A, A+3);
    int minNum =  a.minMoves2(nums);
    cout << minNum << endl;

    int B[4] = {1, 2, 3, 5};
    vector<int> nums1(B, B+4);
    int minNum1 =  a.minMoves2(nums1);
    cout << minNum1 << endl;

    int C[5] = {1, 2, 3, 4, 5};
    vector<int> nums2(C, C+5);
    int minNum2 =  a.minMoves2(nums2);
    cout << minNum2 << endl;

    return 0;
}
