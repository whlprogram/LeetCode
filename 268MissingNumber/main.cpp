#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//ԭ������ https://leetcode.com/problems/missing-number/#/description
public:
    //33ms
    //���������򣬲�ȱ��Ԫ�������������Ԫ��Ӧ�������±��ֵ���
    //�������飬�ҳ������±겻��ȵ�Ԫ�أ���ȱ�ٵ�Ԫ��
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
    //�����ȱ��Ԫ�����������������Ԫ�صĺ�,��0~n
    //0+1+2+3+...+n => (n+0)*((n+1)/2) => n*(n+1)/2
    //���μ�ȥ�����е�Ԫ�أ����ʣ�µľ���ȱ�ٵ��Ǹ���
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        long sum = n*(n+1)/2;//��ȱ��Ԫ�����������������Ԫ�صĺ�
        for(auto i: nums){
            sum -= i;
        }
        return sum;

    }
    //22ms
    //a^a=0   a^b^a=b  a^b^c^a^c=b
    //nums[] = {0, 2, 1, 3, 5}
    //     i = 0, 1, 2, 3, 4
    //     x = 5 (������nums��ȱ��Ԫ��,�����Ӧ����nums.size()=5)
    //���������xֵ����ȱ�ٵ�Ԫ��
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
