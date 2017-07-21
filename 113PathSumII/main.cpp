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
        vector<vector<int>> paths; //�洢��������������·��
        vector<int> temp;//�洢��ǰ����·��
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
end������
����ԭ�ͣ�
iterator end();
const_iterator end();
���ܣ�
����һ����ǰvector������ĩβԪ�صĵ�������
    */
    vector<vector<int>> pathSum1(TreeNode* root, int sum) {//9ms
        vector<vector<int>> paths; //�洢��������������·��
        vector<int> temp;//�洢��ǰ����·��
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
        //ע��temp.end()ָ��������һ��Ԫ�ص���һ��λ�ã����Է������һ��Ԫ�ص���ȷ����Ϊ��temp.end() -1;
        //temp.erase()  ɾ��ĳ��Ԫ��
        temp.erase(temp.end() - 1);
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
        if(index < len && num[index] != -1){
            // ������մ���һ���ڵ�
            TreeNode *leftNode = new TreeNode(num[index]);
            p->left = leftNode;
            queue.push(leftNode);
        }
        index++;
        // �ҽڵ�
        if(index < len && num[index] != -1){
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
    // -1����NULL
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
