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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head || !k)return 0;
        ListNode* res = head, *h = head;
        for(int i = 0; i < k; ++i, h = h->next);
        while(h){
            h = h->next;
            res = res->next;
        }
        return res;
    }
};
