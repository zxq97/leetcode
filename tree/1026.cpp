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
    void dfs(TreeNode* root, vector<int>& v, int& ans)
    {
        if(!root)return;
        for(int i = 0; i < v.size(); ++i)
            ans = max(ans, abs(root->val - v[i]));
        v.push_back(root->val);
        dfs(root->left, v, ans);
        dfs(root->right, v, ans);
        v.pop_back();
        return;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        vector<int> v;
        int ans = 0;
        dfs(root, v, ans);
        return ans;
    }
};
