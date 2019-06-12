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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1, lastcnt = 0, x = 0x80000000;
        while(!q.empty()){
            x = max(x, q.front()->val);
            --cnt;
            if(q.front()->left){
                q.push(q.front()->left);
                ++lastcnt;
            }
            if(q.front()->right){
                q.push(q.front()->right);
                ++lastcnt;
            }
            if(!cnt){
                ans.push_back(x);
                x = 0x80000000;
                cnt = lastcnt;
                lastcnt = 0;
            }
            q.pop();
        }
        return ans;
    }
};
