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
    bool dfs(TreeNode* root, const int val)
    {
        if(!root)return 1;
        if(root->val != val)return 0;
        return dfs(root->left, val) & dfs(root->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(!root)return 1;
        int val = root->val;
        return dfs(root, val);
    }
};
