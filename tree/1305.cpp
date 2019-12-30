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
    void pre(TreeNode* root, vector<int>& v)
    {
        if(!root)return;
        pre(root->left, v);
        v.push_back(root->val);
        pre(root->right, v);
    }
    
    void merge(const vector<int>& a, const vector<int>& b, vector<int>& ans)
    {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j])ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i < a.size())
            ans.push_back(a[i++]);
        while(j < b.size())
            ans.push_back(b[j++]);
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)return {};
        vector<int> ans, first, second;
        pre(root1, first);
        pre(root2, second);
        merge(first, second, ans);
        return ans;
    }
};
