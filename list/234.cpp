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
    bool isPalindrome(ListNode* head) {
        if(!head)return 1;
        stack<int> s;
        for(ListNode* h = head; h; h = h->next)
            s.push(h->val);
        for(ListNode* h = head; h; h = h->next, s.pop())
            if(s.top() != h->val)return 0;
        return 1;
    }
};
