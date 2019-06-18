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
    TreeNode* dfs(int l, int r, const vector<int>& nums)
    {
        if(l > r)return 0;
        int idx = l;
        for(int i = l; i <= r; ++i)
            if(nums[i] > nums[idx])idx = i;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = dfs(l, idx - 1, nums);
        root->right = dfs(idx + 1, r, nums);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(!nums.size())return 0;
        return dfs(0, nums.size() - 1, nums);
    }
};
