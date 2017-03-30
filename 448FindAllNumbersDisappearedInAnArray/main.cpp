#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //�������±���Ϊ���������Щ���ֳ��ֹ�����Ƿ���Ϊ���������ֶ�Ӧ�±�����ֱ�Ϊ����
        int length = nums.size();
        vector<int> res;
        for(int i=0;i<length;i++){
            //����������г��ֵ�����x���±���ʽ�����±�Ϊindex = |x| - 1��
            //�ɽ�����a�е�a[index]��Ϊ�������������x������������
            int a = abs(nums[i]) - 1;//abs()���ؾ���ֵ
            if(nums[a]>0)
                nums[a] *= -1;
        }
        //��������ĳ������Ϊ������˵���������������г��ֹ�
        //���ձ������飬��a[i]Ϊ�������������� i + 1��������û�г��ֹ�
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
