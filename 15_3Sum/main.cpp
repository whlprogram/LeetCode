/*
�������������һ�����飬�ҳ��������в�ͬ�������͵���0����ϡ�

���������
���ȣ��������������������ȶ������е���������������������ָ�룬һ��ָ��ͷ��һ��ָ��β��
�ж��������Ƿ������Ҫ��������������ڽ�������������飻
���С��˵�����ָ��ָ�����С�ˣ������ָ�����ƣ���֮�����������ָ�����ơ�

���԰�����������ת��Ϊ���������⣺ͬ���ȶ���������
��������ָ��p,q,r��pָ��ָ���һ����x����q,rҪָ��������ʣ�����е�����������ָ���������Ϊ-x���Ӷ�ת��Ϊ���������⡣
��pָ���һ���������������Ϻ󣬲������������������Ұ���x�����������p���ơ�
����һֱ������pָ�������е������������������
ע�����������ظ��������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        vector<int> numSet(3);
        vector< vector<int> > r;
        // 1.����
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.�ó���һ������ת��Ϊ���������⡣ע�����ѭ��������������������
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            numSet[0] = num[i];
            // 3.����������
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    numSet[1] = num[j++];
                    numSet[2] = num[k--];
                    r.push_back(numSet);
                    // ������ĿҪ�������ظ�Ԫ��
                    while(j < k && num[j] == num[j-1])
                        j++;
                    while(j < k && num[k] == num[k+1])
                        k--;
                }
                else if(num[j] + num[k] < sum)
                    j++;
                else
                    k--;
            }
            while(i < len-2 && num[i+1] == num[i])
                i++;
        }
        return r;
    }
    //const int* input, int size
    int three_sum(const int* input, int size)
    {
        vector<int> num(input, input+size);
        vector<int> numSet(3);
        vector< vector<int> > r;
        // 1.����
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.�ó���һ������ת��Ϊ���������⡣ע�����ѭ��������������������
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            numSet[0] = num[i];
            // 3.����������
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    numSet[1] = num[j++];
                    numSet[2] = num[k--];
                    r.push_back(numSet);
                    // ������ĿҪ�������ظ�Ԫ��
                    while(j < k && num[j] == num[j-1])
                        j++;
                    while(j < k && num[k] == num[k+1])
                        k--;
                }
                else if(num[j] + num[k] < sum)
                    j++;
                else
                    k--;
            }
            while(i < len-2 && num[i+1] == num[i])
                i++;
        }
        return r.size();
    }
};

int main() {
    int a[] = {-2, 13, -5, -4, -7, 8, 0, -9, 6, 7, 0, -4, 2, 1, -2, 4};
    int len = sizeof(a) / sizeof(a[0]);
    vector<int> num(a, a+len);
    Solution s;
    vector< vector<int> > result;
    result = s.threeSum(num);
    int res = s.three_sum(a, len);
    cout << res << endl;
    // ������
    for(int q = 0; q < result.size(); q++) {
        vector<int> x = result[q];
        cout << "(";
        int t;
        for(t = 0; t < x.size()-1; t++) {
            cout << x[t] << " ";
        }
        cout << x[t];
        cout << ")" << endl;
    }

    return 0;
}
