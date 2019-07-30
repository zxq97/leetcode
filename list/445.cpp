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
    ListNode* reverse(ListNode* t)
    {
        ListNode* h = 0;
        while(t){
            ListNode* next = t->next;
            t->next = h;
            h = t;
            t = next;
        }
        return h;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int t = 0;
        ListNode* p = new ListNode(-1);
        ListNode* res = p;
        while(l1 || l2){
            int val = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + t) % 10;
            t = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + t) / 10;
            p->next = new ListNode(val);
            p = p->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(t)
            p->next = new ListNode(1);
        return reverse(res->next);
    }
};
