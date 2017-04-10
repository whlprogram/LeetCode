#include <iostream>
using namespace std;
class Solution {//求左叶子节点的和
public:
    // Definition for a binary tree node.
    struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        //判断节点是否有左孩子
        if(root->left){//节点有左孩子节点
            if(root->left->left == nullptr && root->left->right == nullptr)//节点左孩子是叶子节点
                return root->left->val + sumOfLeftLeaves(root->right);
            else//节点左孩子有子节点
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        else//节点没有左孩子节点
            return sumOfLeftLeaves(root->right);
    }

    int sumOfLeftLeaves1(TreeNode* root) {
        //如果root为空，返回0
        if(root == nullptr)
            return 0;
        //判断节点是否为左叶子节点
        //如果左子树即为左叶子节点，则返回左叶子节点的val值+sumOfLeftLeaves（右子树）的值
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
            return root->left->val+sumOfLeftLeaves(root->right);
        else
        //否则返回递归调用sumOfLeftLeaves（左子树）+sumOfLeftLeaves（右子树）的值
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }

    //先判断是否是叶子节点，然后是判断是否是左孩子，叶子节点很容易判断，左孩子需要加一个标记。
    int sumOfLeftLeaves2(TreeNode* root) {
        int res = 0;
        DFS(root, 0, res);//0 false   1 true
        return res;
    }
    void DFS(TreeNode* root, bool f, int&s){//bool 判断是否为左孩子 0 false   1 true
        if(!root)//节点为空
            return;
        if(!root->left && !root->right){//节点左右孩子为空(叶子节点)
            if(f)
                s += root->val;
             return;
        }
        if(root->left)
            DFS(root->left, 1, s);
        if(root->right)
            DFS(root->right, 0, s);
    }
};
int main()
{
    if(1)
        cout << "Hello world!" << endl;
    return 0;
}
