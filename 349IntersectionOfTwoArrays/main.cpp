#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res(1000, 0);//处理不了大量数据，不符合题意
        vector <int> intersectionArray;//交集数组
        for(char m : nums1)
            res[m]++;
        for(char n : nums2){
            if(res[n] != 0){
                 intersectionArray.push_back(n);//将两数组内相同的数存入数组intersectionArray中
                 res[n] = 0;//赋值为0是为了不存入相同元素
                 //例如： nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. 第二个2不存入
            }
        }
        return intersectionArray;
    }
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector <int> intersectionArray;//交集数组
        if(nums1.empty() || nums2.empty())//判断数组是否为空
            return intersectionArray;
        sort(nums1.begin(), nums1.end());//底层使用了快速排序，O(nlogn)
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();

        for(int i=0,j=0; i<m||j<n; ){//任何一个数组遍历完就结束循环
            if(nums1[i] == nums2[j]){
                if(i==0 || j==0){//若是数组首元素直接加入交集数组
                    intersectionArray.push_back(nums1[i]);
                    i++; j++;
                    continue;
                }
                //排除两个数组内均有两个或两个以上相同元素的情况。例如nums1=[1, 2, 2, 1],nums2=[2, 2]
                else if(nums1[i]!=nums1[i-1]){
                    intersectionArray.push_back(nums1[i]);
                    i++; j++;
                    continue;
                }
                //两个数组内均有两个或两个以上相同元素，i++ j++ 直接开始下一个循环
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
