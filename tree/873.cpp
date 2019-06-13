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
    void dfs(TreeNode* root, vector<int>& v)
    {
        if(!root)return;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
        return;
    }
    
    int minDiffInBST(TreeNode* root) {
        if(!root)return 0;
        vector<int> v;
        dfs(root, v);
        int ans = 0x3fffffff;
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); ++i)
            ans = min(ans, v[i] - v[i - 1]);
        return ans;
    }
};
