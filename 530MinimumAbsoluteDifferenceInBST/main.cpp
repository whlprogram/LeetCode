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
// BST����������3�������Ķ�������
//1. �ڵ�������������Ľڵ��ֵС�ڸýڵ��ֵ
//2. �ڵ�������������Ľڵ��ֵ���ڵ��ڸýڵ��ֵ
//3. �ڵ��������������������BST
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {//�ݹ�ⷨ
        if(!root)
            return 0;
        vector<int> InOrderArray;
        getInOrderArray(InOrderArray, root);
        //INT_MAX���� https://zhidao.baidu.com/question/294243885.html
        int res = INT_MAX;
        for(int i=1; i<InOrderArray.size(); i++){//��������õ���������Ԫ����С�Ĳ�
            if(InOrderArray[i] - InOrderArray[i-1] < res)
                res = InOrderArray[i] - InOrderArray[i-1];
        }
        return res;
    }
    void getInOrderArray(vector<int> &InOrderArray, TreeNode* root){//ͨ����������õ�һ����������
        if(!root)
            return;
        getInOrderArray(InOrderArray, root->left);
        InOrderArray.push_back(root->val);
        getInOrderArray(InOrderArray, root->right);
    }
    int getMinimumDifference1(TreeNode* root) {//�ǵݹ�ⷨ
        //resΪ��С�preΪǰ�ڵ�ֵ��BSTû�и��������Զ���Ϊ-1
        int res = INT_MAX, pre = -1;
        //Stack<TreeNode*> InOrderArray = new Stack<>();
        stack<TreeNode*> InOrderArray;//����һ��ջ
        TreeNode *p = root;
        while (p || !InOrderArray.empty()) {//�ǿ��ж�
            while (p) {
                InOrderArray.push(p);
                p = p->left;
            }
            p = InOrderArray.top();//ջ��Ԫ��
            InOrderArray.pop();//���±���ջ
            if (pre != -1)
                res = min(res, p->val - pre);
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
