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
   
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=1;
        while(!q.empty()){
            long long e=q.back().second;
            long long s=q.front().second;
            long long k=q.size();
            
            ans=max(e-s+1,ans);
            while(k--){
                TreeNode* node=q.front().first;
                int x=q.front().second;
                q.pop();
                if(node->left)q.push({node->left,(long long)2*x});
                if(node->right)q.push({node->right,(long long)2*x+1});
            }

        }
        return ans;
    }
};