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
    int f(TreeNode* root)
    {
        if(!root)return 0;
        int sum = 0;
        if(root->left){
            if(root->left->left)sum += root->left->left->val;
            if(root->left->right)sum += root->left->right->val;
        }
        if(root->right){
            if(root->right->left)sum += root->right->left->val;
            if(root->right->right)sum += root->right->right->val;
        }
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)return 0;
        int sum = 0;
        if(!(root->val & 1))sum += f(root);
        sum += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        return sum;
    }
};
