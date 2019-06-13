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
    void dfs(TreeNode* root, const int val, TreeNode*& ans, bool flag)
    {
        if(!root || flag)return;
        if(root->val == val){
            flag = 1;
            ans = root;
            return;
        }
        dfs(root->left, val, ans, flag);
        dfs(root->right, val, ans, flag);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return root;
        TreeNode* ans = 0;
        dfs(root, val, ans, 0);
        return ans;
    }
};
