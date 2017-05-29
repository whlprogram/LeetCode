//ԭ������ https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description
//���˲��� http://blog.csdn.net/whl_program/article/details/72803058

#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode *sortedArrayToBST(vector<int>& nums) {//16ms
        return BuildTree(nums, 0, nums.size()-1);
    }
    TreeNode *BuildTree(vector<int> &nums, int Start, int End){
        if(Start > End) return nullptr;
        if(Start == End) return new TreeNode(nums[Start]);
        int Min = (Start+End)/2;
        TreeNode *node = new TreeNode(nums[Min]);// ���ڵ�
        node->left = BuildTree(nums, Start, Min-1);// ������
        node->right = BuildTree(nums, Min+1, End);// ������
        return node;
    }
    // ��α���
    vector<vector<int> > LevelOrder(TreeNode *root) {
        vector<int> level;
        vector<vector<int> > levels;
        if(root == NULL){
            return levels;
        }
        queue<TreeNode*> cur,next;
        //�����
        cur.push(root);//��� ��rootԪ�ؽӵ����е�ĩ�ˣ�
        // ��α���
        while(!cur.empty()){
            //��ǰ�����
            while(!cur.empty()){
                TreeNode *p = cur.front();//cur.front() ���ʶ���Ԫ��
                cur.pop();//���� �������еĵ�һ��Ԫ�أ������᷵��Ԫ�ص�ֵ��
                level.push_back(p->val);
                // next������һ��ڵ�
                //������
                if(p->left){
                    next.push(p->left);
                }
                //������
                if(p->right){
                    next.push(p->right);
                }
            }//end while
            levels.push_back(level);
            level.clear();
            swap(next,cur);
        }//end while
        return levels;
    }
};
int main()
{
    Solution S;
    vector<int> num = {0,1,2,3,4,5,6,7,8,9};
    TreeNode* root = S.sortedArrayToBST(num);
    vector<vector<int> > levels = S.LevelOrder(root);
    for(int i = 0;i < levels.size();i++){
        for(int j = 0;j < levels[i].size();j++){
            cout<<levels[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
