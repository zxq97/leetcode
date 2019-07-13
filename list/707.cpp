// 这道题是真的 有毒 测试数据 真的有毒 
class MyLinkedList {
public:
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
    }*head,*tail;
    int size = 0;
    MyLinkedList() {
        head = NULL; 
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        int count = 0;
        ListNode* curr = head;
        while(count < index){
            curr = curr->next;
            ++count;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        if(head == NULL){
            tail = node;
        }
        node->next = head;
        head = node;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(index > size)
            return;
        if(index == size){
            addAtTail(val);
            return;
        }
        int count = 0;
        ListNode* curr = head;
        while(count < index-1){
            curr = curr->next;
            ++count;
        }
        ListNode* node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        if(!index){
            head = head->next;
            --size;
            return;
        }
        int count = 0;
        ListNode* curr = head;
        while(count < index-1){
            curr = curr->next;
            ++count;
        }
        curr->next = curr->next->next;
        if(!curr->next)
            tail = curr;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
