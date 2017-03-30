#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 1;
    int y = 0;
    if(x == 0)//单等号和双等号不能弄混
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
