#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        int SUM = 0;
        return res = help(root, res, temp, SUM, sum);
    }
    vector<vector<int>> help(TreeNode* &root, vector<vector<int>> &res, vector<int> &temp, int &SUM, int &sum) {
        if(root == nullptr)
            return res;
        else if(root->left==nullptr && root->right==nullptr ){
            SUM += root->val;
            if(SUM == sum)
                res.push_back(temp);
            else
                temp.clear();
            SUM = 0;
        }
        else{
            SUM += root->val;
            temp.push_back(root->val);

        }
        help(root->left, res, temp, SUM, sum);
            help(root->right, res, temp, SUM, sum);
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
