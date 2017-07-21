#include <iostream>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {//16ms
        vector<vector<int>> paths; //存储所有满足条件的路径
        vector<int> temp;//存储当前遍历路径
        help(root, paths, temp, sum);
        return paths;
    }
    void help(TreeNode* &root, vector<vector<int>> &paths, vector<int> temp,  int sum) {
        if(root == nullptr)
            return ;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && sum==root->val)
            paths.push_back(temp);
        if(root->left != nullptr)
            help(root->left, paths, temp, sum-root->val);
        if(root->right != nullptr)
            help(root->right, paths, temp, sum-root->val);
    }
    /*
end函数：
函数原型：
iterator end();
const_iterator end();
功能：
返回一个当前vector容器中末尾元素的迭代器。
    */
    vector<vector<int>> pathSum1(TreeNode* root, int sum) {//9ms
        vector<vector<int>> paths; //存储所有满足条件的路径
        vector<int> temp;//存储当前遍历路径
        help(root, paths, temp, sum);
        return paths;
    }
    void help1(TreeNode* &root, vector<vector<int>> &paths, vector<int> &temp,  int sum) {
        if(root == nullptr)
            return ;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && sum==root->val)
            paths.push_back(temp);
        if(root->left != nullptr)
            help1(root->left, paths, temp, sum-root->val);
        if(root->right != nullptr)
            help1(root->right, paths, temp, sum-root->val);
        //注意temp.end()指向的是最后一个元素的下一个位置，所以访问最后一个元素的正确操作为：temp.end() -1;
        //temp.erase()  删除某个元素
        temp.erase(temp.end() - 1);
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
        if(index < len && num[index] != -1){
            // 如果不空创建一个节点
            TreeNode *leftNode = new TreeNode(num[index]);
            p->left = leftNode;
            queue.push(leftNode);
        }
        index++;
        // 右节点
        if(index < len && num[index] != -1){
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
    // -1代表NULL
    vector<int> num = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    TreeNode* root = CreateTreeByLevel(num);
    vector<vector<int> > paths = s.pathSum(root,22);
    for(int i = 0;i < paths.size();i++){
        for(int j = 0;j < paths[i].size();j++){
            cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
