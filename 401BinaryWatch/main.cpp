#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        if(num<0 || num>8)
            return times;
        vector<vector <int>> hours(4);
        vector<vector <int>> minutes(6);
        for(int i=0; i<12; i++){
            hours[numOfRow(i)].push_back(i);
        }
        for(int j=0; j<60; j++){
            minutes[numOfRow(j)].push_back(j);
        }
        for(int h=0; h<4&&h<=num; h++){
            if(num-h<6){
                for(int H: hours[h]){
                    for(int M: minutes[num-h]){
                        string time = M<10 ? ":0" : ":";
                        times.push_back(to_string(H) + time + to_string(M));
                    }
                }
            }
        }
        return times;
    }
    int numOfRow(int num){
        int Count = 0;
        while(num != 0){
            if(num%2 == 1)
                Count++;
            num /= 2;
        }
        return Count;
    }

    vector<string> readBinaryWatch1(int num) {//bitset STL模板
        vector<string> times;
        for (int i = 0; i < 12; i++) {
            bitset<4> h(i);//4位的二进制数
            for (int j = 0; j < 60; j++) {
                bitset<6> m(j);//6位的二进制数
                if (h.count() + m.count() == num)//h.count()函数判断h中1的个数
                    times.push_back(to_string(i) + (j < 10? ":0": ":") + to_string(j));
            }
        }
        return times;
    }
};
int main()
{
    Solution a;
    int num = 0;
    cin >> num;
    vector<string> times = a.readBinaryWatch1(num);
    for(int t=0; t<times.size(); t++)
        cout << times[t] << endl;
    return 0;
}
