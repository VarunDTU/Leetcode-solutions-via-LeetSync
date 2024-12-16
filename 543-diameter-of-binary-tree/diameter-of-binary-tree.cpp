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
    
    int helper(TreeNode* root,int &maxi){
        if(!root)return 0;
        int left=helper(root->left,maxi);
        int right=helper(root->right,maxi);
        maxi=max(left+right,maxi);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};