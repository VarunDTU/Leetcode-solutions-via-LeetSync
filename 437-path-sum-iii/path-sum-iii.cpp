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
    long long ans=0;
public:
    int dfs(TreeNode *root,long long sum){
        if(!root)return 0;

        if(sum==root->val)ans++;
        dfs(root->left,(long long)sum-root->val);
        dfs(root->right,(long long)sum-root->val);
        return ans;
    }
    int pathSum(TreeNode* root, long long targetSum) {
    
        if(!root)return 0;
         dfs(root,targetSum);
         pathSum(root->left,targetSum);
         pathSum(root->right,targetSum);
         return ans;
    }
};