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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr)
            if(p == q)
                return true;
            else
                return false;
        return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
