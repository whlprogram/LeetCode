#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)//length==1 ֻ��һ��Ԫ��
            return nums[0];
        vector<int> tem(length, 1);//����һ����ͬ���ȵ����飬Ĭ��ֵΪ1������ÿ����������
        sort(nums.begin(), nums.end());//��nums����
        /*for(int m=0; m<length; m++){
            cout << nums[m];
        }*/
        for(int i=1; i<length; i++){
            if(nums[i] == nums[i-1]){//ǰ��Ԫ����ͬ
                tem[i] = tem[i-1] + 1;//����Ԫ�ش����������1(��������)
                tem[i-1] = 0;//֮ǰ�������������
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
