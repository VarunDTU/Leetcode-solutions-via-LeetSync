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
      TreeNode* helper(vector<int>&inorder,vector<int>&preorder,int x,int y,int a,int b){
  
        if(x>y||a>b)return NULL;

        TreeNode* node=new TreeNode(preorder[a]);
        int cnt=x;
        while(inorder[cnt]!=preorder[a])cnt++;
        node->left=helper(inorder,preorder,x,cnt-1,a+1,a+cnt-x);
       node->right=helper(inorder,preorder,cnt+1,y,a+cnt-x+1,b);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
    }
};