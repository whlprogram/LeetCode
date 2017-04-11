#include <iostream>
#include <vector>
using namespace std;
class Solution {//求股票最大收益，每次只能持有一股，卖必须在买之后
public:
    //思路
    //1.将list分成多段，两个相邻数比较，将其中的波峰和波谷的差值相加，即为最大利益
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int MaxProfit = 0;
        /*for(int i=0; i< prices.size()-1; i++){//i+1 最大为n-1,n为数组长度
            if(prices[i] < prices[i+1])
                MaxProfit += prices[i+1] - prices[i];//更新最大利益
        }*/

        for(int i=1; i< prices.size(); i++){
            if(prices[i] > prices[i-1])
                MaxProfit += prices[i] - prices[i-1];//更新最大利益
        }
        return MaxProfit;
    }
};
int main()
{
    Solution a;
    int A[4] = {2, 8, 6, 9};
    vector<int> prices(A, A+4);
    cout << "股票近期行情：";
    for(int i=0; i< prices.size(); i++){
            cout << prices[i] << " ";
    }
    cout << endl;
    cout << "最大收益：" << a.maxProfit(prices) << endl;
    return 0;
}
