//原题链接 https://leetcode.com/problems/diameter-of-binary-tree/#/description
/*
定义一个变量diameter，保存给定二叉树最大diameter值。
通过递归计算左右子树的深度来计算每个节点的diameter，通过和变量 diameter 进行比较，保存较大值。
在每一次递归结束后，返回节点左右子树较大的深度，左子树和右子树的深度相加就是根该节点的diameter。
*/
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
    int diameter  = 0;// 全局变量，记录最大直径
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))//空节点 或者 左右孩子均为空的节点
            return 0;
        getDepth(root);
        return diameter;
    }
    // 此函数是返回树的最大深度
    int getDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(left+right > diameter)//左子树和右子树的深度相加就是根该节点的直径
            diameter = left + right;
        return right>left ? right+1 : left+1;//返回节点左右子树中较大的深度
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
