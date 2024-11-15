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
    void helper(TreeNode* root,vector<int>&dic,int lvl){
        if(!root)return ;

        if(dic.size()<=lvl){
            dic.push_back({root->val});
        }
        helper(root->right,dic,lvl+1);
        helper(root->left,dic,lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightSide;
        helper(root,rightSide,0);
        return rightSide;
    }
};