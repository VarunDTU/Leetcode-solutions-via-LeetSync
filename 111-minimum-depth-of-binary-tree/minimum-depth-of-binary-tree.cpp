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
    int ans;
    void helper(TreeNode* root, int l) {
        if(!root)return;
        if (!root->left&&!root->right) {
            ans = min(l, ans);
            return;
        }
        helper(root->left, l + 1);
        helper(root->right, l + 1);
    }

public:
    int minDepth(TreeNode* root) {
        ans = INT_MAX;
        if (!root)
            return 0;
        helper(root, 1);
        return ans;
    }
};