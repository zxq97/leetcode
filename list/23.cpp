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
    struct node{
        int val;
        ListNode* p;
        node(const int val, ListNode* p):val(val), p(p){}
        bool operator<(const node& other) const
        {
            return this->val > other.val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return 0;
        ListNode* res = 0;
        priority_queue<node> q;
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i])
                q.push(node(lists[i]->val, lists[i]));
        if(!q.empty()){
            res = new ListNode(q.top().p->val);
            node t = q.top();
            q.pop();
            if(t.p->next)q.push(node(t.p->next->val, t.p->next));
            ListNode* p = res;
            while(!q.empty()){
                t = q.top();
                q.pop();
                p->next = new ListNode(t.p->val);
                p = p->next;
                if(t.p->next)q.push(node(t.p->next->val, t.p->next));
            }
        }
        return res;
    }
};
