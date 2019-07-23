class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        l.clear();
        capacity = k;
        size = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size < capacity){
            l.push_back(value);
            ++size;
            return 1;
        }
        return 0;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size){
            l.pop_front();
            --size;
            return 1;
        }
        return 0;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return size ? l.front() : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return size ? l.back() : -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !size;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
    
private:
    list<int> l;
    int capacity;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
