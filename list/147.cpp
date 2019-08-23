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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        stack<ListNode*> s;
        for(ListNode* i = head; i; i = i->next){
            stack<ListNode*> st = s;
            int val = i->val;
            ListNode* cur = i;
            while(!st.empty() && st.top()->val > val){
                cur->val = st.top()->val;
                cur = st.top();
                st.pop();
            }
            if(st.empty())head->val = val;
            else st.top()->next->val = val;
            s.push(i);
        }
        return head;
    }
};
