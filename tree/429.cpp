/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        int cnt = 1, lastcnt = 0;
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            v.push_back(t->val);
            for(int i = 0; i < t->children.size(); ++i){
                ++lastcnt;
                q.push(t->children[i]);
            }
            --cnt;
            if(!cnt){
                cnt = lastcnt;
                lastcnt = 0;
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};
