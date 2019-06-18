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
        if(!root)return 0;
        if(root->val == val)return 1;
        if(root->val > val)return dfs(root->left, val);
        return dfs(root->right, val);
    }
    
    void in(TreeNode* root, TreeNode* r, const int k, bool& ans)
    {
        if(!root || ans)return;
        in(root->left, r, k, ans);
        if(ans)return;
        if((k >> 1) != root->val)
            ans = dfs(r, k - root->val);
        if(ans)return;
        in(root->right, r, k, ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root || (!root->left && !root->right))return 0;
        bool ans = 0;
        in(root, root, k, ans);
        return ans;
    }
};
