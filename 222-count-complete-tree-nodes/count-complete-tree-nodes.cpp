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
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        TreeNode* r = root;
        TreeNode* l = root;
        int right = 0, left = 0;
        while (r!=NULL) {
            r = r->right;
            right++;
        }
        while (l!=NULL) {
            l = l->left;
            left++;
        }
        return left == right ?  pow(2, left) - 1
                             :1+ countNodes(root->left) + countNodes(root->right);
    }
};