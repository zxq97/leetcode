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
    vector<int> reversePrint(ListNode* head) {
        if(!head)return {};
        // stack<int> s;
        // while(head){
        //     s.push(head->val);
        //     head = head->next;
        // }
        // int n = s.size();
        // vector<int> v(n);
        // for(int i = 0; i < n; ++i){
        //     v[i] = s.top();
        //     s.pop();
        // }
        // return v;
        ListNode* h = head, *res = 0;
        while(head){
            h = head->next;
            head->next = res;
            res = head;
            head = h;
        }
        vector<int> v;
        for(ListNode* h = res; res; res = res->next)
            v.push_back(res->val);
        return v;
    }
};
