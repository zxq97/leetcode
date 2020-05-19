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
    void in(TreeNode* root, vector<int>& v)
    {
        if(!root)return;
        in(root->left, v);
        v.push_back(root->val);
        in(root->right, v);
        return;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)return 1;
        vector<int> v;
        in(root, v);
        for(int i = 1; i < v.size(); ++i)
            if(v[i] <= v[i - 1])
                return 0;
        return 1;
    }
};
