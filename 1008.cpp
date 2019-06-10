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
    void dfs(TreeNode*& root, int value)
    {
        if(!root){
            root = new TreeNode(value);
            return;
        }
        if(root->val > value)dfs(root->left, value);
        else dfs(root->right, value);
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        if(n <= 0)return 0;
        TreeNode* root = 0;
        for(int i = 0; i < n; ++i)
            dfs(root, pre[i]);
        return root;
    }
};
