#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 1;
    int y = 0;
    if(x == 0)//���Ⱥź�˫�ȺŲ���Ū��
        y = 1;
    int c = 1;
    while(x != 0)
    {
        int a = x%2;
        int b = a>0?0:1;
        y += b*c;
        c *=2;
        x = x / 2;
    }
    cout << y << endl;
    return 0;
}
