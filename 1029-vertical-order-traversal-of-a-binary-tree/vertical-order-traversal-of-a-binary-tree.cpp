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
    void helper(TreeNode* root, map<int,map<int,vector<int>>>&mp, int x,
                int y) {

        if (!root)
            return;
        mp[x][y].push_back(root->val);
        helper(root->left, mp, x - 1, y + 1);
        helper(root->right, mp, x + 1, y +1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,vector<int>>>mp;
        helper(root, mp, 0, 0);
        vector<vector<int>> ans;
        for (auto itr : mp) {
            vector<int> col;
            for (auto itr2 : itr.second) {
                sort(itr2.second.begin(),itr2.second.end());
                col.insert(col.end(), itr2.second.begin(), itr2.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};