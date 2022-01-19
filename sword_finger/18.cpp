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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head)return head;
        if(head->val == val)return head->next;
        ListNode* h = head;
        while(h && h->next && h->next->val != val)
            h = h->next;
        h->next = h->next->next;
        return head;
    }
};
