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
    void dfs(TreeNode* root, string& s, priority_queue<string, vector<string>, greater<string>>& q)
    {
        if(!root)return;
        s += 'a' + root->val;
        if(!root->left && !root->right){
            string t = s;
            reverse(t.begin(), t.end());
            q.push(t);
            s.pop_back();
            return;
        }
        dfs(root->left, s, q);
        dfs(root->right, s, q);
        s.pop_back();
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(!root)return "";
        priority_queue<string, vector<string>, greater<string>> q;
        string s;
        dfs(root, s, q);
        return q.top();
    }
};
