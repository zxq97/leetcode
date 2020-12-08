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
    void dfs(TreeNode* root, int m, int& ans)
    {
        if(!root)return;
        if(root->val >= m)++ans;
        dfs(root->left, max(m, root->val), ans);
        dfs(root->right, max(m, root->val), ans);
        return;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
        dfs(root, 0x80000000, ans);
        return ans;
    }
};
