#include <iostream>
#include <vector>
using namespace std;
class Solution {//���Ʊ������棬ÿ��ֻ�ܳ���һ�ɣ�����������֮��
public:
    //˼·
    //1.��list�ֳɶ�Σ������������Ƚϣ������еĲ���Ͳ��ȵĲ�ֵ��ӣ���Ϊ�������
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int MaxProfit = 0;
        /*for(int i=0; i< prices.size()-1; i++){//i+1 ���Ϊn-1,nΪ���鳤��
            if(prices[i] < prices[i+1])
                MaxProfit += prices[i+1] - prices[i];//�����������
        }*/

        for(int i=1; i< prices.size(); i++){
            if(prices[i] > prices[i-1])
                MaxProfit += prices[i] - prices[i-1];//�����������
        }
        return MaxProfit;
    }
};
int main()
{
    Solution a;
    int A[4] = {2, 8, 6, 9};
    vector<int> prices(A, A+4);
    cout << "��Ʊ�������飺";
    for(int i=0; i< prices.size(); i++){
            cout << prices[i] << " ";
    }
    cout << endl;
    cout << "������棺" << a.maxProfit(prices) << endl;
    return 0;
}
