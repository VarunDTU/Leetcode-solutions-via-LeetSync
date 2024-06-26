/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
//lee215 typa solution
int sum=0;
    TreeNode* helper(TreeNode* root) {
      if(root->right)helper(root->right);
        sum+=root->val;
        root->val=sum;
        if(root->left)helper(root->left);
        return root;

    }
    TreeNode* bstToGst(TreeNode* root) {
        
        return helper(root);
    }
};