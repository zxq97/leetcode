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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
        if(root->left && !root->left->left && !root->left->right)ans = root->left->val;
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        return ans + left + right;
    }
};
