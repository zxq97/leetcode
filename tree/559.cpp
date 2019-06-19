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
    int maxDepth(Node* root) {
        if(!root)return 0;
        if(!root->children.size())return 1;
        int ans = 0;
        for(int i = 0; i < root->children.size(); ++i)
            ans = max(ans, maxDepth(root->children[i]) + 1);
        return ans;
    }
};
