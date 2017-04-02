#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// BST是满足如下3个条件的二叉树：
//1. 节点的左子树包含的节点的值小于该节点的值
//2. 节点的右子树包含的节点的值大于等于该节点的值
//3. 节点的左子树和右子树都是BST
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {//递归解法
        if(!root)
            return 0;
        vector<int> InOrderArray;
        getInOrderArray(InOrderArray, root);
        //INT_MAX定义 https://zhidao.baidu.com/question/294243885.html
        int res = INT_MAX;
        for(int i=1; i<InOrderArray.size(); i++){//遍历数组得到相邻两个元素最小的差
            if(InOrderArray[i] - InOrderArray[i-1] < res)
                res = InOrderArray[i] - InOrderArray[i-1];
        }
        return res;
    }
    void getInOrderArray(vector<int> &InOrderArray, TreeNode* root){//通过中序遍历得到一个升序数组
        if(!root)
            return;
        getInOrderArray(InOrderArray, root->left);
        InOrderArray.push_back(root->val);
        getInOrderArray(InOrderArray, root->right);
    }
    int getMinimumDifference1(TreeNode* root) {//非递归解法
        int res = INT_MAX, pre = -1;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if (pre != -1) res = min(res, p->val - pre);
            pre = p->val;
            p = p->right;
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
