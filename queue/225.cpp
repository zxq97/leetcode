class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        while(!first.empty())
            first.pop();
        while(!second.empty())
            second.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        first.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(first.size() > 1){
            second.push(first.front());
            first.pop();
        }
        int res = first.front();
        first.pop();
        while(!second.empty()){
            first.push(second.front());
            second.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = pop();
        first.push(res);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return first.empty() & second.empty();
    }
    
private:
    queue<int> first, second;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
