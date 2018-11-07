/*
问题简述：给定一个数组，找出其中所有不同的三数和等于0的组合。

问题分析：
首先，两数和问题这样做。先对数组中的数进行排序，再设置两个指针，一个指向头，一个指向尾。
判断两数和是否等于想要的数，如果是则在结果集添加这个数组；
如果小了说明左边指针指向的数小了，因此左指针右移；反之如果大了则右指针左移。

尝试把三数和问题转化为两数和问题：同样先对数组排序，
设置三个指针p,q,r，p指针指向第一个数x，则q,r要指向数组中剩余数中的两个，并且指向的两数和为-x，从而转化为两数和问题。
对p指向第一个数的情况分析完毕后，不可能再有满足题意且包含x的情况，于是p右移。
这样一直分析到p指向数组中倒数第三个数的情况。
注意跳过所有重复的情况。
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
        // 1.排序
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            numSet[0] = num[i];
            // 3.两数和问题
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    numSet[1] = num[j++];
                    numSet[2] = num[k--];
                    r.push_back(numSet);
                    // 根据题目要求，跳过重复元素
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
        // 1.排序
        sort(num.begin(), num.end());
        int sum;
        int len = num.size();
        // 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
        for(int i = 0; i < len-2; i++) {
            sum = 0 - num[i];
            numSet[0] = num[i];
            // 3.两数和问题
            for(int j = i+1, k = len-1; j < k;) {
                if(num[j] + num[k] == sum) {
                    numSet[1] = num[j++];
                    numSet[2] = num[k--];
                    r.push_back(numSet);
                    // 根据题目要求，跳过重复元素
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
    // 输出结果
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
