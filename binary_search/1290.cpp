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
    int getDecimalValue(ListNode* head) {
        if(!head)return 0;
        int ans = 0;
        for(ListNode* h = head; h; h = h->next){
            if(h->val)ans |= 1;
            if(h->next)ans <<= 1;
        }
        return ans;
    }
};
