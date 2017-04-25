//求出各个节点 左右子树的差 的绝对值，将这些绝对值求和并返回
//左右子树的差 = | 左子树所有节点的值的和 - 右子树所有节点的值的和 |
#include <iostream>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int tilt = 0;
    int findTilt(TreeNode* root) {
        sum(root);
        return tilt;
    }
    int sum(TreeNode* root){//自顶向下求解
        if(root == nullptr)
            return 0;
        int left = sum(root->left);//左子树各节点和
        int right = sum(root->right);//右子树各节点和
        tilt += left>right ? left-right : right-left;
        //tilt += abs(left - right);
        return left + right + root->val;//返回左右子树各节点和
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
