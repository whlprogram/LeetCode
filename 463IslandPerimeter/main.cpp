#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int Vertical_length = grid.size();//��ֱ���� ����
        int Horizontal_length = grid[0].size();//ˮƽ���� ����
        int island = 0;//�����θ���
        int repeat = 0;//���������μ��ظ��ı���
        int perimeter = 0;//�ܱ߳�
        for(int i=0;i<Vertical_length;i++)
        {
            for(int j=0;j<Horizontal_length;j++)
            {
                if(!grid[i][j])//Ԫ��Ϊ0 ����ѭ��
                    continue;
                island++;//���������θ���
                if(i!=0 && grid[i-1][j])//�ǵ�һ��Ԫ�� && grid[i-1][j]��grid[i][j]��Ϊ1
                    repeat++;//�ظ��ı���+1
                if(j!=0 && grid[i][j-1])//�ǵ�һ��Ԫ�� && grid[i][j-1]��grid[i][j]��Ϊ1
                    repeat++;
            }
        }
        perimeter = 4 * island - 2 * repeat;//�����ܱ߳�
        return perimeter;
    }
};
int main()
{
    Solution a;
    cout << "hello word!" << endl;
    return 0;
}
