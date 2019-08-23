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
    void dfs(TreeNode* root, string& s)
    {
        if(!root)return;
        s += '(';
        s += to_string(root->val);
        if(root->left)
            dfs(root->left, s);
        else if(!root->left && root->right)
            s += "()";
        if(root->right)
            dfs(root->right, s);
        s += ')';
    }
    
    string tree2str(TreeNode* t) {
        if(!t)return "";
        string s;
        dfs(t, s);
        s.erase(0, 1);
        s.pop_back();
        return s;
    }
};
