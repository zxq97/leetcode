/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    void dfs(TreeNode*& root, int cur)
    {
        if(!root)return;
        root->val = cur;
        if(root->left)dfs(root->left, cur * 2 + 1);
        if(root->right)dfs(root->right, cur * 2 + 2);
        return;
    }
    
    FindElements(TreeNode* root) {
        if(!root)return;
        dfs(root, 0);
        this->root = root;
    }
    
    bool find(int target) {
        return find(this->root, target);
    }
    
    bool find(TreeNode* root, const int target)
    {
        if(!root || root->val > target)return 0;
        if(root->val == target)return 1;
        return find(root->left, target) | find(root->right, target);
    }
    
private:
    TreeNode* root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
