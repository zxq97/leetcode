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
    void dfs(TreeNode* root, int& sum)
    {
        if(!root)return;
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return root;
        dfs(root, sum);
        return root;
    }
    
private:
    int sum = 0;
};
