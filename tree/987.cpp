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
    void dfs(TreeNode* root, int x, int y, map<pair<int, int>, vector<int>>& m)
    {
        if(!root)return;
        m[{x, y}].push_back(root->val);
        dfs(root->left, x - 1, y + 1, m);
        dfs(root->right, x + 1, y + 1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> m;
        dfs(root, 0, 0, m);
        vector<vector<int>> v;
        map<int, vector<int>> h;
        for(auto i : m){
            sort(i.second.begin(), i.second.end());
            for(int j = 0; j < i.second.size(); ++j)
                h[i.first.first].push_back(i.second[j]);
        }
        for(auto i : h)
            v.push_back(i.second);
        return v;
    }
};
