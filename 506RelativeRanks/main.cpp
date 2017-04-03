#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> arr = nums;//����һ����ͬ������
        auto cmp = [](int a, int b) {return a > b;};
        sort(arr.begin(), arr.end(), cmp);//��arr����
        vector<string> result(nums.size());
        //��nums��Ѱ����arr[j]��ͬԪ��,��result�ж�Ӧλ�ø�ֵΪj+1, j=0,1,2ʱ���⴦��
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == arr[j]) {
                    switch(j) {
                        case 0:
                            result[i] = "Gold Medal";
                            break;
                        case 1:
                            result[i] = "Silver Medal";
                            break;
                        case 2:
                            result[i] = "Bronze Medal";
                            break;
                        default:
                            result[i] = to_string(j + 1);
                            break;
                    }
                    break;
                }
            }
        }
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
