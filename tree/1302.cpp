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
    int getDeep(TreeNode* root)
    {
        if(!root)return 0;
        int deep = 0;
        return max(getDeep(root->left), getDeep(root->right)) + 1;
    }
    
    int dfs(TreeNode* root, int curDeep, const int deep)
    {
        if(!root)return 0;
        if(curDeep == deep)
            return root->val;
        return dfs(root->left, curDeep + 1, deep) + dfs(root->right, curDeep + 1, deep);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int deep = getDeep(root);
        return dfs(root, 1, deep);
    }
};
