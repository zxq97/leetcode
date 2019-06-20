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
    void in(TreeNode* root, int& last, int& ans)
    {
        if(!root)return;
        in(root->left, last, ans);
        if(last != -1)ans = min(ans, root->val - last);
        last = root->val;
        in(root->right, last, ans);
        return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(!root)return 0;
        int last = -1, ans = 0x7fffffff;
        in(root, last, ans);
        return ans;
    }
};
