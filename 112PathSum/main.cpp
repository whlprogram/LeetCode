#include <iostream>

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        else if(root->left==nullptr && root->right==nullptr && root->val==sum)
            return true;
        else
            return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
