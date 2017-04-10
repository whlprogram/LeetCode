#include <iostream>
using namespace std;
class Solution {//����Ҷ�ӽڵ�ĺ�
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
        //�жϽڵ��Ƿ�������
        if(root->left){//�ڵ������ӽڵ�
            if(root->left->left == nullptr && root->left->right == nullptr)//�ڵ�������Ҷ�ӽڵ�
                return root->left->val + sumOfLeftLeaves(root->right);
            else//�ڵ��������ӽڵ�
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        else//�ڵ�û�����ӽڵ�
            return sumOfLeftLeaves(root->right);
    }

    int sumOfLeftLeaves1(TreeNode* root) {
        //���rootΪ�գ�����0
        if(root == nullptr)
            return 0;
        //�жϽڵ��Ƿ�Ϊ��Ҷ�ӽڵ�
        //�����������Ϊ��Ҷ�ӽڵ㣬�򷵻���Ҷ�ӽڵ��valֵ+sumOfLeftLeaves������������ֵ
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
            return root->left->val+sumOfLeftLeaves(root->right);
        else
        //���򷵻صݹ����sumOfLeftLeaves����������+sumOfLeftLeaves������������ֵ
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }

    //���ж��Ƿ���Ҷ�ӽڵ㣬Ȼ�����ж��Ƿ������ӣ�Ҷ�ӽڵ�������жϣ�������Ҫ��һ����ǡ�
    int sumOfLeftLeaves2(TreeNode* root) {
        int res = 0;
        DFS(root, 0, res);//0 false   1 true
        return res;
    }
    void DFS(TreeNode* root, bool f, int&s){//bool �ж��Ƿ�Ϊ���� 0 false   1 true
        if(!root)//�ڵ�Ϊ��
            return;
        if(!root->left && !root->right){//�ڵ����Һ���Ϊ��(Ҷ�ӽڵ�)
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
