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
    vector<TreeNode*> sorted;
    void BST_to_sorted_list(TreeNode* root) {
        if (!root)
            return;
        BST_to_sorted_list(root->left);
        sorted.push_back(root);
        BST_to_sorted_list(root->right);
    }
    TreeNode* makeBBST(int left, int right) {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root(sorted[mid]);
        root->left = makeBBST(left, mid - 1);
        root->right = makeBBST(mid + 1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        BST_to_sorted_list(root);
        return makeBBST(0, sorted.size() - 1);
    }
};