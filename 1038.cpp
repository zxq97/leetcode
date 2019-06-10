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
    struct cmp
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)const
        {
            return a.first < b.first;
        }
    };
    
    void dfs(TreeNode* root, vector<pair<int, int>>& v)
    {
        if(!root)return;
        v.push_back({root->val, 0});
        dfs(root->left, v);
        dfs(root->right, v);
        return;
    }
    
    int binary_search(const vector<pair<int, int>>& v, const int value)
    {
        int l = 0, r = v.size() - 1;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(v[m].first < value)l = m + 1;
            else if(v[m].first > value)r = m - 1;
            else return m;
        }
        return -1;
    }
    
    void update(TreeNode* root, const vector<pair<int, int>>& v)
    {
        if(!root)return;
        int idx = binary_search(v, root->val);
        if(idx == -1)return;
        root->val = v[idx].second;
        update(root->left, v);
        update(root->right, v);
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)return 0;
        vector<pair<int, int>> v;
        dfs(root, v);
        sort(v.begin(), v.end(), cmp());
        v.back().second = v.back().first;
        for(int i = v.size() - 2; i >= 0; --i)
            v[i].second = v[i].first + v[i + 1].second;
        update(root, v);
        return root;
    }
};
