/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*& root, TreeNode*& last)
    {
        if(!root)return;
        dfs(root->right, last);
        root->right = last;
        last = root;
        TreeNode* left = root->left;
        root->left = 0;
        dfs(left, last);
    }
    
    TreeNode* findLeft(TreeNode* root)
    {
        if(!root->left)return root;
        return findLeft(root->left);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return root;
        TreeNode* last = 0;
        TreeNode* left = findLeft(root);
        dfs(root, last);
        return left;
    }
};
