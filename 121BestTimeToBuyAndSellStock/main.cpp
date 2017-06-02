//原题链接 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    //算法解释 https://discuss.leetcode.com/topic/19853/kadane-s-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input
    //https://en.wikipedia.org/wiki/Maximum_subarray_problem
    int maxProfit(vector<int>& prices) {//9ms
        int maxPro=0,res=0;
        for(int i=1; i<prices.size(); i++){
            maxPro += prices[i] - prices[i-1];
            maxPro = getMax(0, maxPro);
            res = getMax(res, maxPro);
            //cout << "res is = " << res << endl;
        }
        return res;
    }
    int getMax(int a, int b){return a>b ? a : b;}

    //算法解释 https://discuss.leetcode.com/topic/5863/sharing-my-simple-and-clear-c-solution
    //遍历数组，每次遍历时，找出该价格之前的最小价格，同时计算最小价格后的日期的能得到最大利润
    //minPrice是从第0天到第i天的最低价格。 maxPro是从第0天到第i天可以获得的最大利润。
    //在当前maxPro和prices[i] - minPrice之间获得较大的一个就是maxPro。
    int maxProfit1(vector<int> &prices) {//9ms
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
    int getMin(int a, int b){return a<b ? a : b;}
};
int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "max Profit is = " << s.maxProfit(prices) << endl;
    return 0;
}
