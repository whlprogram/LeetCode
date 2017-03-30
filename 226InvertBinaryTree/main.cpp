#include <iostream>

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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {//·­×ª¶þ²æÊ÷ µÝ¹é
        if(root == NULL)
            return NULL;

        TreeNode* temp = root.left;
        root.left = root.right;
        root.right = temp;

        invertTree(root.left);
        invertTree(root.right);

        return root;
    }
    TreeNode* invertTree1(TreeNode* root) {//·­×ª¶þ²æÊ÷ ·ÇµÝ¹é
            queue<treenode> tbpNode;
            if(root) tbpNode.push(root);
            TreeNode *curNode, *temp;
            while(!tbpNode.empty())
            {
                curNode = tbpNode.front();
                tbpNode.pop();
                temp = curNode->left;
                curNode->left = curNode->right;
                curNode->right = temp;
                if(curNode->left) tbpNode.push(curNode->left);
                if(curNode->right) tbpNode.push(curNode->right);
            }
            return root;
        }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
