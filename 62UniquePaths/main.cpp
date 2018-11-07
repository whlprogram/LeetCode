/*
原题链接 https://leetcode.com/problems/unique-paths/description/
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>100 || n>100 || m<=0 || n<=0)
            return 0;
        if(m==1 || n==1)
            return 1;
        vector<vector<int>> arr(n, vector<int>(m, 1));//n行m列
        /*
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        */
        for(int i=1; i<n; i++){
            for(int j=1;j<m; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        */
        return arr[n-1][m-1];
    }
};
int main()
{
    Solution a;
    cout << a.uniquePaths(7,3) << endl;
    return 0;
}
