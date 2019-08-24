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
    void dfs(TreeNode* root, int deep, vector<int>& v)
    {
        if(!root)return;
        if(deep == v.size())
            v.push_back(root->val);
        else
            v[deep] = root->val;
        dfs(root->left, deep + 1, v);
        dfs(root->right, deep + 1, v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> v;
        dfs(root, 0, v);
        return v;
    }
};
