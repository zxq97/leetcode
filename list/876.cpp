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
    ListNode* middleNode(ListNode* head) {
        if(!head)return head;
        ListNode* ans = 0;
        for(ListNode* first = head, *second = head; first;){
            if(first->next)first = first->next;
            else{
                ans = second;
                break;
            }
            if(first->next)first = first->next;
            else{
                ans = second->next;
                break;
            }
            if(second->next)second = second->next;
        }
        return ans;
    }
};
