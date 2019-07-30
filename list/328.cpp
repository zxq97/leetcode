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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return head;
        ListNode* p = head;
        ListNode* h = head->next;
        ListNode* t = h;
        ListNode* res = p;
        bool flag = 0;
        head = head->next->next;
        while(head){
            ListNode* next = head->next;
            head->next = 0;
            if(!flag){
                p->next = head;
                p = p->next;
            }
            else{
                h->next = head;
                h = h->next;
            }
            flag = !flag;
            head = next;
        }
        h->next = 0;
        p->next = t;
        p = res;
        return res;
    }
};
