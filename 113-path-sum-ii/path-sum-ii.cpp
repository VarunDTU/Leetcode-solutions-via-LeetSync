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
   void helper(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>temp){
        if(root!=NULL&&root->left==NULL&&root->right==NULL&&targetSum==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        if(!root)return;
        temp.push_back(root->val);
        helper(root->left,targetSum-root->val,ans,temp);
        helper(root->right,targetSum-root->val,ans,temp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root,targetSum,ans,{});
        return ans;
    }
};