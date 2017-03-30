#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    public:
        vector<string> findWords(vector<string>& words) {
            vector<string> res;
            unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
            unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
            unordered_set<char> row3{'z','x','c','v','b','n','m'};
            for (string word : words) {
                int one = 0, two = 0, three = 0;

                string s = word;
                int index=0;
                while(s[index]!='\0') {
                    if (s[index] < 'a') s[index] += 32;
                    if (row1.count(s[index])) one = 1;
                    if (row2.count(s[index])) two = 1;
                    if (row3.count(s[index])) three = 1;
                    if (one + two + three > 1) break;

                    cout<<s[index++];
                }
                if (one + two + three == 1) res.push_back(word);
            }
            return res;
        }
};

int main()
{
    char a[]="asdf";
    cout<<a<<endl;

    string words[] = {"Hello", "Alaska", "Dad", "Peace"};

    cout<<findWords(words)<<endl;
    return 0;
}
