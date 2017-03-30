#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int Vertical_length = grid.size();//垂直长度 行数
        int Horizontal_length = grid[0].size();//水平长度 列数
        int island = 0;//正方形个数
        int repeat = 0;//两个正方形间重复的边数
        int perimeter = 0;//总边长
        for(int i=0;i<Vertical_length;i++)
        {
            for(int j=0;j<Horizontal_length;j++)
            {
                if(!grid[i][j])//元素为0 跳出循环
                    continue;
                island++;//计算正方形个数
                if(i!=0 && grid[i-1][j])//非第一行元素 && grid[i-1][j]和grid[i][j]均为1
                    repeat++;//重复的边数+1
                if(j!=0 && grid[i][j-1])//非第一列元素 && grid[i][j-1]和grid[i][j]均为1
                    repeat++;
            }
        }
        perimeter = 4 * island - 2 * repeat;//计算总边长
        return perimeter;
    }
};
int main()
{
    Solution a;
    cout << "hello word!" << endl;
    return 0;
}
