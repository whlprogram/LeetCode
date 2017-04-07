#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res(1000, 0);//�����˴������ݣ�����������
        vector <int> intersectionArray;//��������
        for(char m : nums1)
            res[m]++;
        for(char n : nums2){
            if(res[n] != 0){
                 intersectionArray.push_back(n);//������������ͬ������������intersectionArray��
                 res[n] = 0;//��ֵΪ0��Ϊ�˲�������ͬԪ��
                 //���磺 nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. �ڶ���2������
            }
        }
        return intersectionArray;
    }
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector <int> intersectionArray;//��������
        if(nums1.empty() || nums2.empty())//�ж������Ƿ�Ϊ��
            return intersectionArray;
        sort(nums1.begin(), nums1.end());//�ײ�ʹ���˿�������O(nlogn)
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();

        for(int i=0,j=0; i<m||j<n; ){//�κ�һ�����������ͽ���ѭ��
            if(nums1[i] == nums2[j]){
                if(i==0 || j==0){//����������Ԫ��ֱ�Ӽ��뽻������
                    intersectionArray.push_back(nums1[i]);
                    i++; j++;
                    continue;
                }
                //�ų����������ھ�������������������ͬԪ�ص����������nums1=[1, 2, 2, 1],nums2=[2, 2]
                else if(nums1[i]!=nums1[i-1]){
                    intersectionArray.push_back(nums1[i]);
                    i++; j++;
                    continue;
                }
                //���������ھ�������������������ͬԪ�أ�i++ j++ ֱ�ӿ�ʼ��һ��ѭ��
                else{
                    i++; j++;
                    continue;
                }

            }
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return intersectionArray;
    }
};

int main()
{
    Solution a;
    int A[4] = {2, 8, 11, 15};
    int B[4] = {2, 7, 21, 15};
    vector<int> nums1(A, A+4);
    vector<int> nums2(B, B+4);
    vector<int> intersectionArray = a.intersection1(nums1, nums2);
    for(int i=0; i<intersectionArray.size(); i++)
        cout << intersectionArray[i] << " ";
    return 0;
}
