//原题链接 https://leetcode.com/problems/subtree-of-another-tree/#/description
/*
给定两个非空二进制树s和t，检查树t是否具有与s子树完全相同的结构和节点值。
s的子树是由s中的节点和所有这个节点的后代组成的树。 树也可以被认为是一个本身的子树。
*/
#include <iostream>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //下面这个if很重要,题目给定两个均为非空二叉树，假如s(或s的子树)为空，直接返回false)
        if (s == nullptr) //非空二叉树
            return false;
        if(isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    //判断两个二叉树是否相同
    bool isSame(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr)//节点均为空
            return true;
        if(s == nullptr || t == nullptr)//(节点不是均为空情况下)s为空或者t为空
            return false;
        if(s->val != t->val)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
