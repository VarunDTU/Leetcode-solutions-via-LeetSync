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
    vector<int>levelsum;
    void calculate_level_sum(TreeNode* root,int lvl){
        if(!root)return;
        if(levelsum.size()==lvl)levelsum.push_back(root->val);
        else levelsum[lvl]+=root->val;
        calculate_level_sum(root->left,lvl+1);
        calculate_level_sum(root->right,lvl+1);
    }
    void cousin_sum(TreeNode*root,int prev,int lvl){
        if(!root)return;
        root->val=levelsum[lvl]-prev;
        prev=root->left?root->left->val:0;
        prev+=root->right?root->right->val:0;
        cousin_sum(root->left,prev,lvl+1);
        cousin_sum(root->right,prev,lvl+1);
        }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculate_level_sum(root,0);
        cousin_sum(root,root->val,0);
        return root;
    }
};