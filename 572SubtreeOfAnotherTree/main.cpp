//ԭ������ https://leetcode.com/problems/subtree-of-another-tree/#/description
/*
���������ǿն�������s��t�������t�Ƿ������s������ȫ��ͬ�Ľṹ�ͽڵ�ֵ��
s����������s�еĽڵ����������ڵ�ĺ����ɵ����� ��Ҳ���Ա���Ϊ��һ�������������
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
        //�������if����Ҫ,��Ŀ����������Ϊ�ǿն�����������s(��s������)Ϊ�գ�ֱ�ӷ���false)
        if (s == nullptr) //�ǿն�����
            return false;
        if(isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    //�ж������������Ƿ���ͬ
    bool isSame(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr)//�ڵ��Ϊ��
            return true;
        if(s == nullptr || t == nullptr)//(�ڵ㲻�Ǿ�Ϊ�������)sΪ�ջ���tΪ��
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
