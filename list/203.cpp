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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        while(head && head->val == val)
            head = head->next;
        ListNode* p = head;
        while(p && p->next){
            while(p && p->next && p->next->val == val)
                p->next = p->next->next;
            p = p->next;
        }
        return head;
    }
};
