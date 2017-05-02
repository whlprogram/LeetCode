#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //思路：
    //设置一个不定长一维数组num存放原矩阵的所有数据，按要求设置新矩阵NUMS并依次赋值(对应num中相应位置)
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums[0].size()*nums.size() != r*c)
            return nums;
        vector<int> num;//顺序放置原矩阵的元素
        for(int i=0; i<nums.size(); i++)
            for(int j=0; j<nums[0].size(); j++)
                num.push_back(nums[i][j]);
        vector<vector<int>> NUMS(r, vector<int>(c, 0));
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                NUMS[i][j] = num[i*c+j];
        return NUMS;
    }
    vector<vector<int>> matrixReshape1(vector<vector<int>>& nums, int r, int c) {
        int R = nums.size();//原矩阵行
        int C = nums[0].size();//原矩阵列
        if(R*C != r*c)
            return nums;
        vector<vector<int>> NUMS(r);//构造新矩阵 设置行为r
        for (int i = 0; i < NUMS.size(); i++)//设置新矩阵每行的列数为c
            NUMS[i].resize(c);
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                int a = (i*c+j)/C;//对应原矩阵的行
                int b = (i*c+j)%C;//对应原矩阵的列
                NUMS[i][j] = nums[a][b];
            }
        return NUMS;
    }
};
int main()
{
    Solution a;
    int R,C,r,c;//原矩阵行和列
    cout <<"输入矩阵的行: ";
    cin >> R;
    cout <<"输入矩阵的列: ";
    cin >> C;
    cout << "依次输入矩阵元素: " << endl;
    vector<vector<int>> nums(R, vector<int>(C, 0));//矩阵默认值为0
    for (int i = 0; i <R; i++){
        for (int j = 0; j <C; j++)
            cin >> nums[i][j];
        cout << endl;
    }
    cout << "输出矩阵: " << endl;
    for (int i = 0; i <R; i++){
        for (int j = 0; j <C; j++)
            cout << nums[i][j];
        cout << endl;
    }
    cout <<"输入新矩阵的行: ";
    cin >> r;
    cout <<"输入新矩阵的列: ";
    cin >> c;
    cout << "输出新矩阵: " << endl;
    vector <vector<int>>  NUMS = a.matrixReshape1(nums,r,c);
    for (int i = 0; i <r; i++){
        for (int j = 0; j <c; j++)
            cout << NUMS[i][j];
        cout << endl;
    }
    return 0;
}
