#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> Array(2);
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left]+numbers[right] == target){
                Array[0] = left+1;
                Array[1] = right+1;
                return Array;
            }
            else if(numbers[left]+numbers[right] > target)
                right--;
            else
                left++;
        }
        return Array;
    }
};
int main()
{
    Solution a;
    int A[4] = {2, 7, 11, 15};
    vector<int> numbers1(A, A+4);
    vector<int> Array = a.twoSum(numbers1, 9);
    cout << Array[0] << ", " << Array[1] << endl;

    int B[2] = {5, 5};
    vector<int> numbers2(B, B+2);
    Array = a.twoSum(numbers2, 10);
    cout << Array[0] << ", " << Array[1] << endl;

    int C[3] = {1,5,9};
    vector<int> numbers3(C, C+3);
    Array = a.twoSum(numbers3, 14);
    cout << Array[0] << ", " << Array[1] << endl;
    cout << "Hello world!" << endl;
    return 0;
}
