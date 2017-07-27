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
    int helper(TreeNode* root, int pre, int &sum){//ע��preǰ����&
        if(root == nullptr)
            return 0;
        int current = pre + root->val;
        return (current==sum) + helper(root->left, current, sum) + helper(root->right, current, sum);
    }
};
// ����������
TreeNode* CreateTreeByLevel(vector<int> num){
    int len = num.size();
    if(len == 0){
        return NULL;
    }//if
    queue<TreeNode*> queue;
    int index = 0;
    // �������ڵ�
    TreeNode *root = new TreeNode(num[index++]);
    // �����
    queue.push(root);
    TreeNode *p = NULL;
    while(!queue.empty() && index < len){
        // ������
        p = queue.front();
        queue.pop();
        // ��ڵ�
        if(index < len && num[index] != NULL){
            // ������մ���һ���ڵ�
            TreeNode *leftNode = new TreeNode(num[index]);
            p->left = leftNode;
            queue.push(leftNode);
        }
        index++;
        // �ҽڵ�
        if(index < len && num[index] != NULL){
            // ������մ���һ���ڵ�
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
