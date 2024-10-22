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
    void helper(TreeNode* root,int curr,vector<long long>&arr){
        if(!root)return;
        if(arr.size()==curr)arr.push_back(0);
        arr[curr]+=root->val;
        helper(root->left,curr+1,arr);
        helper(root->right,curr+1,arr);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>arr;
        helper(root,0,arr);
        if(arr.size()<k)return -1;
        nth_element(arr.begin(),arr.begin()+k-1,arr.end(),greater<>());
        return arr[k-1];
    }
};