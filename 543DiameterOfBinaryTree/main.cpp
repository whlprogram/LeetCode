//ԭ������ https://leetcode.com/problems/diameter-of-binary-tree/#/description
/*
����һ������diameter������������������diameterֵ��
ͨ���ݹ�����������������������ÿ���ڵ��diameter��ͨ���ͱ��� diameter ���бȽϣ�����ϴ�ֵ��
��ÿһ�εݹ�����󣬷��ؽڵ����������ϴ����ȣ����������������������Ӿ��Ǹ��ýڵ��diameter��
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
    int diameter  = 0;// ȫ�ֱ�������¼���ֱ��
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))//�սڵ� ���� ���Һ��Ӿ�Ϊ�յĽڵ�
            return 0;
        getDepth(root);
        return diameter;
    }
    // �˺����Ƿ�������������
    int getDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(left+right > diameter)//���������������������Ӿ��Ǹ��ýڵ��ֱ��
            diameter = left + right;
        return right>left ? right+1 : left+1;//���ؽڵ����������нϴ�����
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
