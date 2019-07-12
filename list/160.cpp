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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return 0;
        int lena = 0, lenb = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a->next){
            a = a->next;
            ++lena;
        }
        while(b->next){
            b = b->next;
            ++lenb;
        }
        if(a != b)return 0;
        a = headA;
        b = headB;
        if(lena > lenb){
            int len = lena - lenb;
            while(a && len--)
                a = a->next;
        }
        else if(lenb > lena){
            int len = lenb - lena;
            while(b && len--)
                b = b->next;
        }
        else{
            if(headA == headB)return headA;
        }
        if(a == b)return lena > lenb ? headB : headA;
        ListNode* p = 0;
        while(a && b && a != b){
            a = a->next;
            b = b->next;
            if(a == b){
                p = a;
                break;
            }
        }
        return p;
    }
};
