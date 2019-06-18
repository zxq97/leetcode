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
    void dfs(TreeNode* root, const int val, int& ans, bool& flag)
    {
        if(!root)return;
        if(!root->left && !root->right){
            if(root->val != val){
                flag = 1;
                ans = min(ans, root->val);
            }
            return;
        }
        //因为每个节点的子节点数量只能为 2 或 0 所以不用判断 root->right 是否为空
        if(root->left && root->left->val != root->val && root->right->val != root->val){//左右子节点的val 都不等于该节点的 val
            flag = 1;
            ans = min(ans, min(root->left->val, root->right->val));
            return;
        }
        if(root->left && root->left->val != root->val){//左子节点的val 不等于 该节点val 右边等于
            flag = 1;
            ans = min(ans, root->left->val);
            dfs(root->right, val, ans, flag);
            return;
        }
        if(root->left && root->right->val != root->val){//右子节点的val 不等于 该节点val 左边等于
            flag = 1;
            dfs(root->left, val, ans, flag);
            ans = min(ans, root->right->val);
            return;
        }
        if(root->left){//两边都等于
            dfs(root->left, val, ans, flag);
            dfs(root->right, val, ans, flag);
        }
        return;
    }
    
	/*
	   思路：
	   		ans 存放最后答案
			flag 记录是否找到答案
			遍历整棵树 当子树的val和该节点一样时 继续向下遍历
			如果不一样记录除了跟节点之外最小的
	 */
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return -1;
        if(!root->left && !root->right)return -1;
        int ans = 0x7fffffff;
        bool flag = 0;
        dfs(root, root->val, ans, flag);
        return flag ? ans : -1;
    }
};
