/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& v) {
        unordered_set<int> s;
        for(int i : v)
            s.insert(i);
        int ans = 0;
        bool flag = 0;
        for(ListNode* h = head; h; h = h->next){
            if(s.find(h->val) != s.end()){
                if(!flag)++ans;
                flag = 1;
            }
            else
                flag = 0;
        }
        return ans;
    }
};
