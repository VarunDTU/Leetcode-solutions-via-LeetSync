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
    TreeNode* helper(vector<int>&inorder,vector<int>&postorder,int x,int y,int a,int b){
        if(x>y||a>b)return NULL;

        TreeNode* node=new TreeNode(postorder[b]);
        int cnt=x;
        while(inorder[cnt]!=postorder[b])cnt++;
        node->left=helper(inorder,postorder,x,cnt-1,a,a+cnt-1-x);
        node->right=helper(inorder,postorder,cnt+1,y,a+cnt-x,b-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder  left->root->right 
        //postorder  left->right->root 

        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);

    }
};