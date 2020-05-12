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
        if(!head || !head->next)return;
        ListNode* p = head;
        ListNode* l = head->next;
        while(l && l->next){
            p = p->next;
            l = l->next->next;
        }
        ListNode* mid = p->next;
        p->next = 0;
        ListNode* r = 0;
        while(mid){
            ListNode* t = mid->next;
            mid->next = r;
            r = mid;
            mid = t;
        }
        for(ListNode* p = head, *m = r; p && m;){
            ListNode* t = m->next;
            m->next = p->next;
            p->next = m;
            p = p->next->next;
            m = t;
        }
    }
};
