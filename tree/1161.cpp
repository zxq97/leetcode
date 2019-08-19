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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1});
        int sum = 0, cnt = 1, lastcnt = 0, deep = 1, cur = root->val;
        while(!q.empty()){
            pair<TreeNode*, int> t = q.front();
            q.pop();
            if(t.first->left){
                q.push({t.first->left, t.second + 1});
                sum += t.first->left->val;
                ++lastcnt;
            }
            if(t.first->right){
                q.push({t.first->right, t.second + 1});
                sum += t.first->right->val;
                ++lastcnt;
            }
            --cnt;
            if(!cnt){
                cnt = lastcnt;
                lastcnt = 0;
                if(sum > cur){
                    cur = sum;
                    deep = t.second + 1;
                }
                sum = 0;
            }
        }
        return deep;
    }
};
