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
    unordered_map<int, int> s;
    int maxi = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        s[sum]++;
        maxi = max(maxi, s[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto itr : s) {
            if (maxi == itr.second)
                ans.push_back({itr.first});
        }
        return ans;
    }
};