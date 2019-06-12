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
    void dfs(TreeNode* root, unordered_map<int, int>& m)
    {
        if(!root)return;
        ++m[root->val];
        dfs(root->left, m);
        dfs(root->right, m);
    }
    
    vector<int> findMode(TreeNode* root) {
        if(!root)return {};
        unordered_map<int, int> m;
        dfs(root, m);
        int x = 0;
        for(auto i : m)
            x = max(x, i.second);
        vector<int> ans;
        for(auto i : m)
            if(i.second == x)
                ans.push_back(i.first);
        return ans;
    }
};
