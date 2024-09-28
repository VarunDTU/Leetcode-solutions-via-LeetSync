/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   bool dfs(TreeNode* root, int k,TreeNode* first){
        if(!first)return false;
        return helper(root,k-(first->val),first)||dfs(root,k,first->left)||dfs(root,k,first->right);
   }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        return dfs(root,k,root);
    }
    bool helper(TreeNode* root, int k,TreeNode*first){
        if(!root)return false;
        if(root->val==k&&root!=first)return true;
        if(root->val<k)return helper(root->right,k,first);
        if(root->val>k)return helper(root->left,k,first);
        return false;
    }
};