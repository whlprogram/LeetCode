#include <iostream>
#include <queue>
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
    int pathSum(TreeNode* root, int sum) {//23ms
        if(root == nullptr)
            return 0;
        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int helper(TreeNode* root, int pre, int &sum){//注意pre前不加&
        if(root == nullptr)
            return 0;
        int current = pre + root->val;
        return (current==sum) + helper(root->left, current, sum) + helper(root->right, current, sum);
    }
};
// 创建二叉树
TreeNode* CreateTreeByLevel(vector<int> num){
    int len = num.size();
    if(len == 0){
        return NULL;
    }//if
    queue<TreeNode*> queue;
    int index = 0;
    // 创建根节点
    TreeNode *root = new TreeNode(num[index++]);
    // 入队列
    queue.push(root);
    TreeNode *p = NULL;
    while(!queue.empty() && index < len){
        // 出队列
        p = queue.front();
        queue.pop();
        // 左节点
        if(index < len && num[index] != NULL){
            // 如果不空创建一个节点
            TreeNode *leftNode = new TreeNode(num[index]);
            p->left = leftNode;
            queue.push(leftNode);
        }
        index++;
        // 右节点
        if(index < len && num[index] != NULL){
            // 如果不空创建一个节点
            TreeNode *rightNode = new TreeNode(num[index]);
            p->right = rightNode;
            queue.push(rightNode);
        }
        index++;
    }//while
    return root;
}

int main()
{
    Solution s;
    vector<int> num = {10,5,-3,3,2,NULL,11,3,-2,NULL,1};
    TreeNode* root = CreateTreeByLevel(num);
    cout<< s.pathSum(root,8) <<endl;
    return 0;
}
