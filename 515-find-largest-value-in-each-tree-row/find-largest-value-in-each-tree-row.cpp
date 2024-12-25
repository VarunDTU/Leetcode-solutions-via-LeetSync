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
    vector<int> ans;
public:
    void helper(TreeNode* root,int level){
        if(!root)return ;
        if(ans.size()<level+1)ans.push_back(root->val);
        else ans[level]=max(ans[level],root->val);
        helper(root->left,level+1);
        helper(root->right,level+1);

    }
    vector<int> largestValues(TreeNode* root) {
        
        helper(root,0);
        return ans;
    }
};