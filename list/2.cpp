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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        int t = 0;
        ListNode* p = l1;
        for(; l1 && l2; l1 = l1->next, l2 = l2->next){
            int tmp = (l1->val + l2->val + t) % 10;
            t = (l1->val + l2->val + t) / 10;
            l1->val = tmp;
        }
        while(l1){
            int tmp = (l1->val + t) % 10;
            t = (l1->val + t) / 10;
            l1->val = tmp;
            l1 = l1->next;
        }
        if(l2){
            ListNode* h = p;
            while(h->next)h = h->next;
            while(l2){
                int tmp = (l2->val + t) % 10;
                t = (l2->val + t) / 10;
                h->next = new ListNode(tmp);
                h = h->next;
                l2 = l2->next;
            }   
        }
        if(t){
            ListNode* h = p;
            while(h->next)h = h->next;
            h->next = new ListNode(t);
        }
        return p;
    }
};
