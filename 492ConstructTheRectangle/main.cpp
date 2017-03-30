#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area){
        vector<int> Array(2);
       if(area<=0 || area>10000000)//输入不合法时的情况
       {
            return Array;
       }
        int temp = 0;
        for(int i=1; i<=area; i++)
        {
            if(area%i == 0)//找到area的因数时
            {
                Array[0] = i;
                Array[1] = area/i;
                if(i == temp)//必须放到这个位置，因为要求输出Array[1]<=Array[0]
                    return Array;
                if(Array[0] == Array[1])
                    return Array;
                temp = Array[1];
            }
        }
        return Array;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
