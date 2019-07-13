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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t2)return t1;
        if(!t1)return t2;
        t1->val += t2->val;
        if(!t1->left)
            t1->left = t2->left;
        else
            mergeTrees(t1->left, t2->left);
        if(!t1->right)
            t1->right = t2->right;
        else
            mergeTrees(t1->right, t2->right);
        return t1;
    }
};
