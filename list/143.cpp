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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return;
        stack<ListNode*> s;
        for(ListNode* h = head; h; h = h->next)
            s.push(h);
        while(1){
            ListNode* next = head->next;
            head->next = s.top();
            s.pop();
            head->next->next = next;
            head = next;
            if(head->next == s.top()){
                head->next->next = 0;
                break;
            }
            else if(head == s.top()){
                head->next = 0;
                break;
            }
        }
    }
};
