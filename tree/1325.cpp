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
    bool isChild(TreeNode* root)
    {
        if(!root)return 0;
        return !root->left && !root->right;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return root;
        if(root->left){
            if(!isChild(root->left))
                root->left = removeLeafNodes(root->left, target);
            if(isChild(root->left)){
                if(root->left->val == target)
                    root->left = 0;
            }
        }
        if(root->right){
            if(!isChild(root->right))
                root->right = removeLeafNodes(root->right, target);
            if(isChild(root->right)){
                if(root->right->val == target)
                    root->right = 0;
            }
        }
        if(isChild(root) && root->val == target)return 0;
        return root;
    }
};
