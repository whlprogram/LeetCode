//原题链接 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description
//个人博客 http://blog.csdn.net/whl_program/article/details/72803058

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
        TreeNode *node = new TreeNode(nums[Min]);// 根节点
        node->left = BuildTree(nums, Start, Min-1);// 左子树
        node->right = BuildTree(nums, Min+1, End);// 右子树
        return node;
    }
    // 层次遍历
    vector<vector<int> > LevelOrder(TreeNode *root) {
        vector<int> level;
        vector<vector<int> > levels;
        if(root == NULL){
            return levels;
        }
        queue<TreeNode*> cur,next;
        //入队列
        cur.push(root);//入队 将root元素接到队列的末端；
        // 层次遍历
        while(!cur.empty()){
            //当前层遍历
            while(!cur.empty()){
                TreeNode *p = cur.front();//cur.front() 访问队首元素
                cur.pop();//出队 弹出队列的第一个元素，并不会返回元素的值；
                level.push_back(p->val);
                // next保存下一层节点
                //左子树
                if(p->left){
                    next.push(p->left);
                }
                //右子树
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
