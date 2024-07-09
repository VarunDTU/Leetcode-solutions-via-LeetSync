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
class BSTIterator {
public:
    queue<TreeNode*> st;
    BSTIterator(TreeNode* root) { inorder(root); }

    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        st.push(root);
        inorder(root->right);
    }

    int next() {
        int current = st.front()->val;
        st.pop();
        return current;
    }

    bool hasNext() {
        if (st.empty())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */