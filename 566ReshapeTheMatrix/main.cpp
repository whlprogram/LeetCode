#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //˼·��
    //����һ��������һά����num���ԭ������������ݣ���Ҫ�������¾���NUMS�����θ�ֵ(��Ӧnum����Ӧλ��)
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums[0].size()*nums.size() != r*c)
            return nums;
        vector<int> num;//˳�����ԭ�����Ԫ��
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
        int R = nums.size();//ԭ������
        int C = nums[0].size();//ԭ������
        if(R*C != r*c)
            return nums;
        vector<vector<int>> NUMS(r);//�����¾��� ������Ϊr
        for (int i = 0; i < NUMS.size(); i++)//�����¾���ÿ�е�����Ϊc
            NUMS[i].resize(c);
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                int a = (i*c+j)/C;//��Ӧԭ�������
                int b = (i*c+j)%C;//��Ӧԭ�������
                NUMS[i][j] = nums[a][b];
            }
        return NUMS;
    }
};
int main()
{
    Solution a;
    int R,C,r,c;//ԭ�����к���
    cout <<"����������: ";
    cin >> R;
    cout <<"����������: ";
    cin >> C;
    cout << "�����������Ԫ��: " << endl;
    vector<vector<int>> nums(R, vector<int>(C, 0));//����Ĭ��ֵΪ0
    for (int i = 0; i <R; i++){
        for (int j = 0; j <C; j++)
            cin >> nums[i][j];
        cout << endl;
    }
    cout << "�������: " << endl;
    for (int i = 0; i <R; i++){
        for (int j = 0; j <C; j++)
            cout << nums[i][j];
        cout << endl;
    }
    cout <<"�����¾������: ";
    cin >> r;
    cout <<"�����¾������: ";
    cin >> c;
    cout << "����¾���: " << endl;
    vector <vector<int>>  NUMS = a.matrixReshape1(nums,r,c);
    for (int i = 0; i <r; i++){
        for (int j = 0; j <c; j++)
            cout << NUMS[i][j];
        cout << endl;
    }
    return 0;
}
