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
    const string c = "->";
    void dfs(TreeNode* root, string s, vector<string>& ans)
    {
        if(!root)return;
        if(s.length())
            s += c;
        s += to_string(root->val);
        if(!root->left && !root->right)
            ans.push_back(s);
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
        s.pop_back();
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {};
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};
