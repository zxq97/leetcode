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
    int f(string& s)
    {
        int sum = 0;
        for(int i = 0; i< s.length(); ++i){
            sum |= s[i] == '1' ? 1 : 0;
            if(i != s.length() - 1)
                sum <<= 1;
        }
        s.pop_back();
        return sum;
    }
    
    int dfs(TreeNode* root, string& s)
    {
        if(!root)return 0;
        s += to_string(root->val);
        if(!root->left && !root->right)return f(s);
        int sum = dfs(root->left, s) + dfs(root->right, s);
        s.pop_back();
        return sum;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(!root)return 0;
        string s;
        return dfs(root, s);
    }
};
