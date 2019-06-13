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
    void dfs(TreeNode*& root, const int val, bool flag)
    {
        if(!root || flag)return;
        if(!root->left && root->val > val){
            root->left = new TreeNode(val);
            flag = 1;
            return;
        }
        if(!root->right && root->val < val){
            root->right = new TreeNode(val);
            flag = 1;
            return;
        }
        root->val > val ? dfs(root->left, val, flag) : dfs(root->right, val, flag);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return root;
        dfs(root, val, 0);
        return root;
    }
};
