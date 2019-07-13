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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        vector<double> v;
        int cnt = 1, lastcnt = 0, cur = 0;
        long long sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left){
                q.push(t->left);
                ++lastcnt;
            }
            if(t->right){
                q.push(t->right);
                ++lastcnt;
            }
            --cnt;
            sum += t->val;
            ++cur;
            if(!cnt){
                v.push_back(sum * 1.0 / cur);
                cnt = lastcnt;
                lastcnt = 0;
                sum = 0;
                cur = 0;
            }
        }
        return v;
    }
};
