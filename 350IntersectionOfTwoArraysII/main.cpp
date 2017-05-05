#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {//ԭ��https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty() || nums2.empty())
            return res;
        vector<int>& NUMS1 = nums1;
        vector<int>& NUMS2 = nums2;
        sort(NUMS1.begin(), NUMS1.end());
        sort(NUMS2.begin(), NUMS2.end());

        for(int i=0,j=0; i<NUMS1.size()&&j<NUMS2.size();){
            if(NUMS1[i] == NUMS2[j]){
                res.push_back(NUMS1[i]);
                i++;j++;
                continue;
            }
            else if(NUMS1[i] > NUMS2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return res;
    }
    //��hash��, �򵥴ֱ�
    //���������Ŀ��Բ���hash��, ͬʱɨ����������, ����ͬ��.
    //���nums2�ڴ�����, ��hash����Ӱ��
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 || nums2.size()==0)
                return vector<int>();
        vector<int> res;
        unordered_map<int, int> HASH;
        for(auto val1: nums1)
            HASH[val1]++;
        for(auto val2: nums2){
            if(HASH.count(val2) && HASH[val2]>0)
                res.push_back(val2);
            HASH[val2]--;
        }
         return res;
     }
};
int main()
{
    Solution a;
    int num1[] = {1, 2, 2, 1};
    int num2[] = {2, 2};
    vector<int> nums1(num1, num1 + sizeof(num1)/sizeof(num1[0]));
    vector<int> nums2(num2, num2 + sizeof(num2)/sizeof(num2[0]));
    vector<int> res = a.intersect1(nums1, nums2);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
