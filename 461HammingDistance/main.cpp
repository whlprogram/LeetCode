#include <iostream>
#include <string>
using namespace std;
string toBinary(int x)
{
}
int hammingDistance(int x, int y) {
        int a[31],b[31];
        int c=0;
        for(int i=0;i<31;i++)
        {
            if(x%2!=0)
            {
                a[i]=1;
                x=x/2;
            }
            else
            {
                a[i]=0;
                x=x/2;
            }
            if(y%2!=0)
            {
                b[i]=1;
                y=y/2;
            }
            else
            {
                b[i]=0;
                y=y/2;
            }
            if(a[i]!=b[i])
                c++;
        }
        return c;
    }
int main()
{
    cout << hammingDistance(123, 321) << endl;
    return 0;
}

